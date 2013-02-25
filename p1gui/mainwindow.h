#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include "ui_mainwindow.h"




class CustomScene : public QGraphicsScene
{
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event)
    {
        qDebug() << event->scenePos();
    }
};

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void on_axisList_itemClicked(QListWidgetItem *item);
    //void on_paintBtn_clicked(QPushButton *item);
    
private:
    Ui::MainWindow *ui;
    QGraphicsScene* scene;
};

#endif // MAINWINDOW_H
