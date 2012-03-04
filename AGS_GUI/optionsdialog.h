#ifndef OPTIONSDIALOG_H
#define OPTIONSDIALOG_H

#include <QDialog>

class MainWindow;

namespace Ui {
    class OptionsDialog;
}

class OptionsDialog : public QDialog
{
    Q_OBJECT

public:
    enum {HOST, USER, PASS, DATABASE, PORT, SEMESTER, EVENT, HRS_PER_PERSON,
          TSHIRT_CALC,SHIFT,SUBMITTED_BY, SIZE};
    explicit OptionsDialog(QWidget *parent = 0);
    ~OptionsDialog();

public slots:
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
