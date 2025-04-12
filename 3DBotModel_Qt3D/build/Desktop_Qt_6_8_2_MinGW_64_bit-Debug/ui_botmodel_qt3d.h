/********************************************************************************
** Form generated from reading UI file 'botmodel_qt3d.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOTMODEL_QT3D_H
#define UI_BOTMODEL_QT3D_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BotModel_Qt3D
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *BotModel_Qt3D)
    {
        if (BotModel_Qt3D->objectName().isEmpty())
            BotModel_Qt3D->setObjectName("BotModel_Qt3D");
        BotModel_Qt3D->resize(800, 600);
        centralwidget = new QWidget(BotModel_Qt3D);
        centralwidget->setObjectName("centralwidget");
        BotModel_Qt3D->setCentralWidget(centralwidget);
        menubar = new QMenuBar(BotModel_Qt3D);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        BotModel_Qt3D->setMenuBar(menubar);
        statusbar = new QStatusBar(BotModel_Qt3D);
        statusbar->setObjectName("statusbar");
        BotModel_Qt3D->setStatusBar(statusbar);

        retranslateUi(BotModel_Qt3D);

        QMetaObject::connectSlotsByName(BotModel_Qt3D);
    } // setupUi

    void retranslateUi(QMainWindow *BotModel_Qt3D)
    {
        BotModel_Qt3D->setWindowTitle(QCoreApplication::translate("BotModel_Qt3D", "BotModel_Qt3D", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BotModel_Qt3D: public Ui_BotModel_Qt3D {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOTMODEL_QT3D_H
