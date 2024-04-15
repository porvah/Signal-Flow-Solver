#include "../../headers/widgets/canvas.h"
#include <QPainter>
#include <QMouseEvent>
#include <string>
#include <QDebug>
#include <QString>
#include <iostream>
#include <QtMath>
#include <QtCore/qmath.h>
#include <QApplication>
#include <QScreen>
#include "../../core/headers/models/Graph.h"

CanvasWidget::CanvasWidget(QWidget *parent)
    : QWidget(parent)
{
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();
    int height = screenGeometry.height();
    int width = screenGeometry.width();
    setFixedWidth(width-250);
    setFixedHeight(height-100);
    this->gainInputDialog = new GainInputDialog();
    this->validationDialog = new ValidationDialog();
    this->clearandsetup();
}
int CanvasWidget::num = 0;
CanvasWidget::~CanvasWidget()
{

}

void CanvasWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painterptr = &painter;
    painter.save();
    QPen pen;
    QFont font;
    font.setPixelSize(15);
    font.bold();
    pen.setWidth(3);
    painter.setPen(pen);
    painter.setFont(font);
    for(int i = 0; i < arrows.size(); i++){
        this->drawArrow(arrows[i].first, arrows[i].second, &painter);
    }
    for(int i = 0; i < nodes.size(); i++){
        this->drawNode(nodes[i].second, nodes[i].first, &painter);
    }

    painter.restore();
    if(animationStarted == true) this->drawArrow(0, pair(this->animationStartPos, this->animationCurrentPos), &painter);

}

void CanvasWidget::mousePressEvent(QMouseEvent *event)
{
    QPoint p = this->mapFromGlobal(QCursor::pos());
    if(event->type()==QMouseEvent::MouseButtonPress && state == Node){
        string nodeName = this->searchForNode(this->mapFromGlobal(QCursor::pos()));
        this->addNode(p, "def");
    }else if(event->type()==QMouseEvent::MouseButtonPress && state == Arrow){
        mouseDownState = true;
        node1Name = this->searchForNode(this->mapFromGlobal(QCursor::pos()));
        if(node1Name != "none"){
            animationStartPos = this->getNodePos(node1Name);
            animationStarted = true;
        }else{
            animationStarted = false;
        }
    }
}

void CanvasWidget::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->type()==QMouseEvent::MouseButtonRelease && state == Arrow){
        string nodeName = this->searchForNode(this->mapFromGlobal(QCursor::pos()));
        if (nodeName != "none"){
            if(node1Name != "none"){
                node2Name = nodeName;
                QPoint pos1 = this->getNodePos(node1Name);
                QPoint pos2 = this->getNodePos(node2Name);
                gainInputDialog->clearField();
                int status = gainInputDialog->exec();
                if (status != 0){
                    double gain = gainInputDialog->getGain();
                    this->addArrow(gain, node1Name, node2Name, pair(pos1, pos2));
                }
            }
        }
        animationStarted = false;
    }
    mouseDownState = false;
    animationStarted = false;
    node1Name = "none";
    node2Name = "none";
    update();
}

void CanvasWidget::mouseMoveEvent(QMouseEvent *event)
{
    if(event->type()==QMouseEvent::MouseMove && state == Arrow && mouseDownState == true && animationStarted){
        QPoint currentPos = this->mapFromGlobal(QCursor::pos());
        this->animationCurrentPos = currentPos;
        update();
    }

}

string CanvasWidget::searchForNode(QPoint pos)
{
    string res = "none";
    for(int i = 0; i < nodes.size(); i++){
        if(abs(nodes[i].second.x() - pos.x()) <= 20 && abs(nodes[i].second.y() - pos.y()) <= 20 ){
            res = nodes[i].first;
            break;
        }
    }
    return res;
}

void CanvasWidget::addArrow(double gain, string node1, string node2, pair<QPoint, QPoint> fromTo)
{
    this->inputGraph[node1].push_back(pair(node2, gain));
    this->arrows.push_back(pair(gain, fromTo));
}

QPoint CanvasWidget::getNodePos(string name)
{
    QPoint dummy(0,0);
    for(int i = 0; i < nodes.size(); i++){
        if(nodes[i].first == name) return nodes[i].second;
    }
    return dummy;
}

bool CanvasWidget::firstValidation()
{
    for (auto const& x : inputGraph){
        if(x.first != "end"){
            if(x.second.size() == 0) return false;
        }
    }
    return true;
}

