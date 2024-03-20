#include "../../headers/windows/mainwindow.h"
#include "../../headers/widgets/toolbar.h"

#include <QWidget>
#include <QLayout>
#include <QToolBar>


MainWindow::MainWindow(QWidget *parent)
{
    this->prepareChildren();

}

void MainWindow::prepareChildren(){
    mainLayout = new QVBoxLayout();
    workspaceLayout = new QHBoxLayout();
    outputWidget = new OutputWidget();
    toolbarWidget = new ToolBarWidget(nullptr, outputWidget);
    workspace = new QWidget();
    canvas = new CanvasWidget();
    mainLayout->addWidget(toolbarWidget);
    mainLayout->addWidget(workspace);
    workspaceLayout->addWidget(canvas);
    workspaceLayout->addWidget(outputWidget, 0, Qt::AlignRight);
    workspace->setLayout(workspaceLayout);
    QWidget *centralWidget = new QWidget();
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);
}

MainWindow::~MainWindow()
{
}


