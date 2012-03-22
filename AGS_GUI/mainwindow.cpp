#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "optionsdialog.h"
#include "passworddialog.h"
#include "id_validator.h"
#include <cstdlib>

#include <QDateTime>
#include <QDebug>
#include <QDialogButtonBox>
#include <QKeyEvent>
#include <QFileDialog>
#include <QMessageBox>
#include <QInputDialog>
#include <QSettings>
#include <QDesktopServices>
#include <QUrl>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /*/ status bar stuff /*/
    label = new QLabel;
    ui->statusBar->addWidget(label);
    /*/ end status stuff /*/

    firstLogin = true;
    criticalValues[MULTIPLIER_ON] = "0";

    csWidget = new QWidget(this);
    csWidget->setWindowIcon(QIcon(":/images/cs_icon"));
    csWidget->setVisible(false);
    //ui->menuChange_Event->setVisible(false);
    ui->actionClose_File->setVisible(false);

    agsEventTypes << "" << "AGS" << "CS" << "Meeting" << "Social" << "Other";

    //PasswordDialog pd;
    //pd.exec();

    dialog = new OptionsDialog(this);
    connect(ui->actionOptions,SIGNAL(triggered()),this,SLOT(showOptions()));
    connect(this,SIGNAL(eventChanged(AGSEventType,int)),dialog,SLOT(setEvent(AGSEventType,int)));
    connect(dialog,SIGNAL(eventChanged(AGSEventType,int)),this,SLOT(setEvent(AGSEventType,int)));

    pDialog = new PasswordDialog(this);
    connect(ui->actionChange_Username_Password,SIGNAL(triggered()),pDialog,SLOT(exec()));
    //fDialog = new QFileDialog(this);
    iDialog = new QInputDialog(this);

    IDLE_TIME = 60000;
    CONNECTION_REFRESH = 10000; //[!]

    installChildrenEventFilter(this);
    ID_Validator *val = new ID_Validator;

    //ui->mainToolBar->hide();
    //ui->statusBar->hide();
    ui->menuBar->hide();

    updateTime();
    connectionTimer = 0;
    readTimer = 0;
    messageTimer = 0;
    loginTimer = 0;
    lmTimer = 0;
    stampTimer = startTimer(200);
    ot = startTimer(5000);

    ui->pcc_id_line->installEventFilter(this);
    ui->pcc_id_line->setValidator(val);
    ui->ags_id_line->setValidator(val);

    /*/Connections for reading a PCC ID/*/
    connect(ui->pcc_id_line,SIGNAL(returnPressed()),val,SLOT(doneReading()));
    connect(ui->pcc_id_line,SIGNAL(returnPressed()),this,SLOT(lookupPCC_ID()));
    //connect(ui->ags_id_line,SIGNAL(returnPressed()),val,SLOT(doneReading()));
    //connect(ui->ags_id_line,SIGNAL(returnPressed()),this,SLOT(lookupAGS_ID()));
    connect(val,SIGNAL(doneProcessing(QString)),this,SLOT(lookupPCC_ID(QString)));
    /*/ END PCC ID /*/

    /*/ Connections for login page /*/
    connect(ui->login_button,SIGNAL(clicked()),this,SLOT(login()));
    connect(ui->username_line,SIGNAL(returnPressed()),this,SLOT(login()));
    connect(ui->password_line,SIGNAL(returnPressed()),this,SLOT(login()));
    /*/ End login page /*/

    /*/ Connections for menubar /*/
    connect(ui->actionNew,SIGNAL(triggered()),this,SLOT(newFile()));
    connect(ui->actionOpen,SIGNAL(triggered()),this,SLOT(openFile()));
    connect(ui->actionClose_File,SIGNAL(triggered()),this,SLOT(closeFile()));
    connect(ui->actionExport_log_to,SIGNAL(triggered()),this,SLOT(exportFile()));
    connect(ui->actionImport_to_Database,SIGNAL(triggered()),this,SLOT(importToDatabase()));
    connect(ui->actionLogout,SIGNAL(triggered()),this,SLOT(logout()));
    connect(ui->actionExit,SIGNAL(triggered()),this,SLOT(close()));

    connect(ui->actionSet_Logout_Timer,SIGNAL(triggered()),this,SLOT(setLogoutTime()));

    connect(ui->actionAbout,SIGNAL(triggered()),this,SLOT(about()));
    connect(ui->actionView_Tutorial,SIGNAL(triggered()),this,SLOT(tutorial()));
    connect(ui->actionReport_a_problem,SIGNAL(triggered()),this,SLOT(reportABug()));
    /*/ END menubar /*/

    /*/ Recent Files /*/
    ui->menuFile->insertSeparator(ui->actionLogout);
    for (int i = 0; i < MaxRecentFiles; ++i) {
        recentFileActs[i] = new QAction(this);
        recentFileActs[i]->setVisible(false);
        connect(recentFileActs[i], SIGNAL(triggered()),
                this, SLOT(openRecentFile()));
        ui->menuFile->insertAction(ui->actionLogout,recentFileActs[i]);
    }
    separatorAct = ui->menuFile->insertSeparator(ui->actionLogout);

    //ui->actionLogout->setVisible(false);
    /*/ END Recent Files /*/
    //connect(&[LoggerClass],SIGNAL(append(QString)),ui->textEdit,SLOT(append(QString))); [!]

    updateRecentFileActions();

    setWindowState(Qt::WindowFullScreen);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showOptions()
{
    dialog->exec();
}

