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

    setStyleSheet("background-color: lightgray; font-size:14px");
}

void OutputWidget::updateText(vector<pair<path, double>> paths, map<string, pair<path, double>> loops,
                              vector<vector<pair<string, double>>> nonTouched, vector<pair<string, double>> deltas,
                              double delta, double tf)
{
    QString graph = convertGraphToString(paths, loops, nonTouched, deltas, delta, tf);
    outputTextEdit->setText(graph);
}

QString OutputWidget::convertGraphToString(vector<pair<path, double>> paths, map<string, pair<path, double>> loops,
                                           vector<vector<pair<string, double>>> nonTouched, vector<pair<string, double>> deltas,
                                           double delta, double tf)
{
    QString text;
    text += "Graph: \n";

    text += "Forward Paths:\n";
    for (int i = 0; i < paths.size(); i++) {
        for (int j = 0; j < paths[i].first.getNodes().size(); j++) {
            text += paths[i].first.getNodes()[j] + ",";
        }
        text += QString::number(paths[i].second) + "\n";
    }
    text += "Loops:\n";
    for (auto const& x : loops)
    {
        text += x.first + ':';
        for (int i = 0; i < loops [x.first].first.getNodes().size() ; i++) {
            text += loops[x.first].first.getNodes()[i] + ",";
        }
        text += "gain =" + QString::number(loops[x.first].second);
        text += "\n";
    }
    text += "Nontouched Loops:\n";
    for (int i=0;i<nonTouched.size();i++)
    {
        for (int j = 0; j < nonTouched[i].size(); j++) {
            text += nonTouched[i][j].first +':';
            text += "gain =" + QString::number(nonTouched[i][j].second);
            text += "\n";
        }
    }
    text += "Deltas:\n";
    for (int i = 0; i < deltas.size(); i++) {
        text += deltas[i].first + "=";
        text += QString::number(deltas[i].second) +"\n";
    }
    text += "Delta=";
    text += QString::number(delta)+"\n";
    text += "Transfer Function ="+ QString::number(tf);


    return text;
}
