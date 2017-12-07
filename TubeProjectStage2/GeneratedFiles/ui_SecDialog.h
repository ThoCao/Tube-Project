/********************************************************************************
** Form generated from reading UI file 'SecDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECDIALOG_H
#define UI_SECDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SecDialog
{
public:
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btn_showNet;
    QPushButton *btn_saveNet;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *btn_createNet;
    QPushButton *btn_reTrain;
    QPushButton *btn_loadModelNet;
    QPushButton *btn_predict;
    QTextEdit *textEdit_NeuralNet;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *btn_show;
    QPushButton *btn_save;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_lookuptable;
    QPushButton *btn_showFeatureIndex;
    QSpinBox *featureRange;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QTextEdit *textEdit;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *btn_lookuptable2D;
    QPushButton *btn_showFeatureIndex2D;
    QSpinBox *featureRange2D;
    QTextEdit *text2Dfeature;

    void setupUi(QWidget *SecDialog)
    {
        if (SecDialog->objectName().isEmpty())
            SecDialog->setObjectName(QStringLiteral("SecDialog"));
        SecDialog->resize(553, 831);
        SecDialog->setStyleSheet(QLatin1String("QSlider::groove:vertical {\n"
"    background: red;\n"
"    position: absolute; /* absolutely position 4px from the left and right of the widget. setting margins on the widget should work too... */\n"
"    left: 4px; right: 4px;\n"
"}\n"
"\n"
"QSlider::handle:vertical {\n"
"    height: 10px;\n"
"    background: green;\n"
"    margin: 0 -4px; /* expand outside the groove */\n"
"}\n"
"\n"
"QSlider::add-page:vertical {\n"
"    background: white;\n"
"}\n"
"\n"
"QSlider::sub-page:vertical {\n"
"    background: pink;\n"
"}\n"
"/*  QLabel */\n"
"QFrame, QLabel, QToolTip {\n"
"    border: 2px solid green;\n"
"    border-radius: 4px;\n"
"    padding: 2px;\n"
"   text-align: center;\n"
"}\n"
"/*  Button */\n"
"QPushButton {\n"
"    border: 2px solid #8f8f91;\n"
"    border-radius: 6px;\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
"    min-width: 80px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qli"
                        "neargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}\n"
"\n"
"QPushButton:flat {\n"
"    border: none; /* no border for a flat push button */\n"
"}\n"
"\n"
"QPushButton:default {\n"
"    border-color: navy; /* make the default button prominent */\n"
"}\n"
"QPushButton:open { /* when the button has its menu open */\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}\n"
"\n"
"QPushButton::menu-indicator {\n"
"    image: url(menu_indicator.png);\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: bottom right;\n"
"}\n"
"\n"
"QPushButton::menu-indicator:pressed, QPushButton::menu-indicator:open {\n"
"    position: relative;\n"
"    top: 2px; left: 2px; /* shift the arrow by 2 px */\n"
"}\n"
"\n"
"QTextEdit, QListView {\n"
"    background-color: white;\n"
"    background-image: url(draft.png);\n"
"    background-attachment: scroll;\n"
""
                        "}\n"
