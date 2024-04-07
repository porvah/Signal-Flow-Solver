#ifndef TOOLBARWIDGET_H
#define TOOLBARWIDGET_H

#include <QWidget>
#include <QToolBar>
#include <QPushButton>
#include <QLabel>
#include "output.h"
#include "validation_dialog.h"
#include "gain_input_dialog.h"

class ToolBarWidget : public QToolBar
{
    Q_OBJECT

public:
    explicit ToolBarWidget(QWidget* parent = nullptr, OutputWidget* outputWidget = nullptr, ValidationDialog* validationWidget = nullptr, GainInputDialog* gainInputDialog = nullptr);

    std::string getChosenButton();

private:
    QString chosenButton;
    QPushButton* chooseNode;
    QPushButton* choosePath;
    QPushButton* clear;
    QPushButton* simulate;
    QLabel* chosenLabel;
    OutputWidget* outputWidgetRef;
    ValidationDialog* validationDialog;
    GainInputDialog* gainInputDialog;
};

#endif
