/****************************************************************************
** Meta object code from reading C++ file 'edytor.h'
**
** Created: Sat Jan 1 16:26:24 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../inc/edytor.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'edytor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_edytor[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x0a,
      24,    7,    7,    7, 0x0a,
      43,    7,    7,    7, 0x0a,
      58,    7,    7,    7, 0x0a,
      76,    7,    7,    7, 0x0a,
      90,    7,    7,    7, 0x0a,
     102,    7,    7,    7, 0x0a,
     139,    7,    7,    7, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_edytor[] = {
    "edytor\0\0zmien_szersze()\0dodaj_skojarzone()\0"
    "dodaj_wezsze()\0usun_skojarzone()\0"
    "usun_wezsze()\0zatwierdz()\0"
    "dodaj_atlernatywne(QListWidgetItem*)\0"
    "dodaj_ukryte(QListWidgetItem*)\0"
};

const QMetaObject edytor::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_edytor,
      qt_meta_data_edytor, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &edytor::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *edytor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *edytor::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_edytor))
        return static_cast<void*>(const_cast< edytor*>(this));
    return QDialog::qt_metacast(_clname);
}

int edytor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: zmien_szersze(); break;
        case 1: dodaj_skojarzone(); break;
        case 2: dodaj_wezsze(); break;
        case 3: usun_skojarzone(); break;
        case 4: usun_wezsze(); break;
        case 5: zatwierdz(); break;
        case 6: dodaj_atlernatywne((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 7: dodaj_ukryte((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
