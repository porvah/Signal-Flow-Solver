#include "../../headers/widgets/output.h"

OutputWidget::OutputWidget(QWidget* parent)
    : QWidget(parent)
{
    setFixedWidth(250);

    QVBoxLayout* layout = new QVBoxLayout(this);

    outputTextEdit = new QTextEdit(this);
    outputTextEdit->setReadOnly(true);
    layout->addWidget(outputTextEdit);

    setLayout(layout);

    setStyleSheet("background-color: lightgray;");
}

void OutputWidget::updateText(std::map<std::string, std::vector<std::pair<std::string, double>>> mp)
{
    QString graph = convertGraphToString(mp);
    outputTextEdit->setText(graph);
}

QString OutputWidget::convertGraphToString(std::map<std::string, std::vector<std::pair<std::string, double>>> mp)
{
    QString text;
    text += "Graph: \n";
    for (auto const& x : mp)
    {
        text += x.first + ": ";
        for (int i = 0; i < mp[x.first].size(); i++) {
            text += "(" + mp[x.first][i].first + ", ";
            text += QString::number(mp[x.first][i].second, 'f', 2) + "),";

        }
        text += "\n";
    }

    return text;
}
