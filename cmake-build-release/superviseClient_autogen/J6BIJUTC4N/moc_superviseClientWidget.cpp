/****************************************************************************
** Meta object code from reading C++ file 'superviseClientWidget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../head/superviseClientWidget.h"
#include <QtGui/qtextcursor.h>
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'superviseClientWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSsuperviseClientWidgetENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSsuperviseClientWidgetENDCLASS = QtMocHelpers::stringData(
    "superviseClientWidget",
    "imageAcquired",
    "",
    "onMjpgReadyRead",
    "onJpegReadyRead",
    "on_btnGetMjpg_clicked",
    "on_btnGetJpeg_clicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSsuperviseClientWidgetENDCLASS_t {
    uint offsetsAndSizes[14];
    char stringdata0[22];
    char stringdata1[14];
    char stringdata2[1];
    char stringdata3[16];
    char stringdata4[16];
    char stringdata5[22];
    char stringdata6[22];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSsuperviseClientWidgetENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSsuperviseClientWidgetENDCLASS_t qt_meta_stringdata_CLASSsuperviseClientWidgetENDCLASS = {
    {
        QT_MOC_LITERAL(0, 21),  // "superviseClientWidget"
        QT_MOC_LITERAL(22, 13),  // "imageAcquired"
        QT_MOC_LITERAL(36, 0),  // ""
        QT_MOC_LITERAL(37, 15),  // "onMjpgReadyRead"
        QT_MOC_LITERAL(53, 15),  // "onJpegReadyRead"
        QT_MOC_LITERAL(69, 21),  // "on_btnGetMjpg_clicked"
        QT_MOC_LITERAL(91, 21)   // "on_btnGetJpeg_clicked"
    },
    "superviseClientWidget",
    "imageAcquired",
    "",
    "onMjpgReadyRead",
    "onJpegReadyRead",
    "on_btnGetMjpg_clicked",
    "on_btnGetJpeg_clicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSsuperviseClientWidgetENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   44,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   47,    2, 0x08,    3 /* Private */,
       4,    0,   48,    2, 0x08,    4 /* Private */,
       5,    0,   49,    2, 0x08,    5 /* Private */,
       6,    0,   50,    2, 0x08,    6 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QImage,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject superviseClientWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSsuperviseClientWidgetENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSsuperviseClientWidgetENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSsuperviseClientWidgetENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<superviseClientWidget, std::true_type>,
        // method 'imageAcquired'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QImage, std::false_type>,
        // method 'onMjpgReadyRead'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onJpegReadyRead'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnGetMjpg_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnGetJpeg_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void superviseClientWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<superviseClientWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->imageAcquired((*reinterpret_cast< std::add_pointer_t<QImage>>(_a[1]))); break;
        case 1: _t->onMjpgReadyRead(); break;
        case 2: _t->onJpegReadyRead(); break;
        case 3: _t->on_btnGetMjpg_clicked(); break;
        case 4: _t->on_btnGetJpeg_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (superviseClientWidget::*)(QImage );
            if (_t _q_method = &superviseClientWidget::imageAcquired; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *superviseClientWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *superviseClientWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSsuperviseClientWidgetENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int superviseClientWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void superviseClientWidget::imageAcquired(QImage _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
