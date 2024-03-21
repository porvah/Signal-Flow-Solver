#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <vector>
#include <map>
#include <string>
#include <QPair>
using namespace std;

enum Selected {None, Node, Arrow};

class CanvasWidget : public QWidget
{
    Q_OBJECT
public:
    CanvasWidget(QWidget* parent);
    ~CanvasWidget();


protected:
    void paintEvent(QPaintEvent*);

private:
    Selected state;
    map<string, vector<pair<string, double>>> inputGraph;
    vector<pair<string, QPoint>> nodes;
    vector<pair<double, pair<QPoint,QPoint>>> arrows;
    static int num;
    int nodeId;
    void prepareStartandEnd();
    void mousePressEvent(QMouseEvent *event);
    void drawNode(QPoint position, string name, QPainter *painter);
    void addNode(QPoint pos, string name);
    void clearandsetup();
    void drawArrow(double gain, pair<QPoint,QPoint> arrow, QPainter *painter);

};

#endif
