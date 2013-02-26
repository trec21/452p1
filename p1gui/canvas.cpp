#include "canvas.h"
#include <math.h>
#include <QDebug>

extern int axis_number;

#define _USE_MATH_DEFINES
/* Utils */
#define RAD_TO_DEG 180/M_PI
#define DEG_TO_RAD M_PI/180

/* Program Config */
#define NUM_LINKS 3
#define BASE_ANGLE 60
#define WIDTH 30
#define HEIGHT 5*WIDTH
#define PAINTER_RADIUS 16


Canvas::Canvas(QObject *parent) :
    QGraphicsScene(parent)
{

}


void Canvas::setUpAxes() {
    Axis * axis = NULL;
    for(int i=0; i < axes.size();i++){
        axis = axes[i];
        if (i < axes.size()-1)
            axis->nextAxis = axes[i+1];
        else
            axis->nextAxis = NULL;
    }
}

void Canvas::initialize() {
    painter = new Painter(0);
    painter->resize(width(), height());
    painter->move(-width()/2, 0);
    painter->setXOffset(width()/2);
    addWidget(painter);

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

    setUpAxes();


    for(int i=0; i< NUM_LINKS; i++) {
        Link* link = new Link();
        link->length = heights[i+1] - heights[i];

        link->ellipse = this->addEllipse(-WIDTH/2,heights[i],WIDTH,link->length,blackPen,blackBrush);
        link->ellipse->setTransformOriginPoint(0,heights[i]);

        link->frontAxis = axes[i+1];
        link->backAxis = axes[i];
        link->orientation = 0;

        links.push_back(link);
    }
}

void Canvas::setAxesList(QListWidget *list)
{
    axesList = list;
}


// Maybe i just need the final 3 points
// TODO get the points correctly
//void Canvas::update(vector<QPoint>* points) {
void Canvas::updateLinks(Link* _link, double _angle) {

    // There is four positions to keep track of:
    // targetBackJointPos
    // targetFrontJointPos
    // currentBackJointPos
    // currentFrontJointPos
    // BackJoint = i
    // FrontJoint = i+1
    // i = link number

    rotate_axis(_link->backAxis, _link->frontAxis, _angle, _link);

    QPointF targetBackJointPos;
    QPointF targetFrontJointPos;
    vector<QPointF> targetPoints;

    for(int i=0;i<axes.size() - 1;i++)
    {
        Axis* axis = axes[i];
        QPointF point (axis->loc_x, axis->loc_y);
        qDebug() << "Next X: " << axis->loc_x << "Next Y: " << axis->loc_y;
        targetPoints.push_back(point);
    }

    QPointF currentBackJointPos;
    QPointF currentFrontJointPos;
    QPointF shiftPoint(0,0);

    QBrush blackBrush(Qt::black);
    QPen blackPen(Qt::black);
    blackPen.setWidth(1);

    for(int i=0; i< NUM_LINKS; i++) {

        targetFrontJointPos = targetPoints[i+1];
        Link* link = links[i];

        currentBackJointPos = link->ellipse->mapToScene(link->ellipse->pos());

        delete link->ellipse;
        double angleX = targetFrontJointPos.x() - targetBackJointPos.x();
        double angleY = targetFrontJointPos.y() - targetBackJointPos.y();
        double angle = atan2(angleY,angleX) * RAD_TO_DEG - 90; // to degrees


        link->ellipse = this->addEllipse(-1*WIDTH/2,0, WIDTH,link->length,blackPen,blackBrush);
        link->ellipse->setRotation(angle);
        //link->ellipse->setTransformOriginPoint(targetPoints[i].x(), targetPoints[i].y());

        link->ellipse->setPos(targetFrontJointPos.x(),targetFrontJointPos.y());
    }

    /*

    Link* link;
    for(size_t i=0; i<links.size(); i++) {
        targetFrontJointPos = targetPoints[i+1];
        link = links[i];

        currentBackJointPos = link->ellipse->mapToScene(link->ellipse->pos());
        double angleX = targetFrontJointPos.x() - targetBackJointPos.x();
        double angleY = targetFrontJointPos.y() - targetBackJointPos.y();
        double angle = atan2(angleY,angleX) * RAD_TO_DEG - 90; // to degrees

        currentFrontJointPos = QPointF(link->length * sin(link->ellipse->rotation() * DEG_TO_RAD) + currentFrontJointPos.x(),
                                       link->length * cos(link->ellipse->rotation() * DEG_TO_RAD) + currentFrontJointPos.y());
        // Absolute in scene

        qDebug() << "CurrentFront: " << currentFrontJointPos << "CurrentBack: " <<  currentBackJointPos << "angle: " << angle;
        qDebug() << "TargetFront: " << targetFrontJointPos << "TargetBack: " <<  targetBackJointPos << '\n';

        // This works because of reasons
        //link->ellipse->setPos(shiftPoint);
        link->ellipse->moveBy(shiftPoint.x(), shiftPoint.y());
        link->ellipse->setRotation( angle);


        double shitfX = targetFrontJointPos.x() + -1*currentFrontJointPos.x()  ;
        double shitfY = targetFrontJointPos.y() + -1*currentFrontJointPos.y()  ;

        shiftPoint = QPointF(shitfX, shitfY);
        qDebug() << "Shift: " << shiftPoint << " FROM: " << link->ellipse->mapToScene(shiftPoint) << "\n\n";

        targetBackJointPos = targetFrontJointPos;
    }

*/

}

void Canvas::updateList(){
}


void Canvas::paint() {
    QBrush redBrush(Qt::red);
    QPen redPen(Qt::red);
    redPen.setWidth(2);
    this->addEllipse((int)links[2]->frontAxis->loc_x - PAINTER_RADIUS/2,(int)links[2]->frontAxis->loc_y - PAINTER_RADIUS/2, PAINTER_RADIUS,PAINTER_RADIUS,redPen,redBrush);

    //painter->addPoint((int)links[2]->frontAxis->loc_x, (int)links[2]->frontAxis->loc_y);
    //painter->update();
}


void Canvas::rotateCW()
{
    int linkNum = getAxis() - 1;
    updateLinks(links[linkNum], BASE_ANGLE);
}

void Canvas::rotateCCW()
{
    int linkNum = getAxis() - 1;
    updateLinks(links[linkNum], -1*BASE_ANGLE);
}

int Canvas::getAxis(){
    if(axesList->currentItem() == NULL)
        return 1;


    QString* qstr_axis_number = NULL;
    qstr_axis_number = new QString(axesList->currentItem()->text());

    int axis_number = qstr_axis_number->toInt();


    return axis_number;
}

void Canvas::rotate_axis(Axis* base_axis, Axis* rotated_axis, double degrees, Link* link)
{
   link->orientation = degrees;
   qDebug() << "Base Axis X:" << base_axis->loc_x << endl;
   qDebug() << "Base Axis Y:" << base_axis->loc_y << endl;
   qDebug() << "Y:" << base_axis->loc_y << endl;

   base_axis->rotate(rotated_axis, degrees);
}

