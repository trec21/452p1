#include "Utils.h"
#include "mainwindow.h"

#include <QApplication>
#include <iostream>

using namespace std;
int axis_number;

int main(int argc, char *argv[])
{
    axis_number = 0;
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
