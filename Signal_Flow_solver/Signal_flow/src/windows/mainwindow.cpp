#include "../../headers/windows/mainwindow.h"
#include <QWidget>
#include <QLayout>


MainWindow::MainWindow()
{
    mainLayout = new QVBoxLayout();
    toolbarWidget = new ToolBarWidget();

    mainLayout->addWidget(toolbarWidget);

    QLabel *label = new QLabel("");
    mainLayout->addWidget(label);

    QWidget *centralWidget = new QWidget();
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);
}

MainWindow::~MainWindow()
{
}

