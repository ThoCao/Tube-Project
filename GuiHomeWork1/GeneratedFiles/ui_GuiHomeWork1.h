/********************************************************************************
** Form generated from reading UI file 'GuiHomeWork1.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUIHOMEWORK1_H
#define UI_GUIHOMEWORK1_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "imgview.h"

QT_BEGIN_NAMESPACE

class Ui_GuiHomeWork1Class
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QPushButton *btn_LoadImage;
    QSpacerItem *verticalSpacer;
    ImgView *label;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GuiHomeWork1Class)
    {
        if (GuiHomeWork1Class->objectName().isEmpty())
            GuiHomeWork1Class->setObjectName(QStringLiteral("GuiHomeWork1Class"));
        GuiHomeWork1Class->resize(496, 281);
        GuiHomeWork1Class->setStyleSheet(QLatin1String("/*  Button */\n"
"QPushButton {\n"
"    border: 2px solid #8f8f91;\n"
"    border-radius: 6px;\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
"    min-width: 80px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color:rgb(170, 170, 255)\n"
"}\n"
"/* Group Control*/\n"
"QGroupBox[IsControl]{\n"
"    border: 2px solid #8f8f91;\n"
"   border-radius: 6px;\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
"    min-width: 80px;\n"
"}\n"
"/* Group Display */\n"
"QGroupBox[IsDisplay]{\n"
"    border: 2px solid #8f8f91;\n"
"    border-radius: 6px;\n"
"    background-color:rgb(181, 181, 181)\n"
"}\n"
"\n"
"/*  Progress */\n"
"\n"
"QProgressBar[IsFailed ]::chunk {\n"
"      background-color: rgb(203, 0, 0);\n"
"      width: 20px;\n"
"      margin: 0.5px;\n"
"}\n"
"\n"
"QProgressBar[IsFailed ]{\n"
"      border: 2p"
                        "x solid grey;\n"
"     border-radius: 5px;\n"
"     text-align: center;\n"
"}\n"
"\n"
"QProgressBar[IsPassed ]::chunk {\n"
"      background-color: rgb(0, 220, 0);\n"
"      width: 20px;\n"
"      margin: 0.5px;\n"
"}\n"
"\n"
"QProgressBar[IsPassed ]{\n"
"      border: 2px solid grey;\n"
"     border-radius: 5px;\n"
"     text-align: center;\n"
"}\n"
"\n"
"/* QLabel */\n"
"QLabel[IsPassed]{\n"
"     border: 4px solid green;\n"
"     border-radius: 4px;\n"
"     padding: 2px;\n"
"}\n"
"\n"
"QLabel[IsFailed]{\n"
"     border: 4px solid red;\n"
"     border-radius: 4px;\n"
"     padding: 2px;\n"
"}\n"
"\n"
""));
        centralWidget = new QWidget(GuiHomeWork1Class);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        btn_LoadImage = new QPushButton(groupBox);
        btn_LoadImage->setObjectName(QStringLiteral("btn_LoadImage"));

        gridLayout->addWidget(btn_LoadImage, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 145, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 0, 1, 1);


        gridLayout_2->addWidget(groupBox, 0, 0, 1, 1);

        label = new ImgView(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setAutoFillBackground(true);

        gridLayout_2->addWidget(label, 0, 1, 1, 1);

        GuiHomeWork1Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(GuiHomeWork1Class);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 496, 21));
        GuiHomeWork1Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(GuiHomeWork1Class);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        GuiHomeWork1Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(GuiHomeWork1Class);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        GuiHomeWork1Class->setStatusBar(statusBar);

        retranslateUi(GuiHomeWork1Class);

        QMetaObject::connectSlotsByName(GuiHomeWork1Class);
    } // setupUi

    void retranslateUi(QMainWindow *GuiHomeWork1Class)
    {
        GuiHomeWork1Class->setWindowTitle(QApplication::translate("GuiHomeWork1Class", "GuiHomeWork1", 0));
        groupBox->setTitle(QApplication::translate("GuiHomeWork1Class", "GroupBox", 0));
        btn_LoadImage->setText(QApplication::translate("GuiHomeWork1Class", "Load Image", 0));
        label->setText(QApplication::translate("GuiHomeWork1Class", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class GuiHomeWork1Class: public Ui_GuiHomeWork1Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUIHOMEWORK1_H
