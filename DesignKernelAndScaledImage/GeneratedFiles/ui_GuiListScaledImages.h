/********************************************************************************
** Form generated from reading UI file 'GuiListScaledImages.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUILISTSCALEDIMAGES_H
#define UI_GUILISTSCALEDIMAGES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GuiListScaledImages
{
public:
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_read;
    QPushButton *btn_save;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout_6;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *line_nameKernel;
    QPushButton *btn_createkernel;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *btn_savekernel;
    QPushButton *btn_savelistkernel;
    QTextEdit *text_kernelmask;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *btn_showimage;
    QSpinBox *spin_scaledfactor;
    QPushButton *btn_showlistimage;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_2;
    QSpinBox *spin_poolingsize;
    QPushButton *btn_maxpooling;
    QTextEdit *text_pooling;

    void setupUi(QWidget *GuiListScaledImages)
    {
        if (GuiListScaledImages->objectName().isEmpty())
            GuiListScaledImages->setObjectName(QStringLiteral("GuiListScaledImages"));
        GuiListScaledImages->resize(580, 768);
        verticalLayout_4 = new QVBoxLayout(GuiListScaledImages);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        groupBox = new QGroupBox(GuiListScaledImages);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        groupBox->setFont(font);
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        btn_read = new QPushButton(groupBox);
        btn_read->setObjectName(QStringLiteral("btn_read"));

        horizontalLayout->addWidget(btn_read);

        btn_save = new QPushButton(groupBox);
        btn_save->setObjectName(QStringLiteral("btn_save"));

        horizontalLayout->addWidget(btn_save);


        verticalLayout->addLayout(horizontalLayout);

        textEdit = new QTextEdit(groupBox);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(true);
        font1.setWeight(75);
        textEdit->setFont(font1);

        verticalLayout->addWidget(textEdit);


        verticalLayout_4->addWidget(groupBox);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        groupBox_2 = new QGroupBox(GuiListScaledImages);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setFont(font);
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        line_nameKernel = new QLineEdit(groupBox_2);
        line_nameKernel->setObjectName(QStringLiteral("line_nameKernel"));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        line_nameKernel->setFont(font2);

        horizontalLayout_2->addWidget(line_nameKernel);


        verticalLayout_2->addLayout(horizontalLayout_2);

        btn_createkernel = new QPushButton(groupBox_2);
        btn_createkernel->setObjectName(QStringLiteral("btn_createkernel"));

        verticalLayout_2->addWidget(btn_createkernel);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        btn_savekernel = new QPushButton(groupBox_2);
        btn_savekernel->setObjectName(QStringLiteral("btn_savekernel"));

        horizontalLayout_3->addWidget(btn_savekernel);

        btn_savelistkernel = new QPushButton(groupBox_2);
        btn_savelistkernel->setObjectName(QStringLiteral("btn_savelistkernel"));

        horizontalLayout_3->addWidget(btn_savelistkernel);


        verticalLayout_2->addLayout(horizontalLayout_3);

        text_kernelmask = new QTextEdit(groupBox_2);
        text_kernelmask->setObjectName(QStringLiteral("text_kernelmask"));
        text_kernelmask->setFont(font1);

        verticalLayout_2->addWidget(text_kernelmask);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        btn_showimage = new QPushButton(groupBox_2);
        btn_showimage->setObjectName(QStringLiteral("btn_showimage"));

        horizontalLayout_4->addWidget(btn_showimage);

        spin_scaledfactor = new QSpinBox(groupBox_2);
        spin_scaledfactor->setObjectName(QStringLiteral("spin_scaledfactor"));
        spin_scaledfactor->setMinimum(1);
        spin_scaledfactor->setMaximum(100);
        spin_scaledfactor->setValue(15);

        horizontalLayout_4->addWidget(spin_scaledfactor);


        verticalLayout_2->addLayout(horizontalLayout_4);

        btn_showlistimage = new QPushButton(groupBox_2);
        btn_showlistimage->setObjectName(QStringLiteral("btn_showlistimage"));

        verticalLayout_2->addWidget(btn_showlistimage);


        horizontalLayout_6->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(GuiListScaledImages);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setFont(font);
        verticalLayout_3 = new QVBoxLayout(groupBox_3);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_5->addWidget(label_2);

        spin_poolingsize = new QSpinBox(groupBox_3);
        spin_poolingsize->setObjectName(QStringLiteral("spin_poolingsize"));

        horizontalLayout_5->addWidget(spin_poolingsize);


        verticalLayout_3->addLayout(horizontalLayout_5);

        btn_maxpooling = new QPushButton(groupBox_3);
        btn_maxpooling->setObjectName(QStringLiteral("btn_maxpooling"));

        verticalLayout_3->addWidget(btn_maxpooling);

        text_pooling = new QTextEdit(groupBox_3);
        text_pooling->setObjectName(QStringLiteral("text_pooling"));

        verticalLayout_3->addWidget(text_pooling);


        horizontalLayout_6->addWidget(groupBox_3);


        verticalLayout_4->addLayout(horizontalLayout_6);


        retranslateUi(GuiListScaledImages);

        QMetaObject::connectSlotsByName(GuiListScaledImages);
    } // setupUi

    void retranslateUi(QWidget *GuiListScaledImages)
    {
        GuiListScaledImages->setWindowTitle(QApplication::translate("GuiListScaledImages", "GuiListScaledImages", 0));
        groupBox->setTitle(QApplication::translate("GuiListScaledImages", "Scaled Image", 0));
        btn_read->setText(QApplication::translate("GuiListScaledImages", "Read", 0));
        btn_save->setText(QApplication::translate("GuiListScaledImages", "Save", 0));
        groupBox_2->setTitle(QApplication::translate("GuiListScaledImages", "Kernel Mask", 0));
        label->setText(QApplication::translate("GuiListScaledImages", "Name Kernel", 0));
        line_nameKernel->setText(QApplication::translate("GuiListScaledImages", "kernel3x3", 0));
        btn_createkernel->setText(QApplication::translate("GuiListScaledImages", "Create Kernel", 0));
        btn_savekernel->setText(QApplication::translate("GuiListScaledImages", "Save Kernel", 0));
        btn_savelistkernel->setText(QApplication::translate("GuiListScaledImages", "Save List Kernel", 0));
        btn_showimage->setText(QApplication::translate("GuiListScaledImages", "Show Image", 0));
        btn_showlistimage->setText(QApplication::translate("GuiListScaledImages", "Show List Images", 0));
        groupBox_3->setTitle(QApplication::translate("GuiListScaledImages", "CNN Pooling", 0));
        label_2->setText(QApplication::translate("GuiListScaledImages", "Pooing Size:", 0));
        btn_maxpooling->setText(QApplication::translate("GuiListScaledImages", "Max Pooling", 0));
    } // retranslateUi

};

namespace Ui {
    class GuiListScaledImages: public Ui_GuiListScaledImages {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUILISTSCALEDIMAGES_H
