/********************************************************************************
** Form generated from reading UI file 'RoiGUI.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROIGUI_H
#define UI_ROIGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QWidget>
#include <imgview.h>

QT_BEGIN_NAMESPACE

class Ui_RoiGUI
{
public:
    QGridLayout *gridLayout_2;
    QSplitter *splitter;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QRadioButton *isOne;
    QRadioButton *isTwo;
    QPushButton *btnSaveRoi;
    ImgView *label;

    void setupUi(QDialog *RoiGUI)
    {
        if (RoiGUI->objectName().isEmpty())
            RoiGUI->setObjectName(QStringLiteral("RoiGUI"));
        RoiGUI->resize(658, 583);
        gridLayout_2 = new QGridLayout(RoiGUI);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        splitter = new QSplitter(RoiGUI);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Vertical);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        isOne = new QRadioButton(layoutWidget);
        isOne->setObjectName(QStringLiteral("isOne"));

        gridLayout->addWidget(isOne, 1, 0, 1, 2);

        isTwo = new QRadioButton(layoutWidget);
        isTwo->setObjectName(QStringLiteral("isTwo"));

        gridLayout->addWidget(isTwo, 1, 2, 1, 1);

        btnSaveRoi = new QPushButton(layoutWidget);
        btnSaveRoi->setObjectName(QStringLiteral("btnSaveRoi"));

        gridLayout->addWidget(btnSaveRoi, 0, 0, 1, 3);

        splitter->addWidget(layoutWidget);
        label = new ImgView(splitter);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(640, 512));
        label->setMaximumSize(QSize(640, 512));
        label->setAutoFillBackground(true);
        splitter->addWidget(label);

        gridLayout_2->addWidget(splitter, 0, 0, 1, 1);


        retranslateUi(RoiGUI);

        QMetaObject::connectSlotsByName(RoiGUI);
    } // setupUi

    void retranslateUi(QDialog *RoiGUI)
    {
        RoiGUI->setWindowTitle(QApplication::translate("RoiGUI", "RoiGUI", 0));
        isOne->setText(QApplication::translate("RoiGUI", "Left Side", 0));
        isTwo->setText(QApplication::translate("RoiGUI", "Right Side", 0));
        btnSaveRoi->setText(QApplication::translate("RoiGUI", "Save ", 0));
        label->setText(QApplication::translate("RoiGUI", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class RoiGUI: public Ui_RoiGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROIGUI_H
