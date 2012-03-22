/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Thu Mar 22 00:12:21 2012
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
      30,   14, // methods
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
      84,   11,   11,   11, 0x0a,
      97,   11,   11,   11, 0x0a,
     118,  116,   11,   11, 0x0a,
     136,   11,   11,   11, 0x0a,
     153,   11,   11,   11, 0x0a,
     167,   11,   11,   11, 0x0a,
     180,   11,   11,   11, 0x0a,
     195,   11,   11,   11, 0x0a,
     210,  116,   11,   11, 0x0a,
     236,  232,   11,   11, 0x0a,
     271,  264,   11,   11, 0x0a,
     298,   11,   11,   11, 0x0a,
     322,  314,   11,   11, 0x0a,
     355,  341,   11,   11, 0x0a,
     395,  382,   11,   11, 0x0a,
     426,  419,   11,   11, 0x2a,
     446,   11,   11,   11, 0x0a,
     452,  116,   11,   11, 0x0a,
     471,   11,   11,   11, 0x0a,
     479,   11,   11,   11, 0x0a,
     488,   11,   11,   11, 0x0a,
     496,   11,   11,   11, 0x0a,
     507,   11,   11,   11, 0x0a,
     520,   11,   11,   11, 0x0a,
     545,   11,  537,   11, 0x0a,
     562,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0type,id\0eventChanged(AGSEventType,int)\0"
    "newFile()\0openFile()\0closeFile()\0"
    "exportFile()\0importToDatabase()\0s\0"
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
        case 3: closeFile(); break;
        case 4: exportFile(); break;
        case 5: importToDatabase(); break;
        case 6: loadFile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: openRecentFile(); break;
        case 8: showOptions(); break;
        case 9: updateTime(); break;
        case 10: lookupAGS_ID(); break;
        case 11: lookupPCC_ID(); break;
        case 12: lookupPCC_ID((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: setEventTypeID((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 14: setEvent((*reinterpret_cast< AGSEventType(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 15: setLogoutTime(); break;
        case 16: setLogoutTime((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: setTShirtCalc((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 18: setTimer((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 19: setTimer((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 20: boo(); break;
        case 21: showError((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 22: login(); break;
        case 23: logout(); break;
        case 24: about(); break;
        case 25: tutorial(); break;
        case 26: reportABug(); break;
        case 27: testConnection(); break;
        case 28: { QString _r = generateHeader();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 29: rewriteHeader(); break;
        default: ;
        }
        _id -= 30;
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
