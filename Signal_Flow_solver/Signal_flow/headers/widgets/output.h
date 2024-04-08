#ifndef OUTPUTWIDGET_H
#define OUTPUTWIDGET_H

#include <QWidget>
#include <QTextEdit>
#include <QVBoxLayout>
#include "../../core/headers/models/path.h"

using namespace std;

class OutputWidget: public QWidget
{
    Q_OBJECT

public:
    explicit OutputWidget(QWidget* parent = nullptr);

public slots:
    void updateText(vector<pair<path, double>> paths, map<string, pair<path, double>> loops,
                    vector<vector<pair<string, double>>> nonTouched, vector<pair<string, double>> deltas,
                    double delta, double tf);

private:
    QTextEdit* outputTextEdit;

private:
    QString convertGraphToString(vector<pair<path, double>> paths, map<string, pair<path, double>> loops,
                                 vector<vector<pair<string, double>>> nonTouched, vector<pair<string, double>> deltas,
                                 double delta, double tf);
};

#endif
