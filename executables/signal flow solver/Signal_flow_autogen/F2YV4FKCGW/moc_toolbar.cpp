/****************************************************************************
** Meta object code from reading C++ file 'toolbar.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Signal_flow/headers/widgets/toolbar.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'toolbar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.1. It"
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
struct qt_meta_stringdata_CLASSToolBarWidgetENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSToolBarWidgetENDCLASS = QtMocHelpers::stringData(
    "ToolBarWidget",
    "selectNode",
    "",
    "selectPath",
    "pressClear",
    "startSim"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSToolBarWidgetENDCLASS_t {
    uint offsetsAndSizes[12];
    char stringdata0[14];
    char stringdata1[11];
    char stringdata2[1];
    char stringdata3[11];
    char stringdata4[11];
    char stringdata5[9];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSToolBarWidgetENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSToolBarWidgetENDCLASS_t qt_meta_stringdata_CLASSToolBarWidgetENDCLASS = {
    {
        QT_MOC_LITERAL(0, 13),  // "ToolBarWidget"
        QT_MOC_LITERAL(14, 10),  // "selectNode"
        QT_MOC_LITERAL(25, 0),  // ""
        QT_MOC_LITERAL(26, 10),  // "selectPath"
        QT_MOC_LITERAL(37, 10),  // "pressClear"
        QT_MOC_LITERAL(48, 8)   // "startSim"
    },
    "ToolBarWidget",
    "selectNode",
    "",
    "selectPath",
    "pressClear",
    "startSim"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSToolBarWidgetENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   38,    2, 0x06,    1 /* Public */,
       3,    0,   39,    2, 0x06,    2 /* Public */,
       4,    0,   40,    2, 0x06,    3 /* Public */,
       5,    0,   41,    2, 0x06,    4 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject ToolBarWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QToolBar::staticMetaObject>(),
    qt_meta_stringdata_CLASSToolBarWidgetENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSToolBarWidgetENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSToolBarWidgetENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<ToolBarWidget, std::true_type>,
        // method 'selectNode'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'selectPath'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'pressClear'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'startSim'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void ToolBarWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ToolBarWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->selectNode(); break;
        case 1: _t->selectPath(); break;
        case 2: _t->pressClear(); break;
        case 3: _t->startSim(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ToolBarWidget::*)();
            if (_t _q_method = &ToolBarWidget::selectNode; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ToolBarWidget::*)();
            if (_t _q_method = &ToolBarWidget::selectPath; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ToolBarWidget::*)();
            if (_t _q_method = &ToolBarWidget::pressClear; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ToolBarWidget::*)();
            if (_t _q_method = &ToolBarWidget::startSim; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
    }
    (void)_a;
}

const QMetaObject *ToolBarWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ToolBarWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSToolBarWidgetENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QToolBar::qt_metacast(_clname);
}

int ToolBarWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QToolBar::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void ToolBarWidget::selectNode()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ToolBarWidget::selectPath()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void ToolBarWidget::pressClear()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void ToolBarWidget::startSim()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
