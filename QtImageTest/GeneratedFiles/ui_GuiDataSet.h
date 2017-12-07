/********************************************************************************
** Form generated from reading UI file 'GuiDataSet.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUIDATASET_H
#define UI_GUIDATASET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GuiDataSet
{
public:
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QPushButton *btn_savedata;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_retraindata;
    QRadioButton *radio_true;
    QPushButton *btn_postsave;

    void setupUi(QWidget *GuiDataSet)
    {
        if (GuiDataSet->objectName().isEmpty())
            GuiDataSet->setObjectName(QStringLiteral("GuiDataSet"));
        GuiDataSet->resize(446, 349);
        gridLayout_3 = new QGridLayout(GuiDataSet);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        groupBox_2 = new QGroupBox(GuiDataSet);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        btn_savedata = new QPushButton(groupBox_2);
        btn_savedata->setObjectName(QStringLiteral("btn_savedata"));

        gridLayout_2->addWidget(btn_savedata, 0, 0, 1, 1);


        gridLayout_3->addWidget(groupBox_2, 0, 0, 1, 1);

        groupBox = new QGroupBox(GuiDataSet);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        btn_retraindata = new QPushButton(groupBox);
        btn_retraindata->setObjectName(QStringLiteral("btn_retraindata"));

        horizontalLayout->addWidget(btn_retraindata);

        radio_true = new QRadioButton(groupBox);
        radio_true->setObjectName(QStringLiteral("radio_true"));

        horizontalLayout->addWidget(radio_true);


        verticalLayout->addLayout(horizontalLayout);

        btn_postsave = new QPushButton(groupBox);
        btn_postsave->setObjectName(QStringLiteral("btn_postsave"));

        verticalLayout->addWidget(btn_postsave);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        gridLayout_3->addWidget(groupBox, 1, 0, 1, 1);


        retranslateUi(GuiDataSet);

        QMetaObject::connectSlotsByName(GuiDataSet);
    } // setupUi

    void retranslateUi(QWidget *GuiDataSet)
    {
        GuiDataSet->setWindowTitle(QApplication::translate("GuiDataSet", "GuiDataSet", 0));
        groupBox_2->setTitle(QApplication::translate("GuiDataSet", "Pre Data", 0));
        btn_savedata->setText(QApplication::translate("GuiDataSet", "Save Data", 0));
        groupBox->setTitle(QApplication::translate("GuiDataSet", "Post Data", 0));
        btn_retraindata->setText(QApplication::translate("GuiDataSet", "New Data ReTrain", 0));
        radio_true->setText(QApplication::translate("GuiDataSet", "True", 0));
        btn_postsave->setText(QApplication::translate("GuiDataSet", "Save Post Data", 0));
    } // retranslateUi

};

namespace Ui {
    class GuiDataSet: public Ui_GuiDataSet {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUIDATASET_H
