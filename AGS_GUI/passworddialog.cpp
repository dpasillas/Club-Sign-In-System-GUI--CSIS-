#include "passworddialog.h"
#include "ui_passworddialog.h"

#include "mainwindow.h"
#include "methodrunner.h"

#include <QDebug>
#include <QMessageBox>

PasswordDialog::PasswordDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PasswordDialog)
{
    ui->setupUi(this);
    adjustSize();

    connect(ui->username_line,SIGNAL(returnPressed()),ui->validate_button,SIGNAL(clicked()));
    connect(ui->password_line,SIGNAL(returnPressed()),ui->validate_button,SIGNAL(clicked()));
    connect(ui->validate_button,SIGNAL(clicked()),this,SLOT(validate()));

    connect(ui->nu_line,SIGNAL(returnPressed()),ui->ok_button,SIGNAL(clicked()));
    connect(ui->np_line,SIGNAL(returnPressed()),ui->ok_button,SIGNAL(clicked()));
    connect(ui->verify_np_line,SIGNAL(returnPressed()),ui->ok_button,SIGNAL(clicked()));
    init();

}

PasswordDialog::~PasswordDialog()
{
    delete ui;
}

void PasswordDialog::accept()
{
    qDebug() << sender();
    MethodRunner<PasswordDialog, void> runner(this,&PasswordDialog::aInit);

    if(mwp()->validate(ui->username_line->text(),ui->password_line->text()))
    {

    }
}

void PasswordDialog::reject()
{
    qDebug() << sender();
    MethodRunner<PasswordDialog, void> runner(this,&PasswordDialog::rInit);
}

MainWindow* PasswordDialog::mwp()
{
    return (MainWindow*)parent();
}

void PasswordDialog::init()
{
    const bool b = true;
    ui->username_label->setDisabled(!b);
    ui->username_line->setDisabled(!b);
    ui->username_line->setText("");

    ui->password_label->setDisabled(!b);
    ui->password_line->setDisabled(!b);
    ui->password_line->setText("");

    //ui->validate_button->setDisabled(!b);


    ui->nu_label->setDisabled(b);
    ui->nu_line->setDisabled(b);
    ui->nu_line->setText("");

    ui->np_label->setDisabled(b);
    ui->np_line->setDisabled(b);
    ui->np_line->setText("");

    ui->verify_np_label->setDisabled(b);
    ui->verify_np_line->setDisabled(b);
    ui->verify_np_line->setText("");

    ui->ok_button->setDisabled(b);
}

void PasswordDialog::rInit()
{
    init();
    QDialog::reject();
}

void PasswordDialog::aInit()
{
    if(ui->np_label->isEnabled())
    {
        if(ui->np_line->text() != ui->verify_np_line->text())
        {
            QMessageBox::warning(this,"Mismatching Fields", "New password fields do not match");
            return;
        }

        if(ui->np_line->text().isEmpty() && ui->nu_line->text().isEmpty())
        {
            QMessageBox::warning(this,"No new information", "Neither username or password was updated\n"
                                                            "Update at least one field");
            return;
        }

        if(!ui->np_line->text().isEmpty())
        {
            mwp()->updatePassword(ui->np_line->text());
        }
        if(!ui->nu_line->text().isEmpty())
        {
            mwp()->updateUsername(ui->nu_line->text());
        }

        init();
        QDialog::accept();
    }
    else
    {
        QMessageBox::warning(this,"Validation Error", "Bad username or password\n\n"
                    "Enter a valid username and password, then update chosen fields");
    }
}

void PasswordDialog::validate()
{
    //ui->buttonBox->setEnabled(false);
    if( mwp()->validate(ui->username_line->text(),ui->password_line->text()) )
    {
        const bool b = false;
        ui->username_label->setDisabled(!b);
        ui->username_line->setDisabled(!b);

        ui->password_label->setDisabled(!b);
        ui->password_line->setDisabled(!b);

        //ui->validate_button->setDisabled(!b);


        ui->nu_label->setDisabled(b);
        ui->nu_line->setDisabled(b);

        ui->np_label->setDisabled(b);
        ui->np_line->setDisabled(b);

        ui->verify_np_label->setDisabled(b);
        ui->verify_np_line->setDisabled(b);

        ui->ok_button->setDisabled(b);
    }
}
