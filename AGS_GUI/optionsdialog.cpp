#include "optionsdialog.h"
#include "ui_optionsdialog.h"
#include "mainwindow.h"
#include <QDebug>

OptionsDialog::OptionsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OptionsDialog)
{
    ui->setupUi(this);

    getDefaults();
    updateFields();
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
    updateDefaults();
    /*/      At this point, you can access fields through defaults[enum]       /*/
    /*/            this is the easiest way to get a necessary value            /*/
    /*/ You may also check to see if the value changed with valueChanged[enum] /*/
    //[!]
    emit eventChanged((AGSEventType)defaults[EVENT_TYPE].toInt(),defaults[EVENT_ID].toInt());
    mwp()->setTShirtCalc(defaults[TSHIRT_MULT].toDouble(),defaults[TSHIRT_CALC] == "TRUE");
    for(int i = 0; i < SIZE; i++)
    {
        if(valueChanged[i])
            qDebug() << i;
    }

    QDialog::accept(); //DO NOT MODIFY
}

void OptionsDialog::reject()
{
    updateFields();
    QDialog::reject(); //DO NOT MODIFY
}

void OptionsDialog::getDefaults()
{
    /*  This should read defaults from a file   */
    /*         all defaults are strings         */
    /*    for numbers, use QString::number()    */
    /*/                   [!]                   */
    //set host name
    defaults[HOST] = "";
    valueChanged[HOST] = false;

    //set user
    defaults[USER] = "";
    valueChanged[USER] = false;

    //set pass
    defaults[PASS] = "";
    valueChanged[PASS] = false;

    //set database
    defaults[DATABASE] = "";
    valueChanged[DATABASE] = false;

    //set port
    defaults[PORT] = "";
    valueChanged[DATABASE] = false;
    /*------------------------------*/

    //set semester ID
    defaults[SEMESTER] = "";
    valueChanged[SEMESTER] = false;

    //set event ID
    defaults[EVENT_TYPE] = "0";
    valueChanged[EVENT_TYPE] = false;

    defaults[EVENT_ID] = "";
    valueChanged[EVENT_ID] = false;

    //set event hrs / person
    defaults[HRS_PER_PERSON] = "";
    valueChanged[HRS_PER_PERSON] = false;

    //set T-shirt calc
    defaults[TSHIRT_CALC] = "FALSE";
    valueChanged[TSHIRT_CALC] = false;

    defaults[TSHIRT_MULT] = "1.00";
    valueChanged[TSHIRT_MULT] = false;

    //set shift ID
    defaults[SHIFT] = "";
    valueChanged[SHIFT] = false;

    //set submitted by
    defaults[SUBMITTED_BY] = "";
    valueChanged[SUBMITTED_BY] = false;
    /*/                 [/!]                */
}

void OptionsDialog::updateDefaults()
{
    valueChanged[HOST] = defaults[HOST] != ui->host_line->text();
    defaults[HOST] = ui->host_line->text();

    valueChanged[USER] = defaults[USER] != ui->user_line->text();
    defaults[USER] = ui->user_line->text();

    valueChanged[PASS] = defaults[PASS] != ui->password_line->text();
    defaults[PASS] = ui->password_line->text();

    valueChanged[DATABASE] = defaults[DATABASE] != ui->database_line->text();
    defaults[DATABASE] = ui->database_line->text();

    valueChanged[PORT] = defaults[PORT] != ui->port_line->text();
    defaults[PORT] = ui->port_line->text();
    /*------------------------------*/

    valueChanged[SEMESTER] = defaults[SEMESTER] != ui->semester_line->text();
    defaults[SEMESTER] = ui->semester_line->text();

    valueChanged[EVENT_TYPE] = defaults[EVENT_TYPE] != QString::number(ui->event_type_box->currentIndex());
    defaults[EVENT_TYPE] = QString::number(ui->event_type_box->currentIndex());

    valueChanged[EVENT_ID] = defaults[EVENT_ID] != ui->event_id_line->text();
    defaults[EVENT_ID] = ui->event_id_line->text();

    valueChanged[HRS_PER_PERSON] = defaults[HRS_PER_PERSON] != ui->hours_per_person_line->text();
    defaults[HRS_PER_PERSON] = ui->hours_per_person_line->text();

    valueChanged[TSHIRT_CALC] = defaults[TSHIRT_CALC] != ((ui->tshirt_box->isChecked())?"TRUE":"FALSE");
    defaults[TSHIRT_CALC] = (ui->tshirt_box->isChecked())?"TRUE":"FALSE";

    valueChanged[TSHIRT_MULT] = defaults[TSHIRT_MULT] != QString::number(ui->multiplier_box->value());
    defaults[TSHIRT_MULT] = ui->multiplier_box->text();

    valueChanged[SHIFT] = defaults[SHIFT] != ui->shift_line->text();
    defaults[SHIFT] = ui->shift_line->text();

    valueChanged[SUBMITTED_BY] = defaults[SUBMITTED_BY] != ui->submitted_by_line->text();
    defaults[SUBMITTED_BY] = ui->submitted_by_line->text();
}

void OptionsDialog::updateFields()
{
    ui->host_line->setText(defaults[HOST]);
    ui->user_line->setText(defaults[USER]);
    ui->password_line->setText(defaults[PASS]);
    ui->database_line->setText(defaults[DATABASE]);
    ui->port_line->setText(defaults[PORT]);

    ui->semester_line->setText(defaults[SEMESTER]);
    ui->event_type_box->setCurrentIndex(defaults[EVENT_TYPE].toInt());
    ui->event_id_line->setText(defaults[EVENT_ID]);
    ui->hours_per_person_line->setText(defaults[HRS_PER_PERSON]);
    ui->tshirt_box->setChecked(defaults[TSHIRT_CALC] == "TRUE");
    ui->multiplier_box->setValue(defaults[TSHIRT_MULT].toDouble());
    ui->shift_line->setText(defaults[SHIFT]);
    ui->submitted_by_line->setText(defaults[SUBMITTED_BY]);
}

void OptionsDialog::setEvent(AGSEventType type, int id)
{
    ui->event_type_box->setCurrentIndex(type);
    ui->event_id_line->setText(QString::number(id));

    updateDefaults();
    // Do what you need with these two values here[!]
}

void OptionsDialog::setTShirtCalc(double multiplier, bool on)
{
    ui->multiplier_box->setValue(multiplier);
    ui->tshirt_box->setChecked(on);

    updateDefaults();
    //Do what you need with these two values here[!]
}
