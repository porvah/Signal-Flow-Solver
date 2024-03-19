#ifndef TOOLBARWIDGET_H
#define TOOLBARWIDGET_H

#include <QWidget>
#include <QToolBar>
#include <QPushButton>
#include <QLabel>

class ToolBarWidget : public QToolBar
{
    Q_OBJECT

public:
    explicit ToolBarWidget(QWidget* parent = nullptr);

    std::string getChosenButton();

private:
    QString chosenButton;
    QPushButton* chooseNode;
    QPushButton* choosePath;
    QPushButton* clear;
    QPushButton* simulate;
    QLabel* chosenLabel;
};

#endif
