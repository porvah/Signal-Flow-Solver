#include "../../headers/widgets/canvas.h"
#include <QPainter>
#include <QMouseEvent>
#include <string>
#include <QDebug>
#include <QString>
#include <iostream>
#include <QtMath>
#include <QtCore/qmath.h>
CanvasWidget::CanvasWidget(QWidget *parent)
    : QWidget(parent)
{
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
    pair<QPoint,QPoint> temp;
    temp.second = QPoint(300,700);
    temp.first = QPoint(500,700);
    this->drawArrow(10, temp, &painter);
    for(int i = 0; i < nodes.size(); i++){
        this->drawNode(nodes[i].second, nodes[i].first, &painter);
    }
    painter.restore();
    for(int i = 0; i < arrows.size(); i++){
        this->drawArrow(arrows[i].first, arrows[i].second, &painter);
    }
}

void CanvasWidget::mousePressEvent(QMouseEvent *event)
{
    QPoint p = this->mapFromGlobal(QCursor::pos());
    if(event->type()==QMouseEvent::MouseButtonPress && state == Node){
        this->addNode(p, "def");
    }else if(event->type()==QMouseEvent::MouseButtonPress && state == Arrow){
        mouseDownState = true;
        node1Name = this->searchForNode(this->mapFromGlobal(QCursor::pos()));
        if(node1Name != "none"){
            animationStartPos = this->getNodePos(node1Name);
        }
        // test here <----------------------------------------------------------------------------------------------------
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
                // get gain from dialog <--------------------------------------------------------------------------------
                double gain = 101;
                this->addArrow(gain, node1Name, node2Name, pair(pos1, pos2));
            }
        }
    }
    mouseDownState = false;
    node1Name = "none";
    node2Name = "none";
    update();
}

void CanvasWidget::mouseMoveEvent(QMouseEvent *event)
{
    update();
    if(event->type()==QMouseEvent::MouseMove && state == Arrow && mouseDownState == true){
        this->drawArrow(0, pair(animationStartPos, this->mapFromGlobal(QCursor::pos())), painterptr);
        // test here <----------------------------------------------------------------------------------------------------
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
    nodeId = 1;
    state = None;
    qInfo("constructed");
    QPoint startPos;
    startPos.setX(50);
    startPos.setY(height());
    QPoint endPos;
    endPos.setX(2.5*width()-50);
    endPos.setY(height());
    this->addNode(startPos, "start");
    this->addNode(endPos, "end");
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
    // The day I wrote this code only me and God knew how it worked
    // Now only God knows
    // Please don't try to edit
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


