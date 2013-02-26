#include "mainwindow.h"
//#include "ui_mainwindow.h"
#include "canvas.h"
#include <QtGui>
#include <QDebug>

extern int axis_number;

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    axis_number = 0;
    ui->setupUi(this);

    Canvas* canvas = new Canvas(this);
    canvas->setParent(this);
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

    ui->axisList->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->axisList->item(0)->setSelected(true);
    canvas->setAxesList( ui->axisList);
    canvas->initialize();

    connect(ui->cwiseBtn, SIGNAL(clicked()), canvas, SLOT(rotateCW()));
    connect(ui->ccwiseBtn, SIGNAL(clicked()), canvas, SLOT(rotateCCW()));
    // connect(ui->axisList, SIGNAL(clicked(QModelIndex)), canvas, SLOT(updateList()));

    ui->graphicsView->setScene(canvas);


}

void MainWindow::on_axisList_itemClicked(QListWidgetItem *item)
{
    QString qstr_axis_number =0;
    qstr_axis_number = item->text();
    axis_number = qstr_axis_number.toInt();
    qDebug()<<"hey this is the AXIS NUMBER!!!!!"<<axis_number<<endl;
}

MainWindow::~MainWindow()
{
    delete ui;
}
