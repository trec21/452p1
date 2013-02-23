#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "canvas.h"
#include <QtGui>
#include <QDebug>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
/*
    QGraphicsScene *scene = new CustomScene;
            QGraphicsView *view = new QGraphicsView(this);
            scene->setSceneRect(-180, 180, 360, 180);
            view->setScene(scene);
            view->scale(1, -1);
            setCentralWidget(view);
*/

    Canvas* canvas = new Canvas(this);
    //canvas->setSceneRect(ui->graphicsView->width(), ui->graphicsView->height(), 0, 0);
    QRectF rect = ui->graphicsView->rect();

    // So this is my theory:
    // after messing around a bit with these things, it seems like the canvas origin is
    // the center by default, but you can modify it by positioning x and y correctly. Still y will
    // be positive downward, that's why i did the scale. Now we have the origin at the base :D

    rect.setX(-rect.width()/2 );
    rect.setY(0);
    rect.setWidth(ui->graphicsView->width()-10);
    rect.setHeight(ui->graphicsView->height()-10);

    canvas->setSceneRect(rect);
    ui->graphicsView->scale(1, -1);
    canvas->initialize();
    connect(ui->cwiseBtn, SIGNAL(clicked()), canvas, SLOT(updateLinks()));

    ui->graphicsView->setScene(canvas);


}

MainWindow::~MainWindow()
{
    delete ui;
}
