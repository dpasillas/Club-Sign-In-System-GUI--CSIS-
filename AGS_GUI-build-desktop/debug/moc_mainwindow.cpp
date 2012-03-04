/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Sat Mar 3 19:22:11 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../AGS_GUI/mainwindow.h"
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
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,
      22,   11,   11,   11, 0x0a,
      35,   33,   11,   11, 0x0a,
      53,   11,   11,   11, 0x0a,
      70,   11,   11,   11, 0x0a,
      84,   11,   11,   11, 0x0a,
      97,   11,   11,   11, 0x0a,
     112,   11,   11,   11, 0x0a,
     127,   33,   11,   11, 0x0a,
     149,   33,   11,   11, 0x0a,
     173,  171,   11,   11, 0x0a,
     193,  189,   11,   11, 0x0a,
     221,   11,   11,   11, 0x0a,
     227,   33,   11,   11, 0x0a,
     246,   11,   11,   11, 0x0a,
     254,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0newFile()\0openFile()\0s\0"
    "loadFile(QString)\0openRecentFile()\0"
    "showOptions()\0updateTime()\0lookupAGS_ID()\0"
    "lookupPCC_ID()\0lookupPCC_ID(QString)\0"
    "setEventType(QString)\0i\0setEventID(int)\0"
    "s,i\0setEventTypeID(QString,int)\0boo()\0"
    "showError(QString)\0login()\0logout()\0"
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
        case 0: newFile(); break;
        case 1: openFile(); break;
        case 2: loadFile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: openRecentFile(); break;
        case 4: showOptions(); break;
        case 5: updateTime(); break;
        case 6: lookupAGS_ID(); break;
        case 7: lookupPCC_ID(); break;
        case 8: lookupPCC_ID((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: setEventType((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: setEventID((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: setEventTypeID((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 12: boo(); break;
        case 13: showError((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 14: login(); break;
        case 15: logout(); break;
        default: ;
        }
        _id -= 16;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
