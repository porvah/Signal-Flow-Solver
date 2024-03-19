#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QBoxLayout>
#include <QLabel>
#include "../../headers/widgets/toolbar.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    ~MainWindow();

private:   
    QVBoxLayout *mainLayout;
    ToolBarWidget* toolbarWidget;
};
#endif // MAINWINDOW_H