void MainWindow::updateFileName(const QString &name)
{
    ui->first_name_line->setText(name);
}

void MainWindow::updateTime()
{
    static QString timeFormat = ui->time_stamp_line->text();
    ui->time_stamp_line->setText(QDateTime::currentDateTime().toString(timeFormat));
}

void MainWindow::timerEvent(QTimerEvent *e)
{
    if(e->timerId() == stampTimer)
    {
        updateTime();
    }
    else if(e->timerId() == readTimer)
    {
        resetFields();

        if(readTimer)
            killTimer(readTimer);
        readTimer = 0;
    }
    else if(e->timerId() == lmTimer)
    {
        ui->login_message->setText("");

        killTimer(lmTimer);
        lmTimer = 0;
    }
    else if(e->timerId() == loginTimer)
    {
        logout();
    }
    else if(e->timerId() == connectionTimer)
    {
        testConnection();
    }
    else;//qDebug() << buffer;
}

void MainWindow::resetFields()
{
    ui->pcc_id_line->setReadOnly(false);
    ui->pcc_id_line->setText("");
    //ui->ags_id_line->setReadOnly(false);
    ui->ags_id_line->setText("");
    ui->first_name_line->setText("");
    ui->last_name_line->setText("");
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{

}

bool MainWindow::eventFilter(QObject *o, QEvent *e)
{
    //static int i = 0;
    if(o == ui->pcc_id_line)
    {
        if(e->type() == QEvent::KeyPress)
        {
            QKeyEvent *k = (QKeyEvent*)(e);
            if(k)
                buffer.append(char(k->key()));
        }
    }
    if(e->type() == QEvent::KeyPress || e->type() == QEvent::MouseButtonPress)
    {
        //qDebug() << i++;
        if(loginTimer != 0)
        {
            killTimer(loginTimer);
            loginTimer = startTimer(IDLE_TIME);
        }
    }

    return false;
}

void MainWindow::lookupAGS_ID()
{
    if(ui->pcc_id_line->isReadOnly() || ui->ags_id_line->text().length() < 4)
         return;

     qDebug(ui->ags_id_line->text().toStdString().c_str());
     //if([successful lookup])[!]
        ui->pcc_id_line->setText(QString::number(0.00800290,'f',8).right(8));//[!]
         ui->pcc_id_line->setReadOnly(true);
         //ui->ags_id_line->setText(ui->ags_id_line->text());
         ui->ags_id_line->setReadOnly(true);
         if(readTimer != 0)
             killTimer(readTimer);
         readTimer = startTimer(DISPLAY_MILS);
         ui->first_name_line->setText("Daniel");//[!}
         ui->last_name_line->setText("Pasillas");//[!]

         loadFile(curFile);

         //log data [!]
}

void MainWindow::lookupPCC_ID()
{
    lookupPCC_ID(ui->pcc_id_line->text());
}

void MainWindow::lookupPCC_ID(QString s)
{
    if(ui->pcc_id_line->isReadOnly() || s.length() < 8)
        return;

    //ui->textEdit->append(s); // each append is considered its own paragraph
    //qDebug(s.toStdString().c_str());
    //if([successful lookup])[!]
        ui->pcc_id_line->setText(s);
        ui->pcc_id_line->setReadOnly(true);
        ui->ags_id_line->setText(QString::number(8910));//[1}
        ui->ags_id_line->setReadOnly(true);

        if(criticalValues[MULTIPLIER_ON].toInt() && true)//if(calc && login)[!]
        {
            killTimer(loginTimer);//Prevents logout before confirmation

            bool tshirt =
            QMessageBox::question(this,"AGS T-Shirt","Are you wearing an AGS T-Shirt?",QMessageBox::Yes | QMessageBox::No)
                    == QMessageBox::Yes;
            //do something with tshirt[!]

            loginTimer = startTimer(IDLE_TIME); //Prevents logout
        }

        if(readTimer != 0)
            killTimer(readTimer);
        readTimer = startTimer(DISPLAY_MILS);

        ui->first_name_line->setText("John");//[!]
        ui->last_name_line->setText("Doe");//[!]

        loadFile(curFile);

        //log data [!]
}

void MainWindow::setEventTypeID(QString s, int i)
{
    criticalValues[EVENT_TYPE] = s;//QString::number((AGSEventType)agsEventTypes.indexOf(s));
    criticalValues[EVENT_ID] = QString::number(i);
    ui->event_label->setText(s.append(", ").append(QString::number(i)));
}

void MainWindow::setEvent(AGSEventType type, int i)
{
    setEventTypeID(agsEventTypes[type],i);
}

void MainWindow::boo()
{
    qDebug("BOO!");
}

void MainWindow::showError(QString s)
{

}

void MainWindow::login()
{

    testConnection();
    setTimer(connectionTimer,CONNECTION_REFRESH);
    //if condition should compare hash of Username and password to stored hash [!]
    if( validate(ui->username_line->text(),ui->password_line->text()) )
    {

        if(firstLogin)
        {
            ui->stackedWidget->setCurrentIndex(2);
            ui->menuBar->show();

            if(loginTimer != 0)
                killTimer(loginTimer);
            loginTimer = startTimer(IDLE_TIME);
            ui->menuBar->show();
        }
        else
        {
            showMain();
        }


    }
    else //bad login information
    {
        if(ui->username_line->text() == "")
            ui->login_message->setText("Please enter a username");
        else if(ui->password_line->text() == "")
            ui->login_message->setText("Please enter a password");
        else
            ui->login_message->setText("Bad username and/or password!");

        if(lmTimer != 0)
            killTimer(lmTimer);
        lmTimer = startTimer(DISPLAY_MILS);
    }
}

void MainWindow::logout()
{
    ui->username_line->setText("");
    ui->password_line->setText("");
    ui->login_message->setText("Logged out!");
    hideChildren(ui->menuBar);

    foreach(QObject *o, children())
    {
        if(QDialog *d = qobject_cast<QDialog*>(o))
        {
            d->reject();
        }
    }

    //the about dialog is now a child of csWidget
    //so it must be rejected here
    foreach(QObject *o, csWidget->children())
    {
        if(QDialog *d = qobject_cast<QDialog*>(o))
        {
            d->reject();
        }
    }

    if(dialog->isVisible())
        dialog->close();

    ui->stackedWidget->setCurrentIndex(0);

    if(lmTimer != 0)
        killTimer(lmTimer);
    lmTimer = startTimer(DISPLAY_MILS);

    killTimer(loginTimer);
    loginTimer = 0;

    killTimer(connectionTimer);
    connectionTimer = 0;
    label->setText("");
}

void MainWindow::installChildrenEventFilter(QObject *o)
{
    o->installEventFilter(this);
    foreach(QObject* o2, o->children())
        installChildrenEventFilter(o2);
}

void MainWindow::hideChildren(QWidget *w)
{
    w->hide();
    foreach(QObject* o, w->children())
    {
        if(QWidget* w2 = qobject_cast<QWidget*>(o))
            w2->hide();
    }
}

void MainWindow::newFile()
{   
    QStringList eventTypes = agsEventTypes;

    //The next three [!] mark where values are stored;
    QString input;//[!]
    bool accepted = true;
    while(accepted && input.isEmpty())
        input = iDialog->getItem(this,"Event Type", "Please choose the event type:", eventTypes, 0, false,&accepted);
    if(!accepted) return;

    int id = -1;//[!]
    id = iDialog->getInt(this,"Event ID","Please choose the event ID",0,0,2147483647,1,&accepted);
    if(!accepted) return;

    setEventTypeID(input,id);

    QString name;//[!]
    accepted = true;
    while(accepted && name.isEmpty())
        name = iDialog->getText(this, "Event Name", "Please name this event:",QLineEdit::Normal,"",&accepted);
    if(!accepted) return;

    QString adminID;
    accepted = true;
    while(accepted && adminID.isEmpty())
        adminID = getID("Who will administrate this event? (PCC Student ID)", accepted);

    //criticalValues[SHIFT_ID] =;

    dialog->setEvent((AGSEventType)agsEventTypes.indexOf(input),id);

    criticalValues[EVENT_NAME] = name;
    QFile file(genFileName());
    bool shouldLoad = false;
    if(file.open(QFile::WriteOnly))
    {
        shouldLoad = true;
        criticalValues[EVENT_TYPE] = input;
        criticalValues[EVENT_ID] = QString::number(id);
        criticalValues[DATE] = QDateTime::currentDateTime().toString("yyyy-MM-dd");
        criticalValues[EVENT_NAME] = name;
        criticalValues[SHIFT_ID] = "0"; // lookup value [!]
        criticalValues[SEMESTER_ID] = "0"; // [!]
        criticalValues[SUBMITTED_BY_ID] = adminID;
        criticalValues[MULTIPLIER_ON] = "0";
        criticalValues[MULTIPLIER] = QString::number(1.00,'f',2);
        criticalValues[EXPORTED] = "0";

        QTextStream out(&file);
        out << generateHeader();
        file.close();//loadFile(file.fileName());
    }

    if(shouldLoad)
    {
        loadFile(file.fileName());
    }
}

void MainWindow::openFile()
{
    QFileDialog d(this), *fDialog = &d;
    fDialog->setWindowTitle("Open");
    fDialog->setFileMode(QFileDialog::ExistingFile);
    fDialog->setNameFilter("Log Files (*.dat)");
    fDialog->setOption(QFileDialog::DontUseNativeDialog,false);
    fDialog->setViewMode(QFileDialog::List);
    fDialog->setAcceptMode(QFileDialog::AcceptOpen);
    //QByteArray array = fDialog->saveState();
    //QFileDialog::getOpenFileName(this);
    if(fDialog->exec())
    {
        QString name = fDialog->selectedFiles().at(0);
        loadFile(name);
        updateEventFromFile(name);
    }
    //fDialog->restoreState(array);
}

void MainWindow::closeFile()
{
    firstLogin = true;
    ui->stackedWidget->setCurrentIndex(2);
    ui->actionClose_File->setVisible(false);
}

void MainWindow::openRecentFile()
{
    QAction *action = qobject_cast<QAction*>(sender());
    if(action)
    {
        loadFile(action->data().toString());
        updateEventFromFile(action->data().toString());
    }
}

void MainWindow::loadFile(QString s)
{
    firstLogin = false;
    QFile file(s);
    if(file.open(QFile::ReadOnly))
    {
        int pos = s.lastIndexOf("/");
        ui->file_name->setText(s.right(s.length() - pos - 1));
        QTextStream stream(&file);
        updateValues(stream.readLine()); //load appropriate values
        ui->textEdit->setText(stream.readAll());

        showMain();
        setCurrentFile(s);
        updateOptions();
        ui->actionClose_File->setVisible(true);
    }

}

void MainWindow::exportFile()
{
    QFileDialog d(this), *fDialog = &d;
    qDebug("Exporting...");
    fDialog->setWindowTitle("Export");
    fDialog->setFileMode(QFileDialog::AnyFile);
    fDialog->setNameFilter("Comma Delimited Format(*.csv)");
    fDialog->setViewMode(QFileDialog::List);
    fDialog->setAcceptMode(QFileDialog::AcceptSave);
    fDialog->selectFile("");

    //QFileDialog::getOpenFileName(this);
    if(fDialog->exec())
    {
        QString name = fDialog->selectedFiles().at(0);
        int pos = name.lastIndexOf(".");
        if(pos == -1)
            name.append(".csv");
        else
            name.replace(pos,name.length() - pos,".csv");
        qDebug() << name;
        //[!]
    }

}

void MainWindow::showMain()
{
    ui->actionLogout->setVisible(true);
    ui->stackedWidget->setCurrentIndex(1);
    if(loginTimer != 0)
        killTimer(loginTimer);
    loginTimer = startTimer(IDLE_TIME);
    ui->menuBar->show();
}

void MainWindow::updateEventFromFile(QString fileName)
{
    /*QFile file(fileName);
    if(file.open(QFile::ReadOnly))
    {
        QTextStream in(&file);
        QString line = file.readLine();
        int pos = line.indexOf(" ");
        int pos2 = line.indexOf(" ", pos+1);
        //qDebug() << pos << " " << line.length();
        setEventTypeID(line.left(pos), line.mid(pos+1,pos2 - pos - 1).toInt());
                       //line.right(line.length() - pos).toInt());
    }*/
    QString text = criticalValues[EVENT_TYPE];

    ui->event_label->setText(text.append(" ").append(criticalValues[EVENT_ID]));
}

QString MainWindow::genFileName()
{
    QString name = QDir::currentPath().append("/logs/").append(QDateTime::currentDateTime().toString("yyyy-MM-dd "));
    name.append(criticalValues[EVENT_NAME]).append(".dat");
    return name;
}

void MainWindow::setCurrentFile(const QString &fileName)
{
    curFile = fileName;
    setWindowFilePath(curFile);

    files = todaysFiles();

    files.removeAll(fileName);
    files.prepend(fileName);
    while (files.size() > MaxRecentFiles)
        files.removeLast();

    updateRecentFileActions();
}

void MainWindow::updateRecentFileActions()
{
    files = todaysFiles();

    int numRecentFiles = qMin(files.size(), (int)MaxRecentFiles);

    for (int i = 0; i < numRecentFiles; ++i) {
        QString text = tr("&%1 %2").arg(i + 1).arg(strippedName(files[i]));
        recentFileActs[i]->setText(text);
        recentFileActs[i]->setData(files[i]);
        recentFileActs[i]->setVisible(true);
    }
    for (int j = numRecentFiles; j < MaxRecentFiles; ++j)
        recentFileActs[j]->setVisible(false);

    separatorAct->setVisible(numRecentFiles > 0);
}

QStringList MainWindow::todaysFiles()
{
    QDir logs(QDir::currentPath().append("/logs/"));

    QStringList files = logs.entryList(QDir::Files);
    QStringList fullFiles;
    foreach(QString s, files)
    {
        QString shortName = strippedName(s);
        QString today = QDateTime::currentDateTime().toString("yyyy-MM-dd ");

        if(shortName.indexOf(today) == 0)
            fullFiles.append(logs.absoluteFilePath(shortName));
    }

    return fullFiles;
}

QString MainWindow::strippedName(const QString &fullFileName)
{
    return QFileInfo(fullFileName).fileName();
}

bool MainWindow::validate(QString username, QString password)
{
    //[!]
    return username == "Username" && password == "Password";
}

void MainWindow::updateUsername(QString username)
{
    //[!]
}

void MainWindow::updatePassword(QString password)
{
    //[!]
}

void MainWindow::about()
{
    QMessageBox::about(csWidget,"About", "This is a line of text"); //[!]
}

void MainWindow::tutorial()
{
    QDesktopServices::openUrl(QUrl("http://www.google.com"));
}

void MainWindow::reportABug()
{
    //[!] Just change the string, and use <br> for line breaks
    static QString s("To report a problem,<br>"
                     "please visit this link: <a href = \"http://www.google.com\">http://www.google.com</a>"
                     "<hr>"
                     "You may also visit our website here: <a href = \"http://www.google.com\">http://www.google.com</a>");

        QMessageBox::about(csWidget,"Report a Problem",s);
}


void MainWindow::setLogoutTime()
{
    bool ok = false;
    int secs = iDialog->getInteger(this,"Logout Delay","Idle Seconds until logout:",IDLE_TIME / 1000,0,2147438647,1,&ok);
    if(ok)
        setLogoutTime(secs);
}

void MainWindow::setLogoutTime(int seconds)
{
    if(loginTimer)
        killTimer(loginTimer);
    if(seconds)
        loginTimer = startTimer(seconds * 1000);
    IDLE_TIME = seconds * 1000;
}

void MainWindow::setTShirtCalc(double multiplier, bool on)
{
    criticalValues[MULTIPLIER] = QString::number(multiplier,'f',2);
    criticalValues[MULTIPLIER_ON] = on?"1":"0";
    qDebug() << multiplier << on;
    //[!]
}

void MainWindow::testConnection()
{
    bool connected = false; //[!]
    label->setText(QString("Connection Status: ").append((connected)?"<b>ONLINE</b>":"<b>OFFLINE</b>"));
    qDebug() << "Connection Tested";
}

void MainWindow::setTimer(int& id, int& var, int msecs)
{
    if(id)
        killTimer(id);
    if(msecs)
        var = msecs;
    id = startTimer(var);
}

void MainWindow::rewriteHeader()
{
    if(curFile.isEmpty())
        return;
    QFile file(curFile);
    QString oldHeader;
    QString buffer;
    if(file.open(QFile::ReadOnly | QFile::Text))
    {
        QTextStream in(&file);
        oldHeader = in.readLine();
        buffer =in.readAll();
    }
    else return;
    file.close();

    QString newHeader = generateHeader();
    /*int pos = ui->file_name->text().indexOf(" ");
    int length = ui->file_name->text().length();

    for(int i = 0; i < HEADER_SIZE; i++)
        newHeader += criticalValues[i] + "+";
    newHeader = newHeader.left(newHeader.length() - 1);

    newHeader += criticalValues[EVENT_TYPE] + "+";
    newHeader += criticalValues[EVENT_ID] + "+";
    newHeader += ui->file_name->text().left(pos) + "+";
    newHeader += ui->file_name->text().mid(pos + 1, length - pos - 5) + "+";
    newHeader += QString() + "+";//shift_id
    newHeader += QString() + "+";//semester_id
    newHeader += QString() + "+";//submitted_by_id
    newHeader += QString(criticalValues[MULTIPLIER_ON].toInt()?"1":"0") + "+";//tshirt_state
    newHeader += criticalValues[MULTIPLIER] + "+";//multiplier
    newHeader += oldHeader.right(1);//exported_bit
    newHeader += " \n";*/

    if(file.open(QFile::WriteOnly | QFile::Text))
    {
        QTextStream out(&file);
        out << newHeader;
        out << buffer;
        qDebug() << newHeader;
    }
}

QString MainWindow::generateHeader()
{
    QString newHeader;
    for(int i = 0; i < HEADER_SIZE; i++)
        newHeader += criticalValues[i] + "+";

    newHeader[newHeader.size() - 1] = '\n';

    return newHeader;
}

void MainWindow::updateValues(QString values)
{
    if(values.isEmpty())
        return;
    int index = 0;
    QList<int> pos;
    pos.append(-1);
    while(index != -1)
    {
        pos.append(values.indexOf("+",index+1));
        index = pos.last();
    }
    pos.last() = values.length();

    if(pos.count() == 11)
    {
        for(int i = 0; i < 10; i++)
            criticalValues[i] = values.mid(pos[i]+1,pos[i+1]-pos[i]-1);
        /*
        eType = (AGSEventType)agsEventTypes.indexOf(values.left(pos[0])); //Event Type
        eID = vmid(1);//Event ID 0 1
        vmid(2);//Date Stamp 1 2
        eName = vmid(3);//values.mid(pos[2]+1,pos[3]-pos[2]-1);//Event Name 2 3
        vmid(4).toInt();//Shift 3 4
        vmid(5).toInt();//Semester 4 5
        vmid(6).toInt();//Submitted 5 6
        tShirtCalc = vmid(7).toInt();//Tshirt state 6 7
        mult = vmid(8).toDouble();//multiplier 7 8
        vmid(9).toInt();//exported bit 8 last*/
    }
    else
    {
        int pos = values.indexOf(" ");
        criticalValues[EVENT_TYPE] = values.left(pos);
        criticalValues[EVENT_ID] = values.right(values.length() - pos - 1);
    }
}

QString MainWindow::getID(QString labelText, bool &ok)
{
    static QDialog dialog;
    static QVBoxLayout *v = 0;

    static QLineEdit *line = new QLineEdit;
    static QLabel *label = new QLabel;
    static ID_Validator *val = new ID_Validator;
    if(!v)
    {
        v = new QVBoxLayout;

        line->setValidator(val);
        connect(line,SIGNAL(returnPressed()),val,SLOT(doneReading()));
        connect(val,SIGNAL(doneProcessing(QString)),line,SLOT(setText(QString)));

        QDialogButtonBox *box = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);

        connect(box,SIGNAL(accepted()),&dialog,SLOT(accept()));
        connect(box,SIGNAL(rejected()),&dialog,SLOT(reject()));

        v->addSpacing(0);
        v->addWidget(label);
        v->addWidget(line);
        v->addSpacing(0);
        v->addWidget(box);

        dialog.setLayout(v);
    }
    label->setText(labelText);

    line->setText("");
    ok = dialog.exec() == QDialog::Accepted;

    if(line->text().length() == 8)
    {
        return line->text();
    }

    return "";
}

