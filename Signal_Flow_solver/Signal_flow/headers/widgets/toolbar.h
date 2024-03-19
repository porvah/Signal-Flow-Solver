#include <QWidget>
#include <QToolBar>
#include <QPushButton>
#include <string>

class ToolBarWidget : public QToolBar
{
    Q_OBJECT

public:
    explicit ToolBarWidget(QWidget* parent = nullptr);

    std::string getChosenButton();

private:
    std::string chosenButton;
    QPushButton* chooseNode;
    QPushButton* choosePath;
    QPushButton* clear;
    QPushButton* simulate;
};
