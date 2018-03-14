/****************************************************************************
** Meta object code from reading C++ file 'selectmultifolders.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../selectmultifolders.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'selectmultifolders.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SelectMultiFolders_t {
    QByteArrayData data[3];
    char stringdata0[40];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SelectMultiFolders_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SelectMultiFolders_t qt_meta_stringdata_SelectMultiFolders = {
    {
QT_MOC_LITERAL(0, 0, 18), // "SelectMultiFolders"
QT_MOC_LITERAL(1, 19, 19), // "on_clicked_btn_open"
QT_MOC_LITERAL(2, 39, 0) // ""

    },
    "SelectMultiFolders\0on_clicked_btn_open\0"
    ""
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SelectMultiFolders[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void SelectMultiFolders::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SelectMultiFolders *_t = static_cast<SelectMultiFolders *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_clicked_btn_open(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject SelectMultiFolders::staticMetaObject = {
    { &QFileDialog::staticMetaObject, qt_meta_stringdata_SelectMultiFolders.data,
      qt_meta_data_SelectMultiFolders,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SelectMultiFolders::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SelectMultiFolders::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SelectMultiFolders.stringdata0))
        return static_cast<void*>(const_cast< SelectMultiFolders*>(this));
    return QFileDialog::qt_metacast(_clname);
}

int SelectMultiFolders::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFileDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
