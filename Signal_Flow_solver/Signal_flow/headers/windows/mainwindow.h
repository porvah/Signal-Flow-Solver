#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QBoxLayout>
#include <QLabel>
#include "../../headers/widgets/toolbar.h"
#include "../../headers/widgets/output.h"
#include "../../headers/widgets/canvas.h"
#include "../../headers/widgets/validation_dialog.h"
#include "../../headers/widgets/gain_input_dialog.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent);
    ~MainWindow();

private:   
    QVBoxLayout *mainLayout;
    QHBoxLayout *workspaceLayout;
    ToolBarWidget* toolbarWidget;
    OutputWidget* outputWidget;
    ValidationDialog* validationDialog;
    GainInputDialog* gainInputDialog;
    QWidget* workspace;
    CanvasWidget* canvas;
    void prepareChildren();
};
#endif // MAINWINDOW_H
