#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QBoxLayout>
#include <QLabel>
#include "../../headers/widgets/toolbar.h"
#include "../../headers/widgets/output.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent);
    ~MainWindow();

private:   
    QVBoxLayout *mainLayout;
    ToolBarWidget* toolbarWidget;
    OutputWidget* outputWidget;
};
#endif // MAINWINDOW_H
