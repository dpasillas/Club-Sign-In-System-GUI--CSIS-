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
class QLabel;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    enum HeaderValues{EVENT_TYPE, EVENT_ID, DATE, EVENT_NAME,
                     SHIFT_ID, SEMESTER_ID, SUBMITTED_BY_ID,
                     MULTIPLIER_ON,MULTIPLIER, EXPORTED, HEADER_SIZE};
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

    void resetFields();
    void updateValues(QString values);

    QString getID(QString labelText, bool &ok);

    void setValue(HeaderValues type, QString value);
    void updateOptions();

signals:
    void eventChanged(AGSEventType type, int id);

public slots:
    void newFile();
    void openFile();
    void exportFile();
    void loadFile(QString s);
    void openRecentFile();
    void showOptions();
    void updateTime();
    void lookupAGS_ID();
    void lookupPCC_ID();
    void lookupPCC_ID(QString s);
    void setEventTypeID(QString s, int i);
    void setEvent(AGSEventType type, int i);
    void setLogoutTime();
    void setLogoutTime(int seconds);
    void setTShirtCalc(double multiplier, bool on);
    void setTimer(int &id, int& var, int msecs = 0);
    void boo();
    void showError(QString s);
    void login();
    void logout();
    void about();
    void tutorial();
    void reportABug();
    void testConnection();
    QString generateHeader();
    void rewriteHeader();


protected:
    QStringList todaysFiles();
    void setCurrentFile(const QString &fileName);
    void updateRecentFileActions();
    void showMain();
    void keyPressEvent(QKeyEvent *e);
    void timerEvent(QTimerEvent *e);
    bool eventFilter(QObject *o, QEvent *e);
private:
    bool firstLogin, tShirtCalc;
    double mult;
    static const int DISPLAY_MILS = 2500;
    int IDLE_TIME, CONNECTION_REFRESH;
    int stampTimer, readTimer, ot, messageTimer, loginTimer, lmTimer, connectionTimer;

    Ui::MainWindow *ui;

    QString buffer, fName, eName, curFile;
    OptionsDialog *dialog;
    PasswordDialog *pDialog;
    //QFileDialog *fDialog;
    QInputDialog *iDialog;

    QStringList files;
    QStringList agsEventTypes;

    enum { MaxRecentFiles = 10 };
    QAction *recentFileActs[MaxRecentFiles];
    QAction *separatorAct;

    QWidget *csWidget;
    QLabel *label;

    AGSEventType eType;
    int eID;

    QString criticalValues[HEADER_SIZE];
};

#endif // MAINWINDOW_H
