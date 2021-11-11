/********************************************************************************
** Form generated from reading UI file 'QtWidgetsApplication0.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTWIDGETSAPPLICATION0_H
#define UI_QTWIDGETSAPPLICATION0_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtWidgetsApplication0Class
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtWidgetsApplication0Class)
    {
        if (QtWidgetsApplication0Class->objectName().isEmpty())
            QtWidgetsApplication0Class->setObjectName(QStringLiteral("QtWidgetsApplication0Class"));
        QtWidgetsApplication0Class->resize(600, 400);
        menuBar = new QMenuBar(QtWidgetsApplication0Class);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        QtWidgetsApplication0Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtWidgetsApplication0Class);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QtWidgetsApplication0Class->addToolBar(mainToolBar);
        centralWidget = new QWidget(QtWidgetsApplication0Class);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QtWidgetsApplication0Class->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(QtWidgetsApplication0Class);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QtWidgetsApplication0Class->setStatusBar(statusBar);

        retranslateUi(QtWidgetsApplication0Class);

        QMetaObject::connectSlotsByName(QtWidgetsApplication0Class);
    } // setupUi

    void retranslateUi(QMainWindow *QtWidgetsApplication0Class)
    {
        QtWidgetsApplication0Class->setWindowTitle(QApplication::translate("QtWidgetsApplication0Class", "QtWidgetsApplication0", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QtWidgetsApplication0Class: public Ui_QtWidgetsApplication0Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTWIDGETSAPPLICATION0_H
