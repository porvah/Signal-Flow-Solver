#include "../../headers/windows/mainwindow.h"
#include "../../headers/widgets/toolbar.h"
#include "../../headers/widgets/workspace.h"

#include <QWidget>
#include <QLayout>
#include <QToolBar>


MainWindow::MainWindow(QWidget *parent)
{
//    QVBoxLayout *mainLayout = new QVBoxLayout;
    //makeToolbar();
    ToolBarWidget *toolbar = new ToolBarWidget();

    //addToolBar(toolbar);
//    ToolBarWidget *toolbar = new ToolBarWidget;
//    WorkspaceWidget *workspace = new WorkspaceWidget;
//    mainLayout->addWidget(toolbar);
//    mainLayout->addWidget(workspace);

//    setLayout(mainLayout);
}

void MainWindow::makeToolbar(){



}

MainWindow::~MainWindow()
{
}


