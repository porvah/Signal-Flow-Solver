#include "../../headers/windows/mainwindow.h"
#include <QWidget>
#include <QLayout>


MainWindow::MainWindow()
{
    QVBoxLayout *mainLayout = new QVBoxLayout;

    setLayout(mainLayout);
}

MainWindow::~MainWindow()
{
}

