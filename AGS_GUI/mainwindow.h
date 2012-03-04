#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "optionsdialog.h"

namespace Ui {
    class MainWindow;
}

class PasswordDialog;
class QFileDialog;
class QInputDialog;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void updateFileName(const QString &name);

    void installChildrenEventFilter(QObject *o);
    void hideChildren(QWidget* w);
    QString genFileName();
    void updateEventFromFile(QString fileName);

    QString strippedName(const QString &fullFileName);

    bool validate(QString username, QString password);

    void updateUsername(QString username);
    void updatePassword(QString password);

public slots:
    void newFile();
    void openFile();
    void loadFile(QString s);
    void openRecentFile();
    void showOptions();
    void updateTime();
    void lookupAGS_ID();
    void lookupPCC_ID();
    void lookupPCC_ID(QString s);
    void setEventType(QString s);
    void setEventID(int i);
    void setEventTypeID(QString s, int i);
    void boo();
    void showError(QString s);
    void login();
    void logout();


protected:
    QStringList todaysFiles();
    void setCurrentFile(const QString &fileName);
    void updateRecentFileActions();
    void showMain();
    void keyPressEvent(QKeyEvent *e);
    void timerEvent(QTimerEvent *e);
    bool eventFilter(QObject *o, QEvent *e);
private:
    bool firstLogin;
    static const int DISPLAY_MILS = 2500, IDLE_TIME = 60000;
    int stampTimer, readTimer, ot, messageTimer, loginTimer, lmTimer;
    Ui::MainWindow *ui;
    QString buffer, fName, eName, curFile;
    OptionsDialog *dialog;
    PasswordDialog *pDialog;
    QFileDialog *fDialog;
    QInputDialog *iDialog;
    QStringList files;

    enum { MaxRecentFiles = 10 };
    QAction *recentFileActs[MaxRecentFiles];
    QAction *separatorAct;
};

#endif // MAINWINDOW_H
