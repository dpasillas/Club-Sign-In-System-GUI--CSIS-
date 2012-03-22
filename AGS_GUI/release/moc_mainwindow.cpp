/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Wed Mar 21 18:41:50 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      28,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      20,   12,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      51,   11,   11,   11, 0x0a,
      61,   11,   11,   11, 0x0a,
      72,   11,   11,   11, 0x0a,
      87,   85,   11,   11, 0x0a,
     105,   11,   11,   11, 0x0a,
     122,   11,   11,   11, 0x0a,
     136,   11,   11,   11, 0x0a,
     149,   11,   11,   11, 0x0a,
     164,   11,   11,   11, 0x0a,
     179,   85,   11,   11, 0x0a,
     205,  201,   11,   11, 0x0a,
     240,  233,   11,   11, 0x0a,
     267,   11,   11,   11, 0x0a,
     291,  283,   11,   11, 0x0a,
     324,  310,   11,   11, 0x0a,
     364,  351,   11,   11, 0x0a,
     395,  388,   11,   11, 0x2a,
     415,   11,   11,   11, 0x0a,
     421,   85,   11,   11, 0x0a,
     440,   11,   11,   11, 0x0a,
     448,   11,   11,   11, 0x0a,
     457,   11,   11,   11, 0x0a,
     465,   11,   11,   11, 0x0a,
     476,   11,   11,   11, 0x0a,
     489,   11,   11,   11, 0x0a,
     514,   11,  506,   11, 0x0a,
     531,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0type,id\0eventChanged(AGSEventType,int)\0"
    "newFile()\0openFile()\0exportFile()\0s\0"
    "loadFile(QString)\0openRecentFile()\0"
    "showOptions()\0updateTime()\0lookupAGS_ID()\0"
    "lookupPCC_ID()\0lookupPCC_ID(QString)\0"
    "s,i\0setEventTypeID(QString,int)\0type,i\0"
    "setEvent(AGSEventType,int)\0setLogoutTime()\0"
    "seconds\0setLogoutTime(int)\0multiplier,on\0"
    "setTShirtCalc(double,bool)\0id,var,msecs\0"
    "setTimer(int&,int&,int)\0id,var\0"
    "setTimer(int&,int&)\0boo()\0showError(QString)\0"
    "login()\0logout()\0about()\0tutorial()\0"
    "reportABug()\0testConnection()\0QString\0"
    "generateHeader()\0rewriteHeader()\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: eventChanged((*reinterpret_cast< AGSEventType(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: newFile(); break;
        case 2: openFile(); break;
        case 3: exportFile(); break;
        case 4: loadFile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: openRecentFile(); break;
        case 6: showOptions(); break;
        case 7: updateTime(); break;
        case 8: lookupAGS_ID(); break;
        case 9: lookupPCC_ID(); break;
        case 10: lookupPCC_ID((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: setEventTypeID((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 12: setEvent((*reinterpret_cast< AGSEventType(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 13: setLogoutTime(); break;
        case 14: setLogoutTime((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: setTShirtCalc((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 16: setTimer((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 17: setTimer((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 18: boo(); break;
        case 19: showError((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 20: login(); break;
        case 21: logout(); break;
        case 22: about(); break;
        case 23: tutorial(); break;
        case 24: reportABug(); break;
        case 25: testConnection(); break;
        case 26: { QString _r = generateHeader();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 27: rewriteHeader(); break;
        default: ;
        }
        _id -= 28;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::eventChanged(AGSEventType _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
