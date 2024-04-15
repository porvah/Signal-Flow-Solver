/****************************************************************************
** Meta object code from reading C++ file 'output.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Signal_flow/headers/widgets/output.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'output.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSOutputWidgetENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSOutputWidgetENDCLASS = QtMocHelpers::stringData(
    "OutputWidget",
    "updateText",
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
    "tf"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSOutputWidgetENDCLASS_t {
    uint offsetsAndSizes[26];
    char stringdata0[13];
    char stringdata1[11];
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
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSOutputWidgetENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSOutputWidgetENDCLASS_t qt_meta_stringdata_CLASSOutputWidgetENDCLASS = {
    {
        QT_MOC_LITERAL(0, 12),  // "OutputWidget"
        QT_MOC_LITERAL(13, 10),  // "updateText"
        QT_MOC_LITERAL(24, 0),  // ""
        QT_MOC_LITERAL(25, 25),  // "vector<pair<path,double>>"
        QT_MOC_LITERAL(51, 5),  // "paths"
        QT_MOC_LITERAL(57, 29),  // "map<string,pair<path,double>>"
        QT_MOC_LITERAL(87, 5),  // "loops"
        QT_MOC_LITERAL(93, 35),  // "vector<vector<pair<string,dou..."
        QT_MOC_LITERAL(129, 10),  // "nonTouched"
        QT_MOC_LITERAL(140, 27),  // "vector<pair<string,double>>"
        QT_MOC_LITERAL(168, 6),  // "deltas"
        QT_MOC_LITERAL(175, 5),  // "delta"
        QT_MOC_LITERAL(181, 2)   // "tf"
    },
    "OutputWidget",
    "updateText",
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
    "tf"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSOutputWidgetENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    6,   20,    2, 0x0a,    1 /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5, 0x80000000 | 7, 0x80000000 | 9, QMetaType::Double, QMetaType::Double,    4,    6,    8,   10,   11,   12,

       0        // eod
};

Q_CONSTINIT const QMetaObject OutputWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSOutputWidgetENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSOutputWidgetENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSOutputWidgetENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<OutputWidget, std::true_type>,
        // method 'updateText'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<vector<pair<path,double>>, std::false_type>,
        QtPrivate::TypeAndForceComplete<map<string,pair<path,double>>, std::false_type>,
        QtPrivate::TypeAndForceComplete<vector<vector<pair<string,double>> >, std::false_type>,
        QtPrivate::TypeAndForceComplete<vector<pair<string,double>>, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>
    >,
    nullptr
} };

void OutputWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<OutputWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->updateText((*reinterpret_cast< std::add_pointer_t<vector<pair<path,double>>>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<map<string,pair<path,double>>>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<vector<vector<pair<string,double>>>>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<vector<pair<string,double>>>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[6]))); break;
        default: ;
        }
    }
}

const QMetaObject *OutputWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OutputWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSOutputWidgetENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int OutputWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 1;
    }
    return _id;
}
QT_WARNING_POP