bool CanvasWidget::seconValidation(Graph core)
{
    vector<pair<path, double>> paths = core.getPaths();
    if(paths.size() == 0) return false;
    else return true;
}

void CanvasWidget::onNodeSelected()
{
    this->state = Node;
}

void CanvasWidget::onPathSelected()
{
    this->state = Arrow;
}

void CanvasWidget::onClearPressed()
{
    this->nodes.clear();
    this->arrows.clear();
    this->inputGraph.clear();
    this->clearandsetup();
}

void CanvasWidget::onStartSim()
{
    bool showDialog = false;
    if(this->firstValidation()){
        Graph core(inputGraph);
        core.CalculatePaths();
        if(this->seconValidation(core)){
            vector<pair<path, double>> paths = core.getPaths();
            core.CalculateLoops();
            map<string, pair<path, double>> loops = core.getLoops();
            core.CalculateNonTouched();
            vector<vector<pair<string, double>>> nonTouched = core.getNonTouched();
            core.CalculateDeltas();
            vector<pair<string, double>> deltas = core.getDeltas();
            core.CalculateDelta();
            double delta = core.getDelta();
            double tf = core.getSystemTransferFunction();
            emit sendOutputs(paths, loops, nonTouched, deltas, delta, tf);
        }else showDialog = true;
    }
    else showDialog = true;
    if(showDialog){
        this->validationDialog->setLabelText("Graph is Not valid");
        this->validationDialog->exec();
    }
}

void CanvasWidget::drawNode(QPoint position, string name, QPainter *painter)
{
    painter->drawEllipse(position.x()-10,position.y()-10,20,20);
    QString label = QString::fromStdString(name);
    QPoint labelPos(position.x()-10, position.y()+30);
    painter->drawText( labelPos, label);
}

void CanvasWidget::addNode(QPoint pos, string name)
{
    int id = nodeId++;
    string standard;
    string nodeName;
    if(name == "def"){
      standard = "y";
      nodeName = standard.append(to_string(id));
    }else{
      standard = name;
      nodeName = name;
    }
    vector<pair<string, double>> adjList;
    inputGraph[nodeName] = adjList;
    pair<string, QPoint> nodePair(nodeName, pos);
    nodes.push_back(nodePair);
}

void CanvasWidget::clearandsetup()
{
    node1Name = "none";
    node2Name = "none";

    state = None;
    qInfo("constructed");
    QPoint startPos;
    startPos.setX(50);
    startPos.setY(height()/2);
    QPoint endPos;
    endPos.setX(width()-50);
    endPos.setY(height()/2);
    this->addNode(startPos, "start");
    this->addNode(endPos, "end");
    nodeId = 1;
    update();
}

void CanvasWidget::drawArrow(double gain, pair<QPoint, QPoint> arrow, QPainter *painter)
{
    QPoint src = arrow.first;
    QPoint dist = arrow.second;
    bool ltr = (dist.x()-src.x() >= 0);
    int x,y,w,h,start,span;
    painter->save();
    double r = sqrt(pow((float)(dist.x()-src.x()), 2.0)+pow((float)(dist.y()-src.y()), 2.0));
    if(ltr){
      x = (int)(src.x() - 0.5*r);
      y = (int)(src.y() - (1-(sqrt(3.0)/2))*r);
      w = 2*r;
      h = 2*r;
      qDebug("%d", w);
      start = 120*16;
      span = -60*16;
    }else{
      x = (int)(src.x() - 1.5*r);
      y = (int)(src.y() - (1+(sqrt(3.0)/2))*r);
      w = 2*r;
      h = 2*r;
      start = -60*16;
      span = -60*16;
    }
    float deg = ltr? atan2(dist.y()-src.y(), dist.x()-src.x())*180/M_PI : atan2(src.y()-dist.y(), src.x()-dist.x())*180/M_PI;
    QLineF line1;
    QLineF line2;
    line1.setP1(dist);
    line2.setP1(dist);
    int len = ltr ? 30 : -30;
    line1.setAngle(180-deg);
    line2.setAngle(180-deg-60);
    line1.setLength(len);
    line2.setLength(len);
    painter->drawLine(line1);
    painter->drawLine(line2);
    QString label = QString::number(gain);
    QPoint labelPos(ltr? dist.x()-30 : dist.x()+30, ltr? dist.y()-30: dist.y()+30);
    painter->drawText( labelPos, label);
    painter->translate(src);
    painter->rotate(deg);
    painter->translate(-src);
    painter->drawArc(x,y,w,h, start, span);
    painter->restore();

}


