#ifndef OUTPUTWIDGET_H
#define OUTPUTWIDGET_H

#include <QWidget>
#include <QTextEdit>
#include <QVBoxLayout>

class OutputWidget: public QWidget
{
    Q_OBJECT

public:
    explicit OutputWidget(QWidget* parent = nullptr);

public slots:
    void updateText(std::map<std::string, std::vector<std::pair<std::string, double>>> mp);

private:
    QTextEdit* outputTextEdit;

private:
    QString convertGraphToString(std::map<std::string, std::vector<std::pair<std::string, double>>> mp);
};

#endif
