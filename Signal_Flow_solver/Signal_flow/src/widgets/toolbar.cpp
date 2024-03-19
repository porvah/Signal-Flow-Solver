#include "../../headers/widgets/toolbar.h"

ToolBarWidget::ToolBarWidget(QWidget* parent)
    : QToolBar(parent)
{
    setStyleSheet("background-color: #5d8aa8;");

    chooseNode = new QPushButton("&Node", this);
    chooseNode->setIcon(QIcon(QPixmap(":/images/new-moon.png")));
    chooseNode->setIconSize(QSize(32, 32));

    choosePath = new QPushButton("&Path", this);
    choosePath->setIcon(QIcon(QPixmap(":/images/right-arrow.png")));
    choosePath->setIconSize(QSize(32, 32));

    clear = new QPushButton("&Clear", this);
    clear->setIcon(QIcon(":/images/trash-can.png"));
    clear->setIconSize(QSize(32, 32));

    simulate = new QPushButton("&Simulate", this);
    simulate->setIcon(QIcon(":/images/play.png"));
    simulate->setIconSize(QSize(32, 32));

    chosenLabel = new QLabel("None", this);
    chosenLabel->setStyleSheet("background-color: white; color: black; margin: 0 0 0 50px; padding: 10px; width: 50px");

    addWidget(chooseNode);
    addWidget(choosePath);
    addWidget(clear);
    addWidget(simulate);
    addWidget(chosenLabel);

    connect(chooseNode, &QPushButton::clicked, [=]() {
        chosenButton = "NODE_PRESSED";
        chosenLabel->setText(chosenButton);
    });

    connect(choosePath, &QPushButton::clicked, [=]() {
        chosenButton = "PATH_PRESSED";
        chosenLabel->setText(chosenButton);
    });

    connect(clear, &QPushButton::clicked, [=]() {
        chosenButton = "CLEAR_PRESSED";
        chosenLabel->setText(chosenButton);
    });

    connect(simulate, &QPushButton::clicked, [=]() {
        chosenButton = "SIMULATION_PRESSED";
        chosenLabel->setText(chosenButton);
    });
}

std::string ToolBarWidget::getChosenButton()
{
    return chosenButton.toStdString();
}
