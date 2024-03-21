#include "../../headers/widgets/canvas.h"
#include <QPainter>
#include <QMouseEvent>
#include <string>
#include <QDebug>
#include <QString>
#include <iostream>
#include <QtMath>
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
    painter.save();
    QPen pen;
    QFont font;
    font.setPixelSize(20);
    font.bold();
    pen.setWidth(4);
    painter.setPen(pen);
    painter.setFont(font);
    //painter.drawEllipse(200,200,1,1);
    painter.drawEllipse(700,200,1,1);
    painter.drawEllipse(200,700,1,1);
//    painter.drawEllipse(700,700,1,1);
    pair<QPoint,QPoint> temp;
    temp.first = QPoint(200,700);
    temp.second = QPoint(700,200);
    this->drawArrow(10, temp, &painter);
    painter.drawArc(QRect(200,200, 500, 500), 120*16, -60*16);
    for(int i = 0; i < nodes.size(); i++){
        this->drawNode(nodes[i].second, nodes[i].first, &painter);
    }
    painter.restore();

}

void CanvasWidget::prepareStartandEnd()
{

}

void CanvasWidget::mousePressEvent(QMouseEvent *event)
{
    if(event->type()==QMouseEvent::MouseButtonPress){
        num++;
        QPoint p = this->mapFromGlobal(QCursor::pos());
        this->addNode(p, "def");
    }
    update();
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
    QPoint center(x+r, y+r);
    painter->translate(center);
    painter->rotate(45);
    painter->translate(-center);
    painter->drawArc(x,y,w,h, start, span);
    painter->restore();

}
