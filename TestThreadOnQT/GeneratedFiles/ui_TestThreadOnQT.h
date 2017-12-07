/********************************************************************************
** Form generated from reading UI file 'TestThreadOnQT.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTTHREADONQT_H
#define UI_TESTTHREADONQT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "imgview.h"

QT_BEGIN_NAMESPACE

class Ui_TestThreadOnQTClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QPushButton *btn_openThread;
    QPushButton *btn_closeThread;
    QPushButton *btnOpenCam;
    QPushButton *btnCloseCam;
    ImgView *image1;
    ImgView *image2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TestThreadOnQTClass)
    {
        if (TestThreadOnQTClass->objectName().isEmpty())
            TestThreadOnQTClass->setObjectName(QStringLiteral("TestThreadOnQTClass"));
        TestThreadOnQTClass->resize(873, 632);
        centralWidget = new QWidget(TestThreadOnQTClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        btn_openThread = new QPushButton(centralWidget);
        btn_openThread->setObjectName(QStringLiteral("btn_openThread"));

        gridLayout->addWidget(btn_openThread, 0, 0, 1, 1);

        btn_closeThread = new QPushButton(centralWidget);
        btn_closeThread->setObjectName(QStringLiteral("btn_closeThread"));

        gridLayout->addWidget(btn_closeThread, 0, 1, 1, 1);

        btnOpenCam = new QPushButton(centralWidget);
        btnOpenCam->setObjectName(QStringLiteral("btnOpenCam"));

        gridLayout->addWidget(btnOpenCam, 1, 0, 1, 1);

        btnCloseCam = new QPushButton(centralWidget);
        btnCloseCam->setObjectName(QStringLiteral("btnCloseCam"));

        gridLayout->addWidget(btnCloseCam, 1, 1, 1, 1);

        image1 = new ImgView(centralWidget);
        image1->setObjectName(QStringLiteral("image1"));
        image1->setAutoFillBackground(true);

        gridLayout->addWidget(image1, 2, 0, 1, 1);

        image2 = new ImgView(centralWidget);
        image2->setObjectName(QStringLiteral("image2"));
        image2->setAutoFillBackground(true);

        gridLayout->addWidget(image2, 2, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        TestThreadOnQTClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(TestThreadOnQTClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 873, 21));
        TestThreadOnQTClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TestThreadOnQTClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        TestThreadOnQTClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(TestThreadOnQTClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        TestThreadOnQTClass->setStatusBar(statusBar);

        retranslateUi(TestThreadOnQTClass);

        QMetaObject::connectSlotsByName(TestThreadOnQTClass);
    } // setupUi

    void retranslateUi(QMainWindow *TestThreadOnQTClass)
    {
        TestThreadOnQTClass->setWindowTitle(QApplication::translate("TestThreadOnQTClass", "TestThreadOnQT", 0));
        btn_openThread->setText(QApplication::translate("TestThreadOnQTClass", "Open Thread", 0));
        btn_closeThread->setText(QApplication::translate("TestThreadOnQTClass", "Close Thread", 0));
        btnOpenCam->setText(QApplication::translate("TestThreadOnQTClass", "Open Cam", 0));
        btnCloseCam->setText(QApplication::translate("TestThreadOnQTClass", "Close Cam", 0));
        image1->setText(QApplication::translate("TestThreadOnQTClass", "TextLabel", 0));
        image2->setText(QApplication::translate("TestThreadOnQTClass", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class TestThreadOnQTClass: public Ui_TestThreadOnQTClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTTHREADONQT_H
