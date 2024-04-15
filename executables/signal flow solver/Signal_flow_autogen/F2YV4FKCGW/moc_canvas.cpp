/****************************************************************************
** Meta object code from reading C++ file 'canvas.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Signal_flow/headers/widgets/canvas.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'canvas.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSCanvasWidgetENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSCanvasWidgetENDCLASS = QtMocHelpers::stringData(
    "CanvasWidget",
    "sendOutputs",
    "",
    "vector<pair<path,double>>",
    "paths",
    "map<string,pair<path,double>>",
    "loops",
    "vector<vector<pair<string,double>>>",
    "nonTouched",
    "vector<pair<string,double>>",
    "deltas",
    "delta",
    "tf",
    "onNodeSelected",
    "onPathSelected",
    "onClearPressed",
    "onStartSim"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSCanvasWidgetENDCLASS_t {
    uint offsetsAndSizes[34];
    char stringdata0[13];
    char stringdata1[12];
    char stringdata2[1];
    char stringdata3[26];
    char stringdata4[6];
    char stringdata5[30];
    char stringdata6[6];
    char stringdata7[36];
    char stringdata8[11];
    char stringdata9[28];
    char stringdata10[7];
    char stringdata11[6];
    char stringdata12[3];
    char stringdata13[15];
    char stringdata14[15];
    char stringdata15[15];
    char stringdata16[11];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSCanvasWidgetENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSCanvasWidgetENDCLASS_t qt_meta_stringdata_CLASSCanvasWidgetENDCLASS = {
    {
        QT_MOC_LITERAL(0, 12),  // "CanvasWidget"
        QT_MOC_LITERAL(13, 11),  // "sendOutputs"
        QT_MOC_LITERAL(25, 0),  // ""
        QT_MOC_LITERAL(26, 25),  // "vector<pair<path,double>>"
        QT_MOC_LITERAL(52, 5),  // "paths"
        QT_MOC_LITERAL(58, 29),  // "map<string,pair<path,double>>"
        QT_MOC_LITERAL(88, 5),  // "loops"
        QT_MOC_LITERAL(94, 35),  // "vector<vector<pair<string,dou..."
        QT_MOC_LITERAL(130, 10),  // "nonTouched"
        QT_MOC_LITERAL(141, 27),  // "vector<pair<string,double>>"
        QT_MOC_LITERAL(169, 6),  // "deltas"
        QT_MOC_LITERAL(176, 5),  // "delta"
        QT_MOC_LITERAL(182, 2),  // "tf"
        QT_MOC_LITERAL(185, 14),  // "onNodeSelected"
        QT_MOC_LITERAL(200, 14),  // "onPathSelected"
        QT_MOC_LITERAL(215, 14),  // "onClearPressed"
        QT_MOC_LITERAL(230, 10)   // "onStartSim"
    },
    "CanvasWidget",
    "sendOutputs",
    "",
    "vector<pair<path,double>>",
    "paths",
    "map<string,pair<path,double>>",
    "loops",
    "vector<vector<pair<string,double>>>",
    "nonTouched",
    "vector<pair<string,double>>",
    "deltas",
    "delta",
    "tf",
    "onNodeSelected",
    "onPathSelected",
    "onClearPressed",
    "onStartSim"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSCanvasWidgetENDCLASS[] = {

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
       1,    6,   44,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      13,    0,   57,    2, 0x0a,    8 /* Public */,
      14,    0,   58,    2, 0x0a,    9 /* Public */,
      15,    0,   59,    2, 0x0a,   10 /* Public */,
      16,    0,   60,    2, 0x0a,   11 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5, 0x80000000 | 7, 0x80000000 | 9, QMetaType::Double, QMetaType::Double,    4,    6,    8,   10,   11,   12,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject CanvasWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSCanvasWidgetENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSCanvasWidgetENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSCanvasWidgetENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<CanvasWidget, std::true_type>,
        // method 'sendOutputs'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<vector<pair<path,double>>, std::false_type>,
        QtPrivate::TypeAndForceComplete<map<string,pair<path,double>>, std::false_type>,
        QtPrivate::TypeAndForceComplete<vector<vector<pair<string,double>> >, std::false_type>,
        QtPrivate::TypeAndForceComplete<vector<pair<string,double>>, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'onNodeSelected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onPathSelected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onClearPressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onStartSim'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void CanvasWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CanvasWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sendOutputs((*reinterpret_cast< std::add_pointer_t<vector<pair<path,double>>>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<map<string,pair<path,double>>>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<vector<vector<pair<string,double>>>>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<vector<pair<string,double>>>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[6]))); break;
        case 1: _t->onNodeSelected(); break;
        case 2: _t->onPathSelected(); break;
        case 3: _t->onClearPressed(); break;
        case 4: _t->onStartSim(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CanvasWidget::*)(vector<pair<path,double>> , map<string,pair<path,double>> , vector<vector<pair<string,double>> > , vector<pair<string,double>> , double , double );
            if (_t _q_method = &CanvasWidget::sendOutputs; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *CanvasWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CanvasWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSCanvasWidgetENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int CanvasWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void CanvasWidget::sendOutputs(vector<pair<path,double>> _t1, map<string,pair<path,double>> _t2, vector<vector<pair<string,double>> > _t3, vector<pair<string,double>> _t4, double _t5, double _t6)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t6))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
