/********************************************************************************
** Form generated from reading UI file 'QtCurvature.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTCURVATURE_H
#define UI_QTCURVATURE_H

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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtCurvature
{
public:
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QSpinBox *spin_size;
    QLabel *label_2;
    QSpinBox *spin_index;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QRadioButton *radio_outer;
    QRadioButton *radio_inner;
    QPushButton *btn_showImage;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btn_clearolddata;
    QPushButton *btn_savedata;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *check_passed;
    QCheckBox *check_failed;
    QTextEdit *textEdit;

    void setupUi(QWidget *QtCurvature)
    {
        if (QtCurvature->objectName().isEmpty())
            QtCurvature->setObjectName(QStringLiteral("QtCurvature"));
        QtCurvature->resize(521, 504);
        verticalLayout_3 = new QVBoxLayout(QtCurvature);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        groupBox = new QGroupBox(QtCurvature);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        groupBox->setFont(font);
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        spin_size = new QSpinBox(groupBox);
        spin_size->setObjectName(QStringLiteral("spin_size"));
        spin_size->setMinimum(10);
        spin_size->setMaximum(100000);
        spin_size->setValue(100);

        gridLayout->addWidget(spin_size, 0, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        spin_index = new QSpinBox(groupBox);
        spin_index->setObjectName(QStringLiteral("spin_index"));
        spin_index->setMaximum(10000);

        gridLayout->addWidget(spin_index, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);

        radio_outer = new QRadioButton(groupBox);
        radio_outer->setObjectName(QStringLiteral("radio_outer"));
        radio_outer->setChecked(true);

        horizontalLayout->addWidget(radio_outer);

        radio_inner = new QRadioButton(groupBox);
        radio_inner->setObjectName(QStringLiteral("radio_inner"));

        horizontalLayout->addWidget(radio_inner);


        verticalLayout->addLayout(horizontalLayout);

        btn_showImage = new QPushButton(groupBox);
        btn_showImage->setObjectName(QStringLiteral("btn_showImage"));

        verticalLayout->addWidget(btn_showImage);


        verticalLayout_3->addWidget(groupBox);

        groupBox_2 = new QGroupBox(QtCurvature);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        groupBox_2->setFont(font1);
        horizontalLayout_2 = new QHBoxLayout(groupBox_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        btn_clearolddata = new QPushButton(groupBox_2);
        btn_clearolddata->setObjectName(QStringLiteral("btn_clearolddata"));

        horizontalLayout_2->addWidget(btn_clearolddata);

        btn_savedata = new QPushButton(groupBox_2);
        btn_savedata->setObjectName(QStringLiteral("btn_savedata"));

        horizontalLayout_2->addWidget(btn_savedata);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        check_passed = new QCheckBox(groupBox_2);
        check_passed->setObjectName(QStringLiteral("check_passed"));

        verticalLayout_2->addWidget(check_passed);

        check_failed = new QCheckBox(groupBox_2);
        check_failed->setObjectName(QStringLiteral("check_failed"));

        verticalLayout_2->addWidget(check_failed);


        horizontalLayout_2->addLayout(verticalLayout_2);


        verticalLayout_3->addWidget(groupBox_2);

        textEdit = new QTextEdit(QtCurvature);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        verticalLayout_3->addWidget(textEdit);


        retranslateUi(QtCurvature);

        QMetaObject::connectSlotsByName(QtCurvature);
    } // setupUi

    void retranslateUi(QWidget *QtCurvature)
    {
        QtCurvature->setWindowTitle(QApplication::translate("QtCurvature", "QtCurvature", 0));
        groupBox->setTitle(QApplication::translate("QtCurvature", "GroupBox", 0));
        label->setText(QApplication::translate("QtCurvature", "Size:", 0));
        label_2->setText(QApplication::translate("QtCurvature", "Index:", 0));
        label_3->setText(QApplication::translate("QtCurvature", "Select Id:", 0));
        radio_outer->setText(QApplication::translate("QtCurvature", "Outer", 0));
        radio_inner->setText(QApplication::translate("QtCurvature", "Inner", 0));
        btn_showImage->setText(QApplication::translate("QtCurvature", "Show Contour", 0));
        groupBox_2->setTitle(QApplication::translate("QtCurvature", "Data", 0));
        btn_clearolddata->setText(QApplication::translate("QtCurvature", "Clear Old Data", 0));
        btn_savedata->setText(QApplication::translate("QtCurvature", "Save Data", 0));
        check_passed->setText(QApplication::translate("QtCurvature", "Passed", 0));
        check_failed->setText(QApplication::translate("QtCurvature", "Failed", 0));
    } // retranslateUi

};

namespace Ui {
    class QtCurvature: public Ui_QtCurvature {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTCURVATURE_H
