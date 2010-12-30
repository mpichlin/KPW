/****************************************************************************
** Meta object code from reading C++ file 'przegladarka.h'
**
** Created: Thu Dec 30 20:31:11 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../inc/przegladarka.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'przegladarka.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_przegladarka[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x0a,
      23,   13,   13,   13, 0x0a,
      31,   13,   13,   13, 0x0a,
      39,   13,   13,   13, 0x0a,
      48,   13,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_przegladarka[] = {
    "przegladarka\0\0edytuj()\0dodaj()\0pokaz()\0"
    "zapisz()\0wczytaj()\0"
};

const QMetaObject przegladarka::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_przegladarka,
      qt_meta_data_przegladarka, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &przegladarka::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *przegladarka::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *przegladarka::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_przegladarka))
        return static_cast<void*>(const_cast< przegladarka*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int przegladarka::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: edytuj(); break;
        case 1: dodaj(); break;
        case 2: pokaz(); break;
        case 3: zapisz(); break;
        case 4: wczytaj(); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
