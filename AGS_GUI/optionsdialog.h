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
    explicit OptionsDialog(QWidget *parent = 0);
    ~OptionsDialog();

public slots:
    void accept();

protected:
    MainWindow* mwp();

private:
    Ui::OptionsDialog *ui;
};

#endif // OPTIONSDIALOG_H
