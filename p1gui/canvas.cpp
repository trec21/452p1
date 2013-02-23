#include "canvas.h"
#include <math.h>
#include <QDebug>

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
    QBrush blackBrush(Qt::black);
    QPen blackPen(Qt::black);
    blackPen.setWidth(1);
    Link* link;

    for(int i=0; i< NUM_LINKS; i++) {
        link = static_cast <Link*>(this->addEllipse(-WIDTH/2,HEIGHT*i,WIDTH,HEIGHT,blackPen,blackBrush));
        link->setTransformOriginPoint(0,HEIGHT*i);

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

    QPointF targetBackJointPos;
    QPointF targetFrontJointPos;
    targetBackJointPos.setX(0);
    targetBackJointPos.setY(0);
    vector<QPointF> targetPoints;
    targetFrontJointPos.setX(106);
    targetFrontJointPos.setY(106);
    targetPoints.push_back(targetFrontJointPos);

    targetFrontJointPos.setX(106);
    targetFrontJointPos.setY(150 + 106);
    targetPoints.push_back(targetFrontJointPos);

    targetFrontJointPos.setX(0);
    targetFrontJointPos.setY(150 + 106 + 106);
    targetPoints.push_back(targetFrontJointPos);

    QPointF currentBackJointPos;
    QPointF currentFrontJointPos;
    QPointF shiftPoint(0,0);

    Link* link;
    for(size_t i=0; i<links.size(); i++) {
        targetFrontJointPos = targetPoints[i];
        link = links[i];

        currentBackJointPos = link->mapToScene(link->pos());
        double angleX = targetFrontJointPos.x() - targetBackJointPos.x();
        double angleY = targetFrontJointPos.y() - targetBackJointPos.y();
        double angle = atan2(angleY,angleX) * RAD_TO_DEG - 90; // to degrees

        currentFrontJointPos = QPointF(HEIGHT * sin(link->rotation() * DEG_TO_RAD) + currentFrontJointPos.x(), HEIGHT * cos(link->rotation() * DEG_TO_RAD) + currentFrontJointPos.y());
        // Absolute in scene

        qDebug() << "Front: " << currentFrontJointPos << "Back: " <<  currentBackJointPos << "angle: " << angle;

        /* This works because of reasons */
        //link->setTransform(QTransform().translate(center.x(), center.y()));
        //link->setPos(center);
        link->setPos(shiftPoint);
        // link->setTransformOriginPoint(shiftPoint);
        if(i !=1)
            link->setRotation(angle);
        else
            link->setRotation(00);
        //link->setTransform(QTransform().translate(-center.x(), -center.y()));


        double shitfX = -1*currentFrontJointPos.x() + targetFrontJointPos.x() ;
        double shitfY = -1*currentFrontJointPos.y() + targetFrontJointPos.y() ;

        shiftPoint = QPointF(shitfX, shitfY);
        qDebug() << "Shift: " << shiftPoint << " FROM: " << link->mapToScene(shiftPoint);

        targetBackJointPos = targetFrontJointPos;
    }

}

