#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "optionsdialog.h"
#include "id_validator.h"
#include <cstdlib>

#include <QDateTime>
#include <QDebug>
#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ID_Validator *val = new ID_Validator;

    ui->setupUi(this);
    //ui->mainToolBar->hide();
    ui->statusBar->hide();

    connect(ui->actionOptions,SIGNAL(triggered()),this,SLOT(showOptions()));

    updateTime();
    readTimer = 0;
    stampTimer = startTimer(200);
    ot = startTimer(5000);

    ui->pcc_id_line->installEventFilter(this);
    ui->pcc_id_line->setValidator(val);
    ui->ags_id_line->setValidator(val);
    connect(ui->pcc_id_line,SIGNAL(returnPressed()),val,SLOT(doneReading()));
    connect(ui->pcc_id_line,SIGNAL(returnPressed()),this,SLOT(lookupPCC_ID()));
    connect(ui->ags_id_line,SIGNAL(returnPressed()),this,SLOT(lookupAGS_ID()));
    connect(val,SIGNAL(doneProcessing(QString)),this,SLOT(lookupPCC_ID(QString)));

    //ui->ags_id_line->setValidator(new ID_Validator);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showOptions()
{
    OptionsDialog d(this);
    d.setModal(true);
    d.exec();
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
    else
        ;//qDebug() << buffer;
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{

}

bool MainWindow::eventFilter(QObject *o, QEvent *e)
{
    static int i = 0;
    if(o == ui->pcc_id_line)
    {
        if(e->type() == QEvent::KeyPress)
        {
            QKeyEvent *k = (QKeyEvent*)(e);
            if(k)
                buffer.append(char(k->key()));
        }
    }
    return false;
}

void MainWindow::lookupAGS_ID()
{
    if(ui->pcc_id_line->isReadOnly() || ui->ags_id_line->text().length() < 4)
         return;

     qDebug(ui->ags_id_line->text().toStdString().c_str());
     //if([successful lookup])
        ui->pcc_id_line->setText(QString::number(0.00800290,'f',8).right(8));
         ui->pcc_id_line->setReadOnly(true);
         ui->ags_id_line->setText(ui->ags_id_line->text());
         ui->ags_id_line->setReadOnly(true);
         readTimer = startTimer(DISPLAY_MILS);
         ui->first_name_line->setText("Arjun");
         ui->last_name_line->setText("Prakash");
}

void MainWindow::lookupPCC_ID()
{
    lookupPCC_ID(ui->pcc_id_line->text());
}

void MainWindow::lookupPCC_ID(QString s)
{
    if(ui->pcc_id_line->isReadOnly() || s.length() < 8)
        return;

    system("Beep");
    qDebug(s.toStdString().c_str());
    //if([successful lookup])
        ui->pcc_id_line->setText(s);
        ui->pcc_id_line->setReadOnly(true);
        ui->ags_id_line->setText(QString::number(1415));
        ui->ags_id_line->setReadOnly(true);
        readTimer = startTimer(DISPLAY_MILS);
        ui->first_name_line->setText("John");
        ui->last_name_line->setText("Castillo");
        //log info
}

void MainWindow::setEventType(QString s)
{

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
