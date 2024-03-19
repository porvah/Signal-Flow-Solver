#include "../../headers/widgets/toolbar.h"
#include <map>
#include <string>
#include <vector>

ToolBarWidget::ToolBarWidget(QWidget* parent, OutputWidget* outputWidget)
    : QToolBar(parent), outputWidgetRef(outputWidget)
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

        std::map<std::string, std::vector<std::pair<std::string, double>>> mp;
        mp["start"].push_back({"y2", 1});
        mp["y2"].push_back({"y3", 5});
        mp["y2"].push_back({"y6",10});
        mp["y3"].push_back({"y4", 10});
        mp["y4"].push_back({"y3", -1});
        mp["y4"].push_back({"y5", 2});
        mp["y5"].push_back({"y4", -2});
        mp["y5"].push_back({"y2", -1});
        mp["y5"].push_back({"end", 1});
        mp["y6"].push_back({"y5", 2});
        mp["y6"].push_back({"y6", -1});

        outputWidget->updateText(mp);
    });
}

std::string ToolBarWidget::getChosenButton()
{
    return chosenButton.toStdString();
}
