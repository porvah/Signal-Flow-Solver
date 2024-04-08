#include "../../headers/windows/mainwindow.h"
#include "../../headers/widgets/toolbar.h"

#include <QWidget>
#include <QLayout>
#include <QToolBar>
#include <QApplication>
#include <QScreen>

MainWindow::MainWindow(QWidget *parent)
{
    this->prepareChildren();
    this->connectSignals();
}

void MainWindow::prepareChildren(){
    mainLayout = new QVBoxLayout();
    workspaceLayout = new QHBoxLayout();
    outputWidget = new OutputWidget();
    validationDialog = new ValidationDialog();
    gainInputDialog = new GainInputDialog();
    toolbarWidget = new ToolBarWidget(nullptr, outputWidget, validationDialog, gainInputDialog);
    workspace = new QWidget();
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();
    int width = screenGeometry.width();
    workspace->setFixedWidth(width);
    QWidget *centralWidget = new QWidget();
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);
    centralWidget->setFixedWidth(width);
    mainLayout->setSizeConstraint(QLayout::SetMaximumSize);
    mainLayout->addWidget(toolbarWidget);
    mainLayout->addWidget(workspace);
    canvas = new CanvasWidget(nullptr);
    workspaceLayout->addWidget(canvas);
    workspaceLayout->addWidget(outputWidget);
    workspace->setLayout(workspaceLayout);
}

void MainWindow::connectSignals()
{
    connect(this->toolbarWidget, &ToolBarWidget::selectNode, this->canvas, &CanvasWidget::onNodeSelected);
    connect(this->toolbarWidget, &ToolBarWidget::selectPath, this->canvas, &CanvasWidget::onPathSelected);
    connect(this->toolbarWidget, &ToolBarWidget::pressClear, this->canvas, &CanvasWidget::onClearPressed);
    connect(this->toolbarWidget, &ToolBarWidget::startSim, this->canvas, &CanvasWidget::onStartSim);
    connect(this->canvas, &CanvasWidget::sendOutputs, this->outputWidget, &OutputWidget::updateText);
}

MainWindow::~MainWindow()
{
}


