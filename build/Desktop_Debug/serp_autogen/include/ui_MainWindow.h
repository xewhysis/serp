/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
//#include "../../../../KochWidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *inputLayout;
    QLabel *nLabel;
    QSpinBox *nSpinBox;
    QPushButton *buildButton;
    QSpacerItem *horizontalSpacer;
    QLabel *iterationLabel;
    QSlider *iterationSlider;
    QFrame *kochFrame;
    QVBoxLayout *kochLayout;
    KochWidget *kochWidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1000, 800);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        inputLayout = new QHBoxLayout();
        inputLayout->setObjectName("inputLayout");
        nLabel = new QLabel(centralwidget);
        nLabel->setObjectName("nLabel");

        inputLayout->addWidget(nLabel);

        nSpinBox = new QSpinBox(centralwidget);
        nSpinBox->setObjectName("nSpinBox");
        nSpinBox->setMinimum(0);
        nSpinBox->setMaximum(8);
        nSpinBox->setValue(5);

        inputLayout->addWidget(nSpinBox);

        buildButton = new QPushButton(centralwidget);
        buildButton->setObjectName("buildButton");

        inputLayout->addWidget(buildButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        inputLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(inputLayout);

        iterationLabel = new QLabel(centralwidget);
        iterationLabel->setObjectName("iterationLabel");
        iterationLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(iterationLabel);

        iterationSlider = new QSlider(centralwidget);
        iterationSlider->setObjectName("iterationSlider");
        iterationSlider->setOrientation(Qt::Horizontal);
        iterationSlider->setMinimum(0);
        iterationSlider->setMaximum(5);
        iterationSlider->setValue(0);
        iterationSlider->setTickPosition(QSlider::TicksBelow);
        iterationSlider->setTickInterval(1);

        verticalLayout->addWidget(iterationSlider);

        kochFrame = new QFrame(centralwidget);
        kochFrame->setObjectName("kochFrame");
        kochFrame->setFrameShape(QFrame::StyledPanel);
        kochFrame->setFrameShadow(QFrame::Raised);
        kochLayout = new QVBoxLayout(kochFrame);
        kochLayout->setObjectName("kochLayout");
        kochWidget = new KochWidget(kochFrame);
        kochWidget->setObjectName("kochWidget");

        kochLayout->addWidget(kochWidget);


        verticalLayout->addWidget(kochFrame);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\241\320\275\320\265\320\266\320\270\320\275\320\272\320\260 \320\232\320\276\321\205\320\260", nullptr));
        nLabel->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\270\321\202\320\265\321\200\320\260\321\206\320\270\320\271:", nullptr));
        buildButton->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\321\201\321\202\321\200\320\276\320\270\321\202\321\214", nullptr));
        iterationLabel->setText(QCoreApplication::translate("MainWindow", "\320\230\321\202\320\265\321\200\320\260\321\206\320\270\321\217: 0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
