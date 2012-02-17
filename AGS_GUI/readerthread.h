#ifndef READERTHREAD_H
#define READERTHREAD_H

#include <QThread>
#include <QMutex>

class ReaderThread : public QThread
{
    Q_OBJECT
public:
    explicit ReaderThread(const QString &h, const QString &u, const QString &p, const QString &n, QMutex* mux, QObject *parent = 0);

    void run();

signals:

public slots:

private:
    bool running;

};

#endif // READERTHREAD_H
