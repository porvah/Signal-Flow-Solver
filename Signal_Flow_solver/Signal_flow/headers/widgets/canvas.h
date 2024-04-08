#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <vector>
#include <map>
#include <string>
#include <QPair>
#include "./gain_input_dialog.h"
#include "./validation_dialog.h"
#include "../../core/headers/models/Graph.h"

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
    bool mouseDownState;
    string node1Name;
    string node2Name;
    QPoint animationStartPos;
    bool animationStarted;
    map<string, vector<pair<string, double>>> inputGraph;
    vector<pair<string, QPoint>> nodes;
    vector<pair<double, pair<QPoint,QPoint>>> arrows;
    QPainter*painterptr;
    static int num;
    int nodeId;
    GainInputDialog* gainInputDialog;
    ValidationDialog* validationDialog;
    void clearandsetup();
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void drawNode(QPoint position, string name, QPainter *painter);
    void addNode(QPoint pos, string name);
    void drawArrow(double gain, pair<QPoint,QPoint> arrow, QPainter *painter);
    void addArrow(double gain, string node1, string node2, pair<QPoint, QPoint> fromTo);
    string searchForNode(QPoint pos);
    QPoint getNodePos(string name);
    bool firstValidation();
    bool seconValidation(Graph core);
public slots:
    void onNodeSelected();
    void onPathSelected();
    void onClearPressed();
    void onStartSim();
signals:
    void sendOutputs(vector<pair<path, double>> paths, map<string, pair<path, double>> loops,
        vector<vector<pair<string, double>>> nonTouched, vector<pair<string, double>> deltas,
        double delta, double tf);

};

#endif
