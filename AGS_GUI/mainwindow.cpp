#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "optionsdialog.h"
#include "passworddialog.h"
#include "id_validator.h"
#include <cstdlib>

#include <QDateTime>
#include <QDebug>
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

    firstLogin = true;

    csWidget = new QWidget(this);
    csWidget->setWindowIcon(QIcon(":/images/cs_icon"));
    csWidget->setVisible(false);

    //PasswordDialog pd;
    //pd.exec();

    dialog = new OptionsDialog(this);
    pDialog = new PasswordDialog(this);
    connect(ui->actionChange_Username_Password,SIGNAL(triggered()),pDialog,SLOT(exec()));
    fDialog = new QFileDialog(this);
    iDialog = new QInputDialog(this);

    installChildrenEventFilter(this);
    ID_Validator *val = new ID_Validator;

    //ui->mainToolBar->hide();
    ui->statusBar->hide();
    ui->menuBar->hide();

    connect(ui->actionOptions,SIGNAL(triggered()),this,SLOT(showOptions()));

    updateTime();
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
    connect(ui->ags_id_line,SIGNAL(returnPressed()),val,SLOT(doneReading()));
    connect(ui->ags_id_line,SIGNAL(returnPressed()),this,SLOT(lookupAGS_ID()));
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
    connect(ui->actionExport_log_to,SIGNAL(triggered()),this,SLOT(exportFile()));
    connect(ui->actionLogout,SIGNAL(triggered()),this,SLOT(logout()));
    connect(ui->actionExit,SIGNAL(triggered()),this,SLOT(close()));
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
        ui->pcc_id_line->setReadOnly(false);
        ui->pcc_id_line->setText("");
        ui->ags_id_line->setReadOnly(false);
        ui->ags_id_line->setText("");
        ui->first_name_line->setText("");
        ui->last_name_line->setText("");

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
    else;//qDebug() << buffer;
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
        if(readTimer != 0)
            killTimer(readTimer);
        readTimer = startTimer(DISPLAY_MILS);
        ui->first_name_line->setText("John");//[!]
        ui->last_name_line->setText("Doe");//[!]

        loadFile(curFile);

        //log data [!]
}

void MainWindow::setEventType(QString s)
{
    ui->event_label->setText(s);
}

void MainWindow::setEventID(int i)
{

}

void MainWindow::setEventTypeID(QString s, int i)
{
    ui->event_label->setText(s.append(", ").append(QString::number(1)));
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
    //if condition should compare hash of Username and password to stored hash [!]
    if( validate(ui->username_line->text(),ui->password_line->text()) )
    {

        if(firstLogin)
        {
            /*
            QMessageBox msgBox;
            msgBox.setText("A log file for today already exists.");
            msgBox.setInformativeText("Would you like to open an existing log file?");
            msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
            msgBox.setDefaultButton(QMessageBox::Ok);
            int selection = msgBox.exec();

            QString fileName;
            if(selection == QMessageBox::Ok)//if file found && OK [!]
            {
                fileName = QFileDialog::getOpenFileName(this,"Log File", "","Log Files (*.dat)");
                QFile file(fileName);
                if(file.open(QFile::ReadOnly))
                {
                    int pos = fileName.lastIndexOf("/");
                    ui->file_name->setText(fileName.right(fileName.length() - pos - 1));
                    QTextStream stream(&file);
                    ui->textEdit->setText(stream.readAll());
                }

            }
            if(fileName.isEmpty()) //the user chose not to open a previous file, must choose
            {
                QInputDialog inputDialog(this);
                QStringList eventTypes;
                eventTypes << "AGS" << "CS" << "Meeting" << "Social" << "Other";

                QString input = inputDialog.getItem(this,"Event Type", "Please choose the event type:", eventTypes, 0, false);
                qDebug() << input;

                QString name;
                while(name.isEmpty())
                    name = inputDialog.getText(this, "Event Name", "Please name this event:");

                ui->file_name->setText(QDateTime::currentDateTime().toString(ui->file_name->text()));
                ui->file_name->setText(ui->file_name->text().append(" ").append(name).append(".dat"));


            }*/
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
    QStringList eventTypes;
    eventTypes << "AGS" << "CS" << "Meeting" << "Social" << "Other";

    QString input;
    bool accepted = false;
    input = iDialog->getItem(this,"Event Type", "Please choose the event type:", eventTypes, 0, false,&accepted);
    if(!accepted) return;

    int id = -1;
    id = iDialog->getInt(this,"Event ID","Please choose the event ID",0,0,2147483647,1,&accepted);
    if(!accepted) return;

    setEventTypeID(input,1);

    QString name;
    accepted = true;
    while(accepted && name.isEmpty())
        name = iDialog->getText(this, "Event Name", "Please name this event:",QLineEdit::Normal,"",&accepted);
    if(!accepted) return;

    eName = name;
    QFile file(genFileName());
    if(file.open(QFile::WriteOnly))
    {
        //qDebug() << true;
        QTextStream out(&file);
        out << ui->event_label->text().remove(",");
        loadFile(file.fileName());
    }
    else
        ;//qDebug() << false;
}

void MainWindow::openFile()
{
    fDialog->setWindowTitle("Open");
    fDialog->setFileMode(QFileDialog::ExistingFile);
    fDialog->setNameFilter("Log Files (*.dat)");
    fDialog->setOption(QFileDialog::DontUseNativeDialog,false);
    fDialog->setViewMode(QFileDialog::List);
    fDialog->setAcceptMode(QFileDialog::AcceptOpen);
    //QFileDialog::getOpenFileName(this);
    if(fDialog->exec())
    {
        QString name = fDialog->selectedFiles().at(0);
        loadFile(name);
        updateEventFromFile(name);
    }
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
        stream.readLine(); //discard Event & ID
        ui->textEdit->setText(stream.readAll());

        showMain();
        setCurrentFile(s);
    }

}

void MainWindow::exportFile()
{
    qDebug("Exporting...");
    fDialog->setWindowTitle("Export");
    fDialog->setFileMode(QFileDialog::AnyFile);
    fDialog->setNameFilter("Comma Delimited Format(*.csv)");
    fDialog->setViewMode(QFileDialog::List);
    fDialog->setAcceptMode(QFileDialog::AcceptSave);
    //QFileDialog::getOpenFileName(this);
    if(fDialog->exec())
    {
        QString name = fDialog->selectedFiles().at(0);
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
    QFile file(fileName);
    if(file.open(QFile::ReadOnly))
    {
        QTextStream in(&file);
        QString line = file.readLine();
        int pos = line.lastIndexOf(" ");
        //qDebug() << pos << " " << line.length();
        setEventTypeID(line.left(pos), line.right(line.length() - pos).toInt());
    }
}

QString MainWindow::genFileName()
{
    QString name = QDir::currentPath().append("/logs/").append(QDateTime::currentDateTime().toString("yyyy-MM-dd "));
    name.append(eName).append(".dat");
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

        QMessageBox::about(this,"Report a Problem",s);
}
