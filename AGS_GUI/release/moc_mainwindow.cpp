/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Thu Mar 8 16:22:59 2012
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
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,
      22,   11,   11,   11, 0x0a,
      33,   11,   11,   11, 0x0a,
      48,   46,   11,   11, 0x0a,
      66,   11,   11,   11, 0x0a,
      83,   11,   11,   11, 0x0a,
      97,   11,   11,   11, 0x0a,
     110,   11,   11,   11, 0x0a,
     125,   11,   11,   11, 0x0a,
     140,   46,   11,   11, 0x0a,
     162,   46,   11,   11, 0x0a,
     186,  184,   11,   11, 0x0a,
     206,  202,   11,   11, 0x0a,
     234,   11,   11,   11, 0x0a,
     240,   46,   11,   11, 0x0a,
     259,   11,   11,   11, 0x0a,
     267,   11,   11,   11, 0x0a,
     276,   11,   11,   11, 0x0a,
     284,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0newFile()\0openFile()\0"
    "exportFile()\0s\0loadFile(QString)\0"
    "openRecentFile()\0showOptions()\0"
    "updateTime()\0lookupAGS_ID()\0lookupPCC_ID()\0"
    "lookupPCC_ID(QString)\0setEventType(QString)\0"
    "i\0setEventID(int)\0s,i\0setEventTypeID(QString,int)\0"
    "boo()\0showError(QString)\0login()\0"
    "logout()\0about()\0tutorial()\0"
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
        case 2: exportFile(); break;
        case 3: loadFile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: openRecentFile(); break;
        case 5: showOptions(); break;
        case 6: updateTime(); break;
        case 7: lookupAGS_ID(); break;
        case 8: lookupPCC_ID(); break;
        case 9: lookupPCC_ID((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: setEventType((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: setEventID((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: setEventTypeID((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 13: boo(); break;
        case 14: showError((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 15: login(); break;
        case 16: logout(); break;
        case 17: about(); break;
        case 18: tutorial(); break;
        default: ;
        }
        _id -= 19;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
