#include "../../headers/windows/mainwindow.h"
#include "../../headers/widgets/toolbar.h"
#include "../../headers/widgets/workspace.h"

#include <QWidget>
#include <QLayout>
#include <QToolBar>


MainWindow::MainWindow(QWidget *parent)
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


