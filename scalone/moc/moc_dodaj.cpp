/****************************************************************************
** Meta object code from reading C++ file 'dodaj.h'
**
** Created: Thu Dec 30 12:42:10 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../inc/dodaj.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dodaj.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_dodaj[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       7,    6,    6,    6, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_dodaj[] = {
    "dodaj\0\0odswiez()\0"
};

const QMetaObject dodaj::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_dodaj,
      qt_meta_data_dodaj, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &dodaj::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *dodaj::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *dodaj::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_dodaj))
        return static_cast<void*>(const_cast< dodaj*>(this));
    return QDialog::qt_metacast(_clname);
}

int dodaj::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: odswiez(); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE