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
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QPushButton *btn_savealldata;
    QPushButton *btn_trainneural;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QPushButton *btn_IsPushData;
    QPushButton *btn_IsPopData;
    QVBoxLayout *verticalLayout;
    QRadioButton *IsPassed;
    QRadioButton *IsFailed;

    void setupUi(QWidget *GuiDataSet)
    {
        if (GuiDataSet->objectName().isEmpty())
            GuiDataSet->setObjectName(QStringLiteral("GuiDataSet"));
        GuiDataSet->resize(442, 369);
        gridLayout_3 = new QGridLayout(GuiDataSet);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        groupBox_2 = new QGroupBox(GuiDataSet);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout_4 = new QVBoxLayout(groupBox_2);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        btn_savealldata = new QPushButton(groupBox_2);
        btn_savealldata->setObjectName(QStringLiteral("btn_savealldata"));
        btn_savealldata->setMinimumSize(QSize(0, 50));

        verticalLayout_3->addWidget(btn_savealldata);

        btn_trainneural = new QPushButton(groupBox_2);
        btn_trainneural->setObjectName(QStringLiteral("btn_trainneural"));
        btn_trainneural->setMinimumSize(QSize(0, 50));

        verticalLayout_3->addWidget(btn_trainneural);


        verticalLayout_4->addLayout(verticalLayout_3);

        groupBox = new QGroupBox(groupBox_2);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        btn_IsPushData = new QPushButton(groupBox);
        btn_IsPushData->setObjectName(QStringLiteral("btn_IsPushData"));
        btn_IsPushData->setMinimumSize(QSize(0, 100));

        verticalLayout_2->addWidget(btn_IsPushData);

        btn_IsPopData = new QPushButton(groupBox);
        btn_IsPopData->setObjectName(QStringLiteral("btn_IsPopData"));
        btn_IsPopData->setMinimumSize(QSize(0, 100));

        verticalLayout_2->addWidget(btn_IsPopData);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        IsPassed = new QRadioButton(groupBox);
        IsPassed->setObjectName(QStringLiteral("IsPassed"));
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        font.setWeight(75);
        IsPassed->setFont(font);

        verticalLayout->addWidget(IsPassed);

        IsFailed = new QRadioButton(groupBox);
        IsFailed->setObjectName(QStringLiteral("IsFailed"));
        IsFailed->setFont(font);

        verticalLayout->addWidget(IsFailed);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_4->addWidget(groupBox);


        gridLayout_3->addWidget(groupBox_2, 0, 0, 1, 1);


        retranslateUi(GuiDataSet);

        QMetaObject::connectSlotsByName(GuiDataSet);
    } // setupUi

    void retranslateUi(QWidget *GuiDataSet)
    {
        GuiDataSet->setWindowTitle(QApplication::translate("GuiDataSet", "GuiDataSet", 0));
        groupBox_2->setTitle(QApplication::translate("GuiDataSet", "Pre Data", 0));
        btn_savealldata->setText(QApplication::translate("GuiDataSet", "Save All Data", 0));
        btn_trainneural->setText(QApplication::translate("GuiDataSet", "Neural Train", 0));
        groupBox->setTitle(QApplication::translate("GuiDataSet", "Single Each Data", 0));
        btn_IsPushData->setText(QApplication::translate("GuiDataSet", "Push Back", 0));
        btn_IsPopData->setText(QApplication::translate("GuiDataSet", "Push Back", 0));
        IsPassed->setText(QApplication::translate("GuiDataSet", "Passed ", 0));
        IsFailed->setText(QApplication::translate("GuiDataSet", "Failed", 0));
    } // retranslateUi

};

namespace Ui {
    class GuiDataSet: public Ui_GuiDataSet {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUIDATASET_H
