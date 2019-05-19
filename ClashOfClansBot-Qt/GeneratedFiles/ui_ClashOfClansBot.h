/********************************************************************************
** Form generated from reading UI file 'ClashOfClansBot.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLASHOFCLANSBOT_H
#define UI_CLASHOFCLANSBOT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClashOfClansBotClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QGraphicsView *graphicsView;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ClashOfClansBotClass)
    {
        if (ClashOfClansBotClass->objectName().isEmpty())
            ClashOfClansBotClass->setObjectName(QStringLiteral("ClashOfClansBotClass"));
        ClashOfClansBotClass->resize(600, 400);
        centralWidget = new QWidget(ClashOfClansBotClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));

        verticalLayout->addWidget(graphicsView);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);


        gridLayout->addLayout(verticalLayout, 1, 2, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(72, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(72, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 3, 1, 1);

        verticalSpacer = new QSpacerItem(20, 42, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(72, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 4, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(72, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 1, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 42, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 2, 1, 1);

        ClashOfClansBotClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ClashOfClansBotClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 23));
        ClashOfClansBotClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ClashOfClansBotClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ClashOfClansBotClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ClashOfClansBotClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ClashOfClansBotClass->setStatusBar(statusBar);

        retranslateUi(ClashOfClansBotClass);

        QMetaObject::connectSlotsByName(ClashOfClansBotClass);
    } // setupUi

    void retranslateUi(QMainWindow *ClashOfClansBotClass)
    {
        ClashOfClansBotClass->setWindowTitle(QApplication::translate("ClashOfClansBotClass", "ClashOfClansBot", Q_NULLPTR));
        pushButton->setText(QApplication::translate("ClashOfClansBotClass", "PushButton", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ClashOfClansBotClass: public Ui_ClashOfClansBotClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLASHOFCLANSBOT_H
