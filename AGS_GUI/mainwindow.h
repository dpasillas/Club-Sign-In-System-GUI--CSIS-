#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void updateFileName(const QString &name);

public slots:
    void showOptions();
    void updateTime();
    void lookupAGS_ID();
    void lookupPCC_ID();
    void lookupPCC_ID(QString s);
    void setEventType(QString s);
    void setEventID(int i);
    void setEventTypeID(QString s, int i);
    void boo();


protected:
    void keyPressEvent(QKeyEvent *e);
    void timerEvent(QTimerEvent *e);
    bool eventFilter(QObject *o, QEvent *e);
private:
    static const int DISPLAY_MILS = 2500;
    int stampTimer, readTimer, ot;
    Ui::MainWindow *ui;
    QString buffer;
};

#endif // MAINWINDOW_H
