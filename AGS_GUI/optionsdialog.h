#ifndef OPTIONSDIALOG_H
#define OPTIONSDIALOG_H

#include <QDialog>

class MainWindow;

namespace Ui {
    class OptionsDialog;
}

enum AGSEventType{NONE=0, AGS, CS, Meeting ,Social, Other};

class OptionsDialog : public QDialog
{
    Q_OBJECT

public:
    enum OptionTypes{HOST, USER, PASS, DATABASE, PORT, SEMESTER, EVENT_TYPE, EVENT_ID, HRS_PER_PERSON,
          TSHIRT_CALC, TSHIRT_MULT,SHIFT,SUBMITTED_BY, SIZE};
    explicit OptionsDialog(QWidget *parent = 0);
    ~OptionsDialog();

    void setValue(OptionTypes type, QString value);

signals:
    void eventChanged(AGSEventType type, int id);
public slots:
    void setEvent(AGSEventType type, int id);
    void setTShirtCalc(double multiplier, bool on);
    void accept();
    void reject();

protected:
    MainWindow* mwp();
    void getDefaults();
    void updateDefaults();
    void updateFields();

private:
    Ui::OptionsDialog *ui;
    QString defaults[SIZE];
    bool valueChanged[SIZE];
};

#endif // OPTIONSDIALOG_H
