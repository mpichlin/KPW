/****************************************************************************
** Meta object code from reading C++ file 'przegladarka.h'
**
** Created: Sat Jan 1 18:03:08 2011
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
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      33,   13,   14,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
      51,   13,   13,   13, 0x0a,
      60,   13,   13,   13, 0x0a,
      68,   13,   13,   13, 0x0a,
      76,   13,   13,   13, 0x0a,
      85,   13,   13,   13, 0x0a,
      95,   13,   13,   13, 0x0a,
     105,   13,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_przegladarka[] = {
    "przegladarka\0\0QList<SkosConcept>\0"
    "lista_konceptow()\0edytuj()\0dodaj()\0"
    "pokaz()\0zapisz()\0wczytaj()\0odswiez()\0"
    "wstaw_z_listy()\0"
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
        case 0: { QList<SkosConcept> _r = lista_konceptow();
            if (_a[0]) *reinterpret_cast< QList<SkosConcept>*>(_a[0]) = _r; }  break;
        case 1: edytuj(); break;
        case 2: dodaj(); break;
        case 3: pokaz(); break;
        case 4: zapisz(); break;
        case 5: wczytaj(); break;
        case 6: odswiez(); break;
        case 7: wstaw_z_listy(); break;
        default: ;
        }
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
QList<SkosConcept> przegladarka::lista_konceptow()
{
    QList<SkosConcept> _t0;
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(&_t0)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
    return _t0;
}
QT_END_MOC_NAMESPACE
