#ifndef ID_VALIDATOR_H
#define ID_VALIDATOR_H

#include <QValidator>

class ID_Validator : public QValidator
{
    Q_OBJECT
public:
    enum Mode{KEYBOARD, CARD, ACCEPT};
    ID_Validator(QObject* parent = 0);

    State validate(QString &str, int &pos) const;

    void fixup(QString &str) const;

public slots:
    void doneReading();

signals:
    void doneProcessing(QString str);

private:
    mutable Mode mode;
    mutable QString buffer;
};

#endif // ID_VALIDATOR_H
