/********************************************************************************
** Form generated from reading UI file 'GuiNeuralNetwork.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUINEURALNETWORK_H
#define UI_GUINEURALNETWORK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GuiNeuralNetwork
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_newretrainnet;
    QPushButton *btn_ReTrainNet;
    QPushButton *btn_LoadModelNet;
    QPushButton *btn_Predict;
    QPushButton *btn_allpredict;
    QTextEdit *textEdit;

    void setupUi(QWidget *GuiNeuralNetwork)
    {
        if (GuiNeuralNetwork->objectName().isEmpty())
            GuiNeuralNetwork->setObjectName(QStringLiteral("GuiNeuralNetwork"));
        GuiNeuralNetwork->resize(400, 300);
        verticalLayout = new QVBoxLayout(GuiNeuralNetwork);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        btn_newretrainnet = new QPushButton(GuiNeuralNetwork);
        btn_newretrainnet->setObjectName(QStringLiteral("btn_newretrainnet"));

        horizontalLayout->addWidget(btn_newretrainnet);

        btn_ReTrainNet = new QPushButton(GuiNeuralNetwork);
        btn_ReTrainNet->setObjectName(QStringLiteral("btn_ReTrainNet"));

        horizontalLayout->addWidget(btn_ReTrainNet);

        btn_LoadModelNet = new QPushButton(GuiNeuralNetwork);
        btn_LoadModelNet->setObjectName(QStringLiteral("btn_LoadModelNet"));

        horizontalLayout->addWidget(btn_LoadModelNet);

        btn_Predict = new QPushButton(GuiNeuralNetwork);
        btn_Predict->setObjectName(QStringLiteral("btn_Predict"));

        horizontalLayout->addWidget(btn_Predict);


        verticalLayout->addLayout(horizontalLayout);

        btn_allpredict = new QPushButton(GuiNeuralNetwork);
        btn_allpredict->setObjectName(QStringLiteral("btn_allpredict"));

        verticalLayout->addWidget(btn_allpredict);

        textEdit = new QTextEdit(GuiNeuralNetwork);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        font.setWeight(75);
        textEdit->setFont(font);

        verticalLayout->addWidget(textEdit);


        retranslateUi(GuiNeuralNetwork);

        QMetaObject::connectSlotsByName(GuiNeuralNetwork);
    } // setupUi

    void retranslateUi(QWidget *GuiNeuralNetwork)
    {
        GuiNeuralNetwork->setWindowTitle(QApplication::translate("GuiNeuralNetwork", "GuiNeuralNetwork", 0));
        btn_newretrainnet->setText(QApplication::translate("GuiNeuralNetwork", "New Retrain Net", 0));
        btn_ReTrainNet->setText(QApplication::translate("GuiNeuralNetwork", "Re Train Net", 0));
        btn_LoadModelNet->setText(QApplication::translate("GuiNeuralNetwork", "Load Model Net", 0));
        btn_Predict->setText(QApplication::translate("GuiNeuralNetwork", "Predict", 0));
        btn_allpredict->setText(QApplication::translate("GuiNeuralNetwork", "All Predict ", 0));
    } // retranslateUi

};

namespace Ui {
    class GuiNeuralNetwork: public Ui_GuiNeuralNetwork {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUINEURALNETWORK_H