"\n"
"/* LCD*/\n"
"QLCDNumber {\n"
"     color: red;\n"
"     background-color: rgb(0, 170, 255) \n"
"}\n"
"/* The result */\n"
"QLabel[IsResult = true]{\n"
"     color: red;\n"
"     background-color: rgb(220, 220, 220) \n"
"}\n"
"\n"
"\n"
""));
        verticalLayout_4 = new QVBoxLayout(SecDialog);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        groupBox_2 = new QGroupBox(SecDialog);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setAlignment(Qt::AlignCenter);
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        btn_showNet = new QPushButton(groupBox_2);
        btn_showNet->setObjectName(QStringLiteral("btn_showNet"));

        horizontalLayout_2->addWidget(btn_showNet);

        btn_saveNet = new QPushButton(groupBox_2);
        btn_saveNet->setObjectName(QStringLiteral("btn_saveNet"));

        horizontalLayout_2->addWidget(btn_saveNet);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        btn_createNet = new QPushButton(groupBox_2);
        btn_createNet->setObjectName(QStringLiteral("btn_createNet"));

        horizontalLayout_3->addWidget(btn_createNet);

        btn_reTrain = new QPushButton(groupBox_2);
        btn_reTrain->setObjectName(QStringLiteral("btn_reTrain"));

        horizontalLayout_3->addWidget(btn_reTrain);

        btn_loadModelNet = new QPushButton(groupBox_2);
        btn_loadModelNet->setObjectName(QStringLiteral("btn_loadModelNet"));

        horizontalLayout_3->addWidget(btn_loadModelNet);

        btn_predict = new QPushButton(groupBox_2);
        btn_predict->setObjectName(QStringLiteral("btn_predict"));

        horizontalLayout_3->addWidget(btn_predict);


        verticalLayout_2->addLayout(horizontalLayout_3);

        textEdit_NeuralNet = new QTextEdit(groupBox_2);
        textEdit_NeuralNet->setObjectName(QStringLiteral("textEdit_NeuralNet"));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        textEdit_NeuralNet->setFont(font);

        verticalLayout_2->addWidget(textEdit_NeuralNet);


        verticalLayout_4->addWidget(groupBox_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        btn_show = new QPushButton(SecDialog);
        btn_show->setObjectName(QStringLiteral("btn_show"));

        horizontalLayout_4->addWidget(btn_show);

        btn_save = new QPushButton(SecDialog);
        btn_save->setObjectName(QStringLiteral("btn_save"));

        horizontalLayout_4->addWidget(btn_save);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        btn_lookuptable = new QPushButton(SecDialog);
        btn_lookuptable->setObjectName(QStringLiteral("btn_lookuptable"));

        horizontalLayout->addWidget(btn_lookuptable);

        btn_showFeatureIndex = new QPushButton(SecDialog);
        btn_showFeatureIndex->setObjectName(QStringLiteral("btn_showFeatureIndex"));

        horizontalLayout->addWidget(btn_showFeatureIndex);

        featureRange = new QSpinBox(SecDialog);
        featureRange->setObjectName(QStringLiteral("featureRange"));
        featureRange->setMaximum(1000);

        horizontalLayout->addWidget(featureRange);


        verticalLayout_3->addLayout(horizontalLayout);

        groupBox = new QGroupBox(SecDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setAlignment(Qt::AlignCenter);
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        textEdit = new QTextEdit(groupBox);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        textEdit->setFont(font1);

        gridLayout->addWidget(textEdit, 0, 0, 1, 1);


        verticalLayout_3->addWidget(groupBox);


        verticalLayout_4->addLayout(verticalLayout_3);

        groupBox_3 = new QGroupBox(SecDialog);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        verticalLayout = new QVBoxLayout(groupBox_3);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        btn_lookuptable2D = new QPushButton(groupBox_3);
        btn_lookuptable2D->setObjectName(QStringLiteral("btn_lookuptable2D"));

        horizontalLayout_5->addWidget(btn_lookuptable2D);

        btn_showFeatureIndex2D = new QPushButton(groupBox_3);
        btn_showFeatureIndex2D->setObjectName(QStringLiteral("btn_showFeatureIndex2D"));

        horizontalLayout_5->addWidget(btn_showFeatureIndex2D);

        featureRange2D = new QSpinBox(groupBox_3);
        featureRange2D->setObjectName(QStringLiteral("featureRange2D"));
        featureRange2D->setMaximum(1000);

        horizontalLayout_5->addWidget(featureRange2D);


        verticalLayout->addLayout(horizontalLayout_5);

        text2Dfeature = new QTextEdit(groupBox_3);
        text2Dfeature->setObjectName(QStringLiteral("text2Dfeature"));
        text2Dfeature->setFont(font1);

        verticalLayout->addWidget(text2Dfeature);


        verticalLayout_4->addWidget(groupBox_3);


        retranslateUi(SecDialog);

        QMetaObject::connectSlotsByName(SecDialog);
    } // setupUi

    void retranslateUi(QWidget *SecDialog)
    {
        SecDialog->setWindowTitle(QApplication::translate("SecDialog", "SecDialog", 0));
        groupBox_2->setTitle(QApplication::translate("SecDialog", "Group of Neural Net", 0));
        btn_showNet->setText(QApplication::translate("SecDialog", "Show Net", 0));
        btn_saveNet->setText(QApplication::translate("SecDialog", "Save Net", 0));
        btn_createNet->setText(QApplication::translate("SecDialog", "Create Network", 0));
        btn_reTrain->setText(QApplication::translate("SecDialog", "Re-Train", 0));
        btn_loadModelNet->setText(QApplication::translate("SecDialog", "Load Model", 0));
        btn_predict->setText(QApplication::translate("SecDialog", "Predict", 0));
        btn_show->setText(QApplication::translate("SecDialog", "Show Feature", 0));
        btn_save->setText(QApplication::translate("SecDialog", "Save Feature", 0));
        btn_lookuptable->setText(QApplication::translate("SecDialog", "Config LookUpTable 1D", 0));
        btn_showFeatureIndex->setText(QApplication::translate("SecDialog", "Show Feature Index 1D", 0));
        groupBox->setTitle(QApplication::translate("SecDialog", "1D Feature", 0));
        groupBox_3->setTitle(QApplication::translate("SecDialog", "2D Feature", 0));
        btn_lookuptable2D->setText(QApplication::translate("SecDialog", "Config LookUpTable 2D", 0));
        btn_showFeatureIndex2D->setText(QApplication::translate("SecDialog", "Show Feature Index 2D", 0));
    } // retranslateUi

};

namespace Ui {
    class SecDialog: public Ui_SecDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECDIALOG_H
