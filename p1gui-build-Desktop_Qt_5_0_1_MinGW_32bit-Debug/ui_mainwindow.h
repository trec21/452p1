/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QFrame *robotAreaFrm;
    QGraphicsView *graphicsView;
    QFrame *controlPanelFrm;
    QPushButton *ccwiseBtn;
    QPushButton *cwiseBtn;
    QLabel *axisLbl;
    QPushButton *paintBtn;
    QListWidget *axisList;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        robotAreaFrm = new QFrame(centralWidget);
        robotAreaFrm->setObjectName(QStringLiteral("robotAreaFrm"));
        robotAreaFrm->setGeometry(QRect(10, 10, 611, 471));
        robotAreaFrm->setFrameShape(QFrame::StyledPanel);
        robotAreaFrm->setFrameShadow(QFrame::Raised);
        graphicsView = new QGraphicsView(robotAreaFrm);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 611, 471));
        controlPanelFrm = new QFrame(centralWidget);
        controlPanelFrm->setObjectName(QStringLiteral("controlPanelFrm"));
        controlPanelFrm->setGeometry(QRect(630, 10, 131, 311));
        controlPanelFrm->setFrameShape(QFrame::StyledPanel);
        controlPanelFrm->setFrameShadow(QFrame::Raised);
        ccwiseBtn = new QPushButton(controlPanelFrm);
        ccwiseBtn->setObjectName(QStringLiteral("ccwiseBtn"));
        ccwiseBtn->setGeometry(QRect(30, 160, 75, 41));
        cwiseBtn = new QPushButton(controlPanelFrm);
        cwiseBtn->setObjectName(QStringLiteral("cwiseBtn"));
        cwiseBtn->setGeometry(QRect(30, 100, 75, 41));
        axisLbl = new QLabel(controlPanelFrm);
        axisLbl->setObjectName(QStringLiteral("axisLbl"));
        axisLbl->setGeometry(QRect(30, 50, 31, 16));
        paintBtn = new QPushButton(controlPanelFrm);
        paintBtn->setObjectName(QStringLiteral("paintBtn"));
        paintBtn->setGeometry(QRect(30, 230, 75, 61));
        axisList = new QListWidget(controlPanelFrm);
        new QListWidgetItem(axisList);
        new QListWidgetItem(axisList);
        new QListWidgetItem(axisList);
        axisList->setObjectName(QStringLiteral("axisList"));
        axisList->setGeometry(QRect(70, 30, 21, 61));
        MainWindow->setCentralWidget(centralWidget);
        controlPanelFrm->raise();
        robotAreaFrm->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        ccwiseBtn->setText(QApplication::translate("MainWindow", "Counter\n"
"Clockwise", 0));
        cwiseBtn->setText(QApplication::translate("MainWindow", "Clockwise", 0));
        axisLbl->setText(QApplication::translate("MainWindow", "Axis:", 0));
        paintBtn->setText(QApplication::translate("MainWindow", "Paint!", 0));

        const bool __sortingEnabled = axisList->isSortingEnabled();
        axisList->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = axisList->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("MainWindow", "1", 0));
        QListWidgetItem *___qlistwidgetitem1 = axisList->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("MainWindow", "2", 0));
        QListWidgetItem *___qlistwidgetitem2 = axisList->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("MainWindow", "3", 0));
        axisList->setSortingEnabled(__sortingEnabled);

    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
