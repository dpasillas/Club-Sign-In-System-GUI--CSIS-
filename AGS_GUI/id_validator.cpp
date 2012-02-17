#include "id_validator.h"
#include "conio.h"
#include <QRegExp>
#include <QLineEdit>
#include <QThread>

ID_Validator::ID_Validator(QObject *parent):
    QValidator(parent)
{
    mode = KEYBOARD;
}

QValidator::State ID_Validator::validate(QString &str, int &pos) const
{
    if(str.length() == 0 || mode == ACCEPT)
        return Acceptable;

    static QRegExp digits("\\d*");
    if(str[0] == '%')
    {
        mode = CARD;
    }

    if(mode == KEYBOARD)
    {
        if(digits.exactMatch(str))
        {
            return QValidator::Acceptable;
        }
    }
    else
    {
        if(str[0].isDigit())
            buffer.append(str[0]);
        if(str[0] == ';')
            buffer.clear();
        //qDebug(buffer.toStdString().c_str());

        return Invalid;
    }

    return QValidator::Invalid;
}

void ID_Validator::doneReading()
{
    if(mode == KEYBOARD)
        return;

    qDebug(buffer.toStdString().c_str());

    mode = KEYBOARD;
    emit doneProcessing(buffer.right(8));


    qDebug("...");

    buffer.clear();
    //((QLineEdit*)(sender()))->setText("");
}

void ID_Validator::fixup(QString &str) const
{
    //if(str.length() == 7 || str.length() == 6)
    //    str.prepend(QString("0").repeated(8 - str.length()));
}
