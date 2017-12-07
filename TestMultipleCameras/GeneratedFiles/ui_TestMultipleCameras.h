/********************************************************************************
** Form generated from reading UI file 'TestMultipleCameras.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTMULTIPLECAMERAS_H
#define UI_TESTMULTIPLECAMERAS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <imgview.h>

QT_BEGIN_NAMESPACE

class Ui_TestMultipleCamerasClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QSplitter *splitter;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QPushButton *btnShowRoi;
    QPushButton *btnShowImage;
    QPushButton *btnCloseCam;
    QPushButton *btnOpenCam;
    ImgView *label;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TestMultipleCamerasClass)
    {
        if (TestMultipleCamerasClass->objectName().isEmpty())
            TestMultipleCamerasClass->setObjectName(QStringLiteral("TestMultipleCamerasClass"));
        TestMultipleCamerasClass->resize(622, 443);
        centralWidget = new QWidget(TestMultipleCamerasClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Vertical);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        btnShowRoi = new QPushButton(layoutWidget);
        btnShowRoi->setObjectName(QStringLiteral("btnShowRoi"));

        gridLayout->addWidget(btnShowRoi, 1, 1, 1, 1);

        btnShowImage = new QPushButton(layoutWidget);
        btnShowImage->setObjectName(QStringLiteral("btnShowImage"));

        gridLayout->addWidget(btnShowImage, 1, 0, 1, 1);

        btnCloseCam = new QPushButton(layoutWidget);
        btnCloseCam->setObjectName(QStringLiteral("btnCloseCam"));

        gridLayout->addWidget(btnCloseCam, 0, 1, 1, 1);

        btnOpenCam = new QPushButton(layoutWidget);
        btnOpenCam->setObjectName(QStringLiteral("btnOpenCam"));

        gridLayout->addWidget(btnOpenCam, 0, 0, 1, 1);

        splitter->addWidget(layoutWidget);
        label = new ImgView(splitter);
        label->setObjectName(QStringLiteral("label"));
        label->setAutoFillBackground(true);
        splitter->addWidget(label);

        gridLayout_2->addWidget(splitter, 0, 0, 1, 1);

        TestMultipleCamerasClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(TestMultipleCamerasClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 622, 21));
        TestMultipleCamerasClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TestMultipleCamerasClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        TestMultipleCamerasClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(TestMultipleCamerasClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        TestMultipleCamerasClass->setStatusBar(statusBar);

        retranslateUi(TestMultipleCamerasClass);

        QMetaObject::connectSlotsByName(TestMultipleCamerasClass);
    } // setupUi

    void retranslateUi(QMainWindow *TestMultipleCamerasClass)
    {
        TestMultipleCamerasClass->setWindowTitle(QApplication::translate("TestMultipleCamerasClass", "TestMultipleCameras", 0));
        btnShowRoi->setText(QApplication::translate("TestMultipleCamerasClass", "Show Roi", 0));
        btnShowImage->setText(QApplication::translate("TestMultipleCamerasClass", "Show Image", 0));
        btnCloseCam->setText(QApplication::translate("TestMultipleCamerasClass", "Close Cam", 0));
        btnOpenCam->setText(QApplication::translate("TestMultipleCamerasClass", "Open Cam", 0));
        label->setText(QApplication::translate("TestMultipleCamerasClass", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class TestMultipleCamerasClass: public Ui_TestMultipleCamerasClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTMULTIPLECAMERAS_H
