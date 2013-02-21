#include "canvas.h"
#include <math.h>
#include <QDebug>

#define _USE_MATH_DEFINES

int NUM_LINKS = 3;
int WIDTH = 30;
int HEIGHT = 5*WIDTH;

Canvas::Canvas(QObject *parent) :
    QGraphicsScene(parent)
{



}

void Canvas::initialize() {
    QBrush blackBrush(Qt::black);
    QPen blackPen(Qt::black);
    blackPen.setWidth(1);
    Link* link;
    QRectF rect = this->sceneRect();
    double heightCanvas = rect.height();
    double widthCanvas = rect.width();
    printf("height: %f, width: %f", heightCanvas, widthCanvas);

    for(int i=0; i< NUM_LINKS; i++) {
        link = static_cast <Link*>(this->addEllipse(0,0,WIDTH,HEIGHT,blackPen,blackBrush));
        link->setTransformOriginPoint(WIDTH/2,HEIGHT/2);
        // this works because of reasons
        link->setY(HEIGHT*i);

        links.push_back(link);
    }
}

// Maybe i just need the final 3 points
// TODO get the points correctly
//void Canvas::update(vector<QPoint>* points) {
void Canvas::updateLinks() {

    // previousJoint starts as the origin
    QPoint previousJoint;
    QPoint currentJoint;
    previousJoint.setX(0);
    previousJoint.setY(0);
    currentJoint.setX(0);
    currentJoint.setY(-106);
    double midX = (previousJoint.x() + currentJoint.x())/2;
    double midY = (previousJoint.y() + currentJoint.y())/2;
    QPoint center(midX, midY);
    double angle = -atan2(midY,midX) * 180 / M_PI; // to degrees

    Link* link;
    for(size_t i=0; i<links.size(); i++) {
        link = links[i];
        qDebug() << "Before: " << link->rect();

        /* This works because of reasons */
        //link->setTransform(QTransform().translate(center.x(), center.y()));

        link->setRotation(link->rotation() - 1);

        //link->setTransform(QTransform().translate(-center.x(), -center.y()));

        qDebug() << "After: " << link->rect() << link->rotation() << link->transformOriginPoint();


    }


}
