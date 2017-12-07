/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <imgview.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_13;
    QSplitter *splitter;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_12;
    QPushButton *check;
    QCheckBox *IsShow;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *cameraOpen;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_7;
    QVBoxLayout *verticalLayout_2;
    QPushButton *btn_OpenRoi;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *isUpCamera;
    QRadioButton *isDownCamera;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_11;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btn_LUpPassed;
    QPushButton *btn_LUpFailed;
    QHBoxLayout *horizontalLayout_4;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_3;
    QProgressBar *edge_failed_left;
    QProgressBar *edge_passed_left;
    QGridLayout *gridLayout_3;
    QLabel *label_4;
    QLabel *label_5;
    QProgressBar *inner_passed_left;
    QProgressBar *inner_failed_left;
    ImgView *LUpImage;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *btn_RUpPassed;
    QPushButton *btn_RUpFailed;
    QHBoxLayout *horizontalLayout_6;
    QGridLayout *gridLayout_4;
    QLabel *label_6;
    QLabel *label_7;
    QProgressBar *edge_failed_right;
    QProgressBar *edge_passed_right;
    QGridLayout *gridLayout_5;
    QLabel *label_8;
    QLabel *label_9;
    QProgressBar *inner_passed_right;
    QProgressBar *inner_failed_right;
    ImgView *RUpImage;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_10;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *btn_LDownPassed;
    QPushButton *btn_LDownFailed;
    QHBoxLayout *horizontalLayout_10;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QLabel *label_10;
    QProgressBar *edge_failed_left_2;
    QProgressBar *edge_passed_left_2;
    QGridLayout *gridLayout_6;
    QLabel *label_11;
    QLabel *label_12;
    QProgressBar *inner_passed_left_2;
    QProgressBar *inner_failed_left_2;
    ImgView *LDownImage;
    QGroupBox *groupBox_6;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_11;
    QPushButton *btn_RDownPassed;
    QPushButton *btn_RDownFailed;
    QHBoxLayout *horizontalLayout_12;
    QGridLayout *gridLayout_8;
    QLabel *label_13;
    QLabel *label_14;
    QProgressBar *edge_failed_right_2;
    QProgressBar *edge_passed_right_2;
    QGridLayout *gridLayout_9;
    QLabel *label_15;
    QLabel *label_16;
    QProgressBar *inner_passed_right_2;
    QProgressBar *inner_failed_right_2;
    ImgView *RDownImage;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QStringLiteral("MainWindowClass"));
        MainWindowClass->resize(1563, 807);
        MainWindowClass->setStyleSheet(QLatin1String("/*  Button */\n"
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
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_13 = new QGridLayout(centralWidget);
        gridLayout_13->setSpacing(6);
        gridLayout_13->setContentsMargins(11, 11, 11, 11);
        gridLayout_13->setObjectName(QStringLiteral("gridLayout_13"));
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        groupBox = new QGroupBox(splitter);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setMinimumSize(QSize(84, 0));
        groupBox->setMaximumSize(QSize(200, 16777215));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        groupBox->setFont(font);
        groupBox->setProperty("IsControl", QVariant(true));
        gridLayout_12 = new QGridLayout(groupBox);
        gridLayout_12->setSpacing(6);
        gridLayout_12->setContentsMargins(11, 11, 11, 11);
        gridLayout_12->setObjectName(QStringLiteral("gridLayout_12"));
        check = new QPushButton(groupBox);
        check->setObjectName(QStringLiteral("check"));
        check->setMinimumSize(QSize(84, 50));

        gridLayout_12->addWidget(check, 0, 0, 1, 1);

        IsShow = new QCheckBox(groupBox);
        IsShow->setObjectName(QStringLiteral("IsShow"));

        gridLayout_12->addWidget(IsShow, 1, 0, 1, 1);

        textEdit = new QTextEdit(groupBox);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setMinimumSize(QSize(180, 430));
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(true);
        font1.setItalic(true);
        font1.setWeight(75);
        textEdit->setFont(font1);

        gridLayout_12->addWidget(textEdit, 2, 0, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        cameraOpen = new QPushButton(groupBox);
        cameraOpen->setObjectName(QStringLiteral("cameraOpen"));
        cameraOpen->setMinimumSize(QSize(84, 0));
        cameraOpen->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_9->addWidget(cameraOpen);


        gridLayout_12->addLayout(horizontalLayout_9, 3, 0, 1, 1);

        groupBox_3 = new QGroupBox(groupBox);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setMaximumSize(QSize(16777215, 120));
        groupBox_3->setFont(font);
        gridLayout_7 = new QGridLayout(groupBox_3);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        btn_OpenRoi = new QPushButton(groupBox_3);
        btn_OpenRoi->setObjectName(QStringLiteral("btn_OpenRoi"));
        btn_OpenRoi->setFont(font);

        verticalLayout_2->addWidget(btn_OpenRoi);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        isUpCamera = new QRadioButton(groupBox_3);
        isUpCamera->setObjectName(QStringLiteral("isUpCamera"));

        horizontalLayout_3->addWidget(isUpCamera);

        isDownCamera = new QRadioButton(groupBox_3);
        isDownCamera->setObjectName(QStringLiteral("isDownCamera"));

        horizontalLayout_3->addWidget(isDownCamera);


        verticalLayout_2->addLayout(horizontalLayout_3);


        gridLayout_7->addLayout(verticalLayout_2, 0, 0, 1, 1);


        gridLayout_12->addWidget(groupBox_3, 4, 0, 1, 1);

        splitter->addWidget(groupBox);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        gridLayout_11 = new QGridLayout(layoutWidget);
        gridLayout_11->setSpacing(6);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        gridLayout_11->setContentsMargins(0, 0, 0, 0);
        groupBox_2 = new QGroupBox(layoutWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(false);
        font2.setItalic(true);
        font2.setWeight(50);
        groupBox_2->setFont(font2);
        groupBox_2->setProperty("IsDisplay", QVariant(true));
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        btn_LUpPassed = new QPushButton(groupBox_2);
        btn_LUpPassed->setObjectName(QStringLiteral("btn_LUpPassed"));
        QFont font3;
        font3.setPointSize(12);
        font3.setBold(true);
        font3.setWeight(75);
        btn_LUpPassed->setFont(font3);

        horizontalLayout_2->addWidget(btn_LUpPassed);

        btn_LUpFailed = new QPushButton(groupBox_2);
        btn_LUpFailed->setObjectName(QStringLiteral("btn_LUpFailed"));
        btn_LUpFailed->setFont(font3);

        horizontalLayout_2->addWidget(btn_LUpFailed);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));
        QFont font4;
        font4.setPointSize(10);
        font4.setBold(true);
        font4.setWeight(75);
        label->setFont(font4);
        label->setProperty("IsFailed", QVariant(true));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font4);
        label_3->setProperty("IsPassed", QVariant(true));

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        edge_failed_left = new QProgressBar(groupBox_2);
        edge_failed_left->setObjectName(QStringLiteral("edge_failed_left"));
        edge_failed_left->setValue(0);
        edge_failed_left->setProperty("IsFailed", QVariant(true));

        gridLayout->addWidget(edge_failed_left, 1, 1, 1, 1);

        edge_passed_left = new QProgressBar(groupBox_2);
        edge_passed_left->setObjectName(QStringLiteral("edge_passed_left"));
        edge_passed_left->setValue(0);
        edge_passed_left->setProperty("IsPassed", QVariant(true));

        gridLayout->addWidget(edge_passed_left, 0, 1, 1, 1);


        horizontalLayout_4->addLayout(gridLayout);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font4);
        label_4->setProperty("IsPassed", QVariant(true));

        gridLayout_3->addWidget(label_4, 0, 0, 1, 1);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font4);
        label_5->setProperty("IsFailed", QVariant(true));

        gridLayout_3->addWidget(label_5, 2, 0, 1, 1);

        inner_passed_left = new QProgressBar(groupBox_2);
        inner_passed_left->setObjectName(QStringLiteral("inner_passed_left"));
        inner_passed_left->setValue(0);
        inner_passed_left->setProperty("IsPassed", QVariant(true));

        gridLayout_3->addWidget(inner_passed_left, 0, 1, 1, 1);

        inner_failed_left = new QProgressBar(groupBox_2);
        inner_failed_left->setObjectName(QStringLiteral("inner_failed_left"));
        inner_failed_left->setValue(0);
        inner_failed_left->setProperty("IsFailed", QVariant(true));

        gridLayout_3->addWidget(inner_failed_left, 2, 1, 1, 1);


        horizontalLayout_4->addLayout(gridLayout_3);


        verticalLayout->addLayout(horizontalLayout_4);

        LUpImage = new ImgView(groupBox_2);
        LUpImage->setObjectName(QStringLiteral("LUpImage"));
        LUpImage->setMinimumSize(QSize(300, 200));
        LUpImage->setAutoFillBackground(true);
        LUpImage->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(LUpImage);


        gridLayout_11->addWidget(groupBox_2, 0, 0, 1, 1);

        groupBox_5 = new QGroupBox(layoutWidget);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setFont(font2);
        groupBox_5->setProperty("IsDisplay", QVariant(true));
        verticalLayout_3 = new QVBoxLayout(groupBox_5);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        btn_RUpPassed = new QPushButton(groupBox_5);
        btn_RUpPassed->setObjectName(QStringLiteral("btn_RUpPassed"));
        btn_RUpPassed->setFont(font3);

        horizontalLayout_5->addWidget(btn_RUpPassed);

        btn_RUpFailed = new QPushButton(groupBox_5);
        btn_RUpFailed->setObjectName(QStringLiteral("btn_RUpFailed"));
        btn_RUpFailed->setFont(font3);

        horizontalLayout_5->addWidget(btn_RUpFailed);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        label_6 = new QLabel(groupBox_5);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font4);
        label_6->setProperty("IsPassed", QVariant(true));

        gridLayout_4->addWidget(label_6, 0, 0, 1, 1);

        label_7 = new QLabel(groupBox_5);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font4);
        label_7->setProperty("IsFailed", QVariant(true));

        gridLayout_4->addWidget(label_7, 1, 0, 1, 1);

        edge_failed_right = new QProgressBar(groupBox_5);
        edge_failed_right->setObjectName(QStringLiteral("edge_failed_right"));
        edge_failed_right->setValue(0);
        edge_failed_right->setProperty("IsFailed", QVariant(true));

        gridLayout_4->addWidget(edge_failed_right, 1, 1, 1, 1);

        edge_passed_right = new QProgressBar(groupBox_5);
        edge_passed_right->setObjectName(QStringLiteral("edge_passed_right"));
        edge_passed_right->setValue(0);
        edge_passed_right->setProperty("IsPassed", QVariant(true));

        gridLayout_4->addWidget(edge_passed_right, 0, 1, 1, 1);


        horizontalLayout_6->addLayout(gridLayout_4);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        label_8 = new QLabel(groupBox_5);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font4);
        label_8->setProperty("IsPassed", QVariant(true));

        gridLayout_5->addWidget(label_8, 0, 0, 1, 1);

        label_9 = new QLabel(groupBox_5);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setFont(font4);
        label_9->setProperty("IsFailed", QVariant(true));

        gridLayout_5->addWidget(label_9, 1, 0, 1, 1);

        inner_passed_right = new QProgressBar(groupBox_5);
        inner_passed_right->setObjectName(QStringLiteral("inner_passed_right"));
        inner_passed_right->setValue(0);
        inner_passed_right->setProperty("IsPassed", QVariant(true));

        gridLayout_5->addWidget(inner_passed_right, 0, 1, 1, 1);

        inner_failed_right = new QProgressBar(groupBox_5);
        inner_failed_right->setObjectName(QStringLiteral("inner_failed_right"));
        inner_failed_right->setValue(0);
        inner_failed_right->setProperty("IsFailed", QVariant(true));

        gridLayout_5->addWidget(inner_failed_right, 1, 1, 1, 1);


        horizontalLayout_6->addLayout(gridLayout_5);


        verticalLayout_3->addLayout(horizontalLayout_6);

        RUpImage = new ImgView(groupBox_5);
        RUpImage->setObjectName(QStringLiteral("RUpImage"));
        RUpImage->setMinimumSize(QSize(300, 200));
        RUpImage->setAutoFillBackground(true);
        RUpImage->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(RUpImage);


        gridLayout_11->addWidget(groupBox_5, 0, 1, 1, 1);

        groupBox_4 = new QGroupBox(layoutWidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setFont(font2);
        groupBox_4->setProperty("IsDisplay", QVariant(true));
        gridLayout_10 = new QGridLayout(groupBox_4);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        btn_LDownPassed = new QPushButton(groupBox_4);
        btn_LDownPassed->setObjectName(QStringLiteral("btn_LDownPassed"));
        btn_LDownPassed->setFont(font3);

        horizontalLayout_8->addWidget(btn_LDownPassed);

        btn_LDownFailed = new QPushButton(groupBox_4);
        btn_LDownFailed->setObjectName(QStringLiteral("btn_LDownFailed"));
        btn_LDownFailed->setFont(font3);

        horizontalLayout_8->addWidget(btn_LDownFailed);


        gridLayout_10->addLayout(horizontalLayout_8, 0, 0, 1, 1);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_2 = new QLabel(groupBox_4);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font4);
        label_2->setProperty("IsFailed", QVariant(true));

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        label_10 = new QLabel(groupBox_4);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setFont(font4);
        label_10->setProperty("IsPassed", QVariant(true));

        gridLayout_2->addWidget(label_10, 0, 0, 1, 1);

        edge_failed_left_2 = new QProgressBar(groupBox_4);
        edge_failed_left_2->setObjectName(QStringLiteral("edge_failed_left_2"));
        edge_failed_left_2->setValue(0);
        edge_failed_left_2->setProperty("IsFailed", QVariant(true));

        gridLayout_2->addWidget(edge_failed_left_2, 1, 1, 1, 1);

        edge_passed_left_2 = new QProgressBar(groupBox_4);
        edge_passed_left_2->setObjectName(QStringLiteral("edge_passed_left_2"));
        edge_passed_left_2->setValue(0);
        edge_passed_left_2->setProperty("IsPassed", QVariant(true));

        gridLayout_2->addWidget(edge_passed_left_2, 0, 1, 1, 1);


        horizontalLayout_10->addLayout(gridLayout_2);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setSpacing(6);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        label_11 = new QLabel(groupBox_4);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setFont(font4);
        label_11->setProperty("IsPassed", QVariant(true));

        gridLayout_6->addWidget(label_11, 0, 0, 1, 1);

        label_12 = new QLabel(groupBox_4);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setFont(font4);
        label_12->setProperty("IsFailed", QVariant(true));

        gridLayout_6->addWidget(label_12, 2, 0, 1, 1);

        inner_passed_left_2 = new QProgressBar(groupBox_4);
        inner_passed_left_2->setObjectName(QStringLiteral("inner_passed_left_2"));
        inner_passed_left_2->setValue(0);
        inner_passed_left_2->setProperty("IsPassed", QVariant(true));

        gridLayout_6->addWidget(inner_passed_left_2, 0, 1, 1, 1);

        inner_failed_left_2 = new QProgressBar(groupBox_4);
        inner_failed_left_2->setObjectName(QStringLiteral("inner_failed_left_2"));
        inner_failed_left_2->setValue(0);
        inner_failed_left_2->setProperty("IsFailed", QVariant(true));

        gridLayout_6->addWidget(inner_failed_left_2, 2, 1, 1, 1);


        horizontalLayout_10->addLayout(gridLayout_6);


        gridLayout_10->addLayout(horizontalLayout_10, 1, 0, 1, 1);

        LDownImage = new ImgView(groupBox_4);
        LDownImage->setObjectName(QStringLiteral("LDownImage"));
        LDownImage->setMinimumSize(QSize(300, 200));
        LDownImage->setAutoFillBackground(true);
        LDownImage->setAlignment(Qt::AlignCenter);

        gridLayout_10->addWidget(LDownImage, 2, 0, 1, 1);


        gridLayout_11->addWidget(groupBox_4, 1, 0, 1, 1);

        groupBox_6 = new QGroupBox(layoutWidget);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        groupBox_6->setFont(font2);
        groupBox_6->setProperty("IsDisplay", QVariant(true));
        verticalLayout_5 = new QVBoxLayout(groupBox_6);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        btn_RDownPassed = new QPushButton(groupBox_6);
        btn_RDownPassed->setObjectName(QStringLiteral("btn_RDownPassed"));
        btn_RDownPassed->setFont(font3);

        horizontalLayout_11->addWidget(btn_RDownPassed);

        btn_RDownFailed = new QPushButton(groupBox_6);
        btn_RDownFailed->setObjectName(QStringLiteral("btn_RDownFailed"));
        btn_RDownFailed->setFont(font3);

        horizontalLayout_11->addWidget(btn_RDownFailed);


        verticalLayout_5->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        gridLayout_8 = new QGridLayout();
        gridLayout_8->setSpacing(6);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        label_13 = new QLabel(groupBox_6);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setFont(font4);
        label_13->setProperty("IsPassed", QVariant(true));

        gridLayout_8->addWidget(label_13, 0, 0, 1, 1);

        label_14 = new QLabel(groupBox_6);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setFont(font4);
        label_14->setProperty("IsFailed", QVariant(true));

        gridLayout_8->addWidget(label_14, 1, 0, 1, 1);

        edge_failed_right_2 = new QProgressBar(groupBox_6);
        edge_failed_right_2->setObjectName(QStringLiteral("edge_failed_right_2"));
        edge_failed_right_2->setValue(0);
        edge_failed_right_2->setProperty("IsFailed", QVariant(true));

        gridLayout_8->addWidget(edge_failed_right_2, 1, 1, 1, 1);

        edge_passed_right_2 = new QProgressBar(groupBox_6);
        edge_passed_right_2->setObjectName(QStringLiteral("edge_passed_right_2"));
        edge_passed_right_2->setValue(0);
        edge_passed_right_2->setProperty("IsPassed", QVariant(true));

        gridLayout_8->addWidget(edge_passed_right_2, 0, 1, 1, 1);


        horizontalLayout_12->addLayout(gridLayout_8);

        gridLayout_9 = new QGridLayout();
        gridLayout_9->setSpacing(6);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        label_15 = new QLabel(groupBox_6);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setFont(font4);
        label_15->setProperty("IsPassed", QVariant(true));

        gridLayout_9->addWidget(label_15, 0, 0, 1, 1);

        label_16 = new QLabel(groupBox_6);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setFont(font4);
        label_16->setProperty("IsFailed", QVariant(true));

        gridLayout_9->addWidget(label_16, 1, 0, 1, 1);

        inner_passed_right_2 = new QProgressBar(groupBox_6);
        inner_passed_right_2->setObjectName(QStringLiteral("inner_passed_right_2"));
        inner_passed_right_2->setValue(0);
        inner_passed_right_2->setProperty("IsPassed", QVariant(true));

        gridLayout_9->addWidget(inner_passed_right_2, 0, 1, 1, 1);

        inner_failed_right_2 = new QProgressBar(groupBox_6);
        inner_failed_right_2->setObjectName(QStringLiteral("inner_failed_right_2"));
        inner_failed_right_2->setValue(0);
        inner_failed_right_2->setProperty("IsFailed", QVariant(true));

        gridLayout_9->addWidget(inner_failed_right_2, 1, 1, 1, 1);


        horizontalLayout_12->addLayout(gridLayout_9);


        verticalLayout_5->addLayout(horizontalLayout_12);

        RDownImage = new ImgView(groupBox_6);
        RDownImage->setObjectName(QStringLiteral("RDownImage"));
        RDownImage->setMinimumSize(QSize(300, 200));
        RDownImage->setAutoFillBackground(true);
        RDownImage->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(RDownImage);


        gridLayout_11->addWidget(groupBox_6, 1, 1, 1, 1);

        splitter->addWidget(layoutWidget);

        gridLayout_13->addWidget(splitter, 0, 0, 1, 1);

        MainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1563, 21));
        MainWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindowClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindowClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindowClass->setStatusBar(statusBar);

        retranslateUi(MainWindowClass);

        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QApplication::translate("MainWindowClass", "MainWindow", 0));
        groupBox->setTitle(QString());
        check->setText(QApplication::translate("MainWindowClass", "Check", 0));
        IsShow->setText(QApplication::translate("MainWindowClass", "Show Image", 0));
        textEdit->setHtml(QApplication::translate("MainWindowClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:15pt; font-weight:600; font-style:italic;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-style:normal;\">Control Group</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:12pt; font-style:normal;\"><br /></p></body></html>", 0));
        cameraOpen->setText(QApplication::translate("MainWindowClass", "Open Camera", 0));
        groupBox_3->setTitle(QApplication::translate("MainWindowClass", "User Decision", 0));
        btn_OpenRoi->setText(QApplication::translate("MainWindowClass", "Save Roi", 0));
        isUpCamera->setText(QApplication::translate("MainWindowClass", "Up Camera", 0));
        isDownCamera->setText(QApplication::translate("MainWindowClass", "Down Camera", 0));
        groupBox_2->setTitle(QString());
        btn_LUpPassed->setText(QApplication::translate("MainWindowClass", "Passed", 0));
        btn_LUpFailed->setText(QApplication::translate("MainWindowClass", "Failed", 0));
        label->setText(QApplication::translate("MainWindowClass", "Edge:  Failed", 0));
        label_3->setText(QApplication::translate("MainWindowClass", " Edge: Passed", 0));
        label_4->setText(QApplication::translate("MainWindowClass", "Inner: Passed", 0));
        label_5->setText(QApplication::translate("MainWindowClass", "Inner: Failed", 0));
        LUpImage->setText(QApplication::translate("MainWindowClass", "TextLabel", 0));
        groupBox_5->setTitle(QString());
        btn_RUpPassed->setText(QApplication::translate("MainWindowClass", "Passed", 0));
        btn_RUpFailed->setText(QApplication::translate("MainWindowClass", "Failed", 0));
        label_6->setText(QApplication::translate("MainWindowClass", " Edge: Passed", 0));
        label_7->setText(QApplication::translate("MainWindowClass", "Edge: Failed", 0));
        label_8->setText(QApplication::translate("MainWindowClass", "Inner: Passed", 0));
        label_9->setText(QApplication::translate("MainWindowClass", "Inner: Failed", 0));
        RUpImage->setText(QApplication::translate("MainWindowClass", "TextLabel", 0));
        groupBox_4->setTitle(QString());
        btn_LDownPassed->setText(QApplication::translate("MainWindowClass", "Passed", 0));
        btn_LDownFailed->setText(QApplication::translate("MainWindowClass", "Failed", 0));
        label_2->setText(QApplication::translate("MainWindowClass", "Edge:  Failed", 0));
        label_10->setText(QApplication::translate("MainWindowClass", " Edge: Passed", 0));
        label_11->setText(QApplication::translate("MainWindowClass", "Inner: Passed", 0));
        label_12->setText(QApplication::translate("MainWindowClass", "Inner: Failed", 0));
        LDownImage->setText(QApplication::translate("MainWindowClass", "TextLabel", 0));
        groupBox_6->setTitle(QString());
        btn_RDownPassed->setText(QApplication::translate("MainWindowClass", "Passed", 0));
        btn_RDownFailed->setText(QApplication::translate("MainWindowClass", "Failed", 0));
        label_13->setText(QApplication::translate("MainWindowClass", " Edge: Passed", 0));
        label_14->setText(QApplication::translate("MainWindowClass", "Edge: Failed", 0));
        label_15->setText(QApplication::translate("MainWindowClass", "Inner: Passed", 0));
        label_16->setText(QApplication::translate("MainWindowClass", "Inner: Failed", 0));
        RDownImage->setText(QApplication::translate("MainWindowClass", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