void MainWindow::setValue(HeaderValues type, QString value)
{
    criticalValues[type] = value;

    rewriteHeader();
}

void MainWindow::updateOptions()
{
    //HOST, USER, PASS, DATABASE, PORT, , , , HRS_PER_PERSON, , , ,
    //, , DATE, EVENT_NAME, , , , , , EXPORTED, HEADER_SIZE
    dialog->setValue(OptionsDialog::EVENT_TYPE,QString::number(agsEventTypes.indexOf(criticalValues[EVENT_TYPE])));
    dialog->setValue(OptionsDialog::EVENT_ID,criticalValues[EVENT_ID]);
    dialog->setValue(OptionsDialog::SEMESTER,criticalValues[SEMESTER_ID]);
    dialog->setValue(OptionsDialog::SHIFT,criticalValues[SHIFT_ID]);
    dialog->setValue(OptionsDialog::SUBMITTED_BY,criticalValues[SUBMITTED_BY_ID]);
    dialog->setValue(OptionsDialog::TSHIRT_MULT,criticalValues[MULTIPLIER]);
    dialog->setValue(OptionsDialog::TSHIRT_CALC,criticalValues[MULTIPLIER_ON]);
}

void MainWindow::importToDatabase()
{
    QFileDialog d(this), *fDialog = &d;
    fDialog->setWindowTitle("Choose a file to be exported");
    fDialog->setFileMode(QFileDialog::ExistingFile);
    fDialog->setNameFilter("Log Files (*.dat)");
    //fDialog->setOption(QFileDialog::DontUseNativeDialog,false);
    fDialog->setViewMode(QFileDialog::List);
    fDialog->setAcceptMode(QFileDialog::AcceptOpen);
    if(fDialog->exec())
    {
        QString fileName = fDialog->selectedFiles().at(0);
        if(fileName == curFile && QMessageBox::Ok ==
                QMessageBox::warning(this,"Open File Warning",
                                     "In order to continue, you must close this session.\n"
                                     "Proceed?",
                                     QMessageBox::Ok | QMessageBox::Cancel))
        {
            closeFile();
        }

        //do what you need with the file here[!]
    }
}
