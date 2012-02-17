#include "readerthread.h"
#include <conio.h>

ReaderThread::ReaderThread(const QString &h, const QString &u, const QString &p, const QString &n, QMutex *mux, QObject *parent) :
    QThread(parent)
{
}

void ReaderThread::run()
{
    running = true;
    while(running)
    {
        ;//if(std::cin.peek())
        //read and give to main window
    }
}
