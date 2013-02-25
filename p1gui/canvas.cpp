#include "canvas.h"
#include <math.h>
#include <QDebug>

extern int axis_number;

#define _USE_MATH_DEFINES

int NUM_LINKS = 3;
int WIDTH = 30;
int HEIGHT = 5*WIDTH;
double RAD_TO_DEG = 180 / M_PI;
double DEG_TO_RAD = M_PI / 180;

Canvas::Canvas(QObject *parent) :
    QGraphicsScene(parent)
{

}

void Canvas::initialize() {
    painter = new Painter(0);
    painter->resize(width(), height());
    painter->move(-width()/2, 0);
    struct QGraphicsProxyWidget *proxy = addWidget(painter);

    QBrush blackBrush(Qt::black);
    QPen blackPen(Qt::black);
    blackPen.setWidth(1);

    Axis* axis;
    vector<double> heights;
    for(int i=0; i< NUM_LINKS+1; i++) {

        if (i==0) {
            axis = new Axis(0, 0);
            heights.push_back(0);
        } else if(i==1) {
            axis = new Axis(0, 150);
            heights.push_back(150);
        } else if (i==2) {
            axis = new Axis(0, 250);
            heights.push_back(250);
        } else if (i==3) {
            axis = new Axis(0, 325);
            heights.push_back(325);
        }
        axes.push_back(axis);
    }


    Link* link = new Link();

    for(int i=0; i< NUM_LINKS; i++) {
        link->length = heights[i+1] - heights[i];

        link->ellipse = this->addEllipse(-WIDTH/2,heights[i],WIDTH,link->length,blackPen,blackBrush);
        link->ellipse->setTransformOriginPoint(0,heights[i]);

        link->frontAxis = axes[i+1];
        link->backAxis = axes[i];

        links.push_back(link);
    }
}

// Maybe i just need the final 3 points
// TODO get the points correctly
//void Canvas::update(vector<QPoint>* points) {
void Canvas::updateLinks() {

    // There is four positions to keep track of:
    // targetBackJointPos
    // targetFrontJointPos
    // currentBackJointPos
    // currentFrontJointPos
    // BackJoint = i
    // FrontJoint = i+1
    // i = link number

    axes[0]->rotate(axes[1], 10);

    QPointF targetBackJointPos;
    QPointF targetFrontJointPos;
    targetBackJointPos.setX(0);
    targetBackJointPos.setY(0);
    vector<QPointF> targetPoints;
    targetPoints.push_back(targetFrontJointPos);

    for(int i=0;i<links.size();i++)
    {
        Link* link = links[i];
        QPointF point (link->getNextAxisPoint()[0], link->getNextAxisPoint()[1]);
        targetPoints.push_back(point);
    }
/*
    targetFrontJointPos.setX(106);
    targetFrontJointPos.setY(106);
    targetPoints.push_back(targetFrontJointPos);

    targetFrontJointPos.setX(106);
    targetFrontJointPos.setY(150 + 106);
    targetPoints.push_back(targetFrontJointPos);

    targetFrontJointPos.setX(0);
    targetFrontJointPos.setY(150 + 106 + 106);
    targetPoints.push_back(targetFrontJointPos);
*/
    QPointF currentBackJointPos;
    QPointF currentFrontJointPos;
    QPointF shiftPoint(0,0);

    Link* link;
    for(size_t i=0; i<links.size(); i++) {
        targetFrontJointPos = targetPoints[i];
        link = links[i];

        currentBackJointPos = link->ellipse->mapToScene(link->ellipse->pos());
        double angleX = targetFrontJointPos.x() - targetBackJointPos.x();
        double angleY = targetFrontJointPos.y() - targetBackJointPos.y();
        double angle = atan2(angleY,angleX) * RAD_TO_DEG; // to degrees

        currentFrontJointPos = QPointF(HEIGHT * sin(link->ellipse->rotation() * DEG_TO_RAD) + currentFrontJointPos.x(),
                                       HEIGHT * cos(link->ellipse->rotation() * DEG_TO_RAD) + currentFrontJointPos.y());
        // Absolute in scene

        qDebug() << "CurrentFront: " << currentFrontJointPos << "CurrentBack: " <<  currentBackJointPos << "angle: " << angle;
        qDebug() << "TargetFront: " << currentFrontJointPos << "TargetBack: " <<  currentBackJointPos << '\n';

        /* This works because of reasons */
        //link->setTransform(QTransform().translate(center.x(), center.y()));
        //link->setPos(center);
        link->ellipse->setPos(shiftPoint);
        // link->setTransformOriginPoint(shiftPoint);
        link->ellipse->setRotation(angle);
        //link->setTransform(QTransform().translate(-center.x(), -center.y()));


        double shitfX = -1*currentFrontJointPos.x() + targetFrontJointPos.x() ;
        double shitfY = -1*currentFrontJointPos.y() + targetFrontJointPos.y() ;

        shiftPoint = QPointF(shitfX, shitfY);
        qDebug() << "Shift: " << shiftPoint << " FROM: " << link->ellipse->mapToScene(shiftPoint) << "\n\n";

        targetBackJointPos = targetFrontJointPos;
    }
}

void Canvas::updateList(){
}

void Canvas::paint() {
    qDebug() << "ABOUT TO PAINT\n";
    int size = links.size();
    int x = links[3]->frontAxis->loc_x;
    int y = links[3]->frontAxis->loc_y;
    painter->addPoint((int)links[3]->frontAxis->loc_x, (int)links[3]->frontAxis->loc_y);
    painter->update();
}


void Canvas::getAxis(){
    updateLinks();
    int neww = axis_number;
}

