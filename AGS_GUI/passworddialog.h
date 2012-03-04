#ifndef PASSWORDDIALOG_H
#define PASSWORDDIALOG_H

#include <QDialog>

class MainWindow;

namespace Ui {
    class PasswordDialog;
}

class PasswordDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PasswordDialog(QWidget *parent = 0);
    ~PasswordDialog();

public slots:
    void accept();
    void reject();
    void validate();

protected:
    MainWindow* mwp();
    void init();
    void rInit();
    void aInit();

private:
    Ui::PasswordDialog *ui;
};

#endif // PASSWORDDIALOG_H
