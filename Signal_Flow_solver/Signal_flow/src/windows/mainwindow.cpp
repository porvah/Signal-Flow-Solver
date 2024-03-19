#include "../../headers/windows/mainwindow.h"
#include <QWidget>
#include <QLayout>


MainWindow::MainWindow()
{
    mainLayout = new QVBoxLayout();
    outputWidget = new OutputWidget();
    toolbarWidget = new ToolBarWidget(nullptr, outputWidget);

    mainLayout->addWidget(toolbarWidget);

    mainLayout->addWidget(outputWidget, 0, Qt::AlignRight);

    QWidget *centralWidget = new QWidget();
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);
}

MainWindow::~MainWindow()
{
}

