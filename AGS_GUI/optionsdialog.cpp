#include "optionsdialog.h"
#include "ui_optionsdialog.h"
#include "mainwindow.h"

OptionsDialog::OptionsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OptionsDialog)
{
    ui->setupUi(this);

    //set host name
    //set user
    //set pass
    //set database
    //set port

    //set semester ID
    //set event ID
    //set event hrs / person
    //set T-shirt calc
    //set shift ID
    //set submitted by
}

OptionsDialog::~OptionsDialog()
{
    delete ui;
}

MainWindow* OptionsDialog::mwp()
{
    return (MainWindow*)parent();
}

void OptionsDialog::accept()
{
    //mwp()->updateFileName(ui->lineEdit_5->text());

    QDialog::accept();
}

