/****************************************************************************
** Meta object code from reading C++ file 'id_validator.h'
**
** Created: Sat Mar 3 19:22:15 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../AGS_GUI/id_validator.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'id_validator.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ID_Validator[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,   14,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
      42,   13,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ID_Validator[] = {
    "ID_Validator\0\0str\0doneProcessing(QString)\0"
    "doneReading()\0"
};

const QMetaObject ID_Validator::staticMetaObject = {
    { &QValidator::staticMetaObject, qt_meta_stringdata_ID_Validator,
      qt_meta_data_ID_Validator, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ID_Validator::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ID_Validator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ID_Validator::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ID_Validator))
        return static_cast<void*>(const_cast< ID_Validator*>(this));
    return QValidator::qt_metacast(_clname);
}

int ID_Validator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QValidator::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: doneProcessing((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: doneReading(); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void ID_Validator::doneProcessing(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
