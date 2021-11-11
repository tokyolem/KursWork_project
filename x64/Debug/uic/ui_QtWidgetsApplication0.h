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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtWidgetsApplication0Class
{
public:
    QWidget *centralWidget;
    QStackedWidget *stackedWidget;
    QWidget *main_first;
    QLabel *label;
    QLineEdit *setPassword;
    QLineEdit *setLogin;
    QLabel *question;
    QPushButton *Register;
    QPushButton *Log_in;
    QLabel *label_4;
    QLabel *label_2;
    QLabel *label_inf;
    QLabel *label_6;
    QWidget *main_second;
    QPushButton *Back;
    QLabel *label_3;
    QLineEdit *setPasswordReg;
    QLineEdit *setLoginReg;
    QPushButton *Register_begin;
    QLineEdit *RePassword;
    QLabel *label_5;
    QLabel *label_8;
    QWidget *page;
    QStackedWidget *stackedWidget_2;
    QWidget *page_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QWidget *page_3;
    QStackedWidget *stackedWidget_3;
    QWidget *page_4;
    QWidget *page_5;
    QWidget *page_10;
    QLabel *label_7;
    QPushButton *Back_2;
    QLineEdit *setLogin_2;
    QWidget *user_menu;
    QStackedWidget *stackedWidget_4;
    QWidget *page_6;
    QWidget *page_7;
    QStackedWidget *stackedWidget_5;
    QWidget *page_8;
    QWidget *page_9;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *QtWidgetsApplication0Class)
    {
        if (QtWidgetsApplication0Class->objectName().isEmpty())
            QtWidgetsApplication0Class->setObjectName(QStringLiteral("QtWidgetsApplication0Class"));
        QtWidgetsApplication0Class->resize(1280, 680);
        centralWidget = new QWidget(QtWidgetsApplication0Class);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, -40, 1280, 720));
        stackedWidget->setStyleSheet(QStringLiteral("background-color: rgb(246, 228, 255);"));
        main_first = new QWidget();
        main_first->setObjectName(QStringLiteral("main_first"));
        label = new QLabel(main_first);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(630, 90, 621, 551));
        label->setPixmap(QPixmap(QString::fromUtf8("../../../../Desktop/\320\241\320\275\320\270\320\274\320\276\320\272 \321\215\320\272\321\200\320\260\320\275\320\260 2021-11-05 011636.png")));
        setPassword = new QLineEdit(main_first);
        setPassword->setObjectName(QStringLiteral("setPassword"));
        setPassword->setGeometry(QRect(780, 260, 351, 51));
        setPassword->setStyleSheet(QLatin1String("background-color: white;\n"
"     border: 2px solid gray;\n"
"     border-width: 2px;\n"
"     border-radius: 10px;\n"
"     border-color: lightGray;\n"
"     font: bold 14px;\n"
"     min-width: 10em;\n"
"     padding: 6px;"));
        setPassword->setEchoMode(QLineEdit::Password);
        setPassword->setClearButtonEnabled(true);
        setLogin = new QLineEdit(main_first);
        setLogin->setObjectName(QStringLiteral("setLogin"));
        setLogin->setGeometry(QRect(780, 200, 351, 51));
        setLogin->setStyleSheet(QLatin1String("background-color: white;\n"
"     border: 2px solid gray;\n"
"     border-width: 2px;\n"
"     border-radius: 10px;\n"
"     border-color: lightGray;\n"
"     font: bold 14px;\n"
"     min-width: 10em;\n"
"     padding: 6px;"));
        setLogin->setClearButtonEnabled(true);
        question = new QLabel(main_first);
        question->setObjectName(QStringLiteral("question"));
        question->setGeometry(QRect(840, 469, 111, 31));
        QFont font;
        font.setFamily(QStringLiteral("Rockwell"));
        font.setPointSize(12);
        question->setFont(font);
        Register = new QPushButton(main_first);
        Register->setObjectName(QStringLiteral("Register"));
        Register->setGeometry(QRect(950, 469, 131, 31));
        Register->setFont(font);
        Register->setCursor(QCursor(Qt::PointingHandCursor));
        Register->setStyleSheet(QLatin1String("background_color: rgba(255,255,255,0);\n"
"border: none;\n"
"color: blue;"));
        Log_in = new QPushButton(main_first);
        Log_in->setObjectName(QStringLiteral("Log_in"));
        Log_in->setGeometry(QRect(780, 340, 351, 41));
        QFont font1;
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        Log_in->setFont(font1);
        Log_in->setStyleSheet(QLatin1String("background-color: white;\n"
"border-style: solid;\n"
"border-width: 2px;\n"
"border-radius: 10px;\n"
"border-color: lightGray;\n"
"font: bold 14px;\n"
"min-width: 10em;\n"
"padding: 6px;\n"
"\n"
""));
        label_4 = new QLabel(main_first);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(160, 150, 361, 371));
        label_4->setPixmap(QPixmap(QString::fromUtf8("../../../../Downloads/rounded-in-photoretrica (1).png")));
        label_2 = new QLabel(main_first);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 650, 1111, 41));
        label_2->setStyleSheet(QStringLiteral("font: 75 12pt \"Rockwell\";"));
        label_inf = new QLabel(main_first);
        label_inf->setObjectName(QStringLiteral("label_inf"));
        label_inf->setGeometry(QRect(840, 410, 231, 31));
        label_inf->setFont(font);
        label_6 = new QLabel(main_first);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(890, 110, 181, 71));
        QFont font2;
        font2.setFamily(QStringLiteral("Rockwell"));
        font2.setPointSize(28);
        label_6->setFont(font2);
        stackedWidget->addWidget(main_first);
        main_second = new QWidget();
        main_second->setObjectName(QStringLiteral("main_second"));
        Back = new QPushButton(main_second);
        Back->setObjectName(QStringLiteral("Back"));
        Back->setGeometry(QRect(20, 50, 116, 51));
        QFont font3;
        font3.setFamily(QStringLiteral("Rockwell"));
        font3.setPointSize(14);
        font3.setBold(false);
        font3.setItalic(false);
        font3.setWeight(50);
        Back->setFont(font3);
        Back->setFocusPolicy(Qt::StrongFocus);
        Back->setStyleSheet(QLatin1String("background-color: white;\n"
"\n"
"     border-style: solid;\n"
"     border-width: 3px;\n"
"     border-radius: 10px;\n"
"     border-color: lightGray;\n"
" \n"
"font: 14pt \"Rockwell\";\n"
"     min-width: 4em;\n"
"     padding: 3px;\n"
"\n"
""));
        Back->setAutoRepeat(false);
        label_3 = new QLabel(main_second);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(320, 60, 821, 611));
        label_3->setPixmap(QPixmap(QString::fromUtf8("../../../../Desktop/\320\241\320\275\320\270\320\274\320\276\320\272 \321\215\320\272\321\200\320\260\320\275\320\260 2021-11-05 011636.png")));
        setPasswordReg = new QLineEdit(main_second);
        setPasswordReg->setObjectName(QStringLiteral("setPasswordReg"));
        setPasswordReg->setGeometry(QRect(470, 290, 351, 51));
        setPasswordReg->setStyleSheet(QLatin1String("background-color: white;\n"
"     border: 2px solid gray;\n"
"     border-width: 3px;\n"
"     border-radius: 10px;\n"
"     border-color: lightGray;\n"
"     font: bold 14px;\n"
"     min-width: 10em;\n"
"     padding: 6px;"));
        setPasswordReg->setEchoMode(QLineEdit::Password);
        setPasswordReg->setClearButtonEnabled(true);
        setLoginReg = new QLineEdit(main_second);
        setLoginReg->setObjectName(QStringLiteral("setLoginReg"));
        setLoginReg->setGeometry(QRect(470, 210, 351, 51));
        setLoginReg->setStyleSheet(QLatin1String("background-color: white;\n"
"     border: 3px solid gray;\n"
"     border-width: 2px;\n"
"     border-radius: 10px;\n"
"     border-color: lightGray;\n"
"     font: bold 14px;\n"
"     min-width: 10em;\n"
"     padding: 6px;"));
        setLoginReg->setClearButtonEnabled(true);
        Register_begin = new QPushButton(main_second);
        Register_begin->setObjectName(QStringLiteral("Register_begin"));
        Register_begin->setGeometry(QRect(470, 440, 351, 41));
        QFont font4;
        font4.setFamily(QStringLiteral("Rockwell"));
        font4.setPointSize(12);
        font4.setBold(false);
        font4.setItalic(false);
        font4.setWeight(50);
        Register_begin->setFont(font4);
        Register_begin->setStyleSheet(QLatin1String("background-color: white;\n"
"\n"
"     border-style: solid;\n"
"     border-width: 3px;\n"
"     border-radius: 10px;\n"
"     border-color: lightGray;\n"
"   font: 12pt \"Rockwell\";\n"
"     min-width: 10em;\n"
"     padding: 6px;\n"
"\n"
""));
        RePassword = new QLineEdit(main_second);
        RePassword->setObjectName(QStringLiteral("RePassword"));
        RePassword->setGeometry(QRect(470, 370, 351, 51));
        RePassword->setStyleSheet(QLatin1String("background-color: white;\n"
"     border: 2px solid gray;\n"
"     border-width: 3px;\n"
"     border-radius: 10px;\n"
"     border-color: lightGray;\n"
"     font: bold 14px;\n"
"     min-width: 10em;\n"
"     padding: 6px;"));
        RePassword->setEchoMode(QLineEdit::Password);
        RePassword->setClearButtonEnabled(true);
        label_5 = new QLabel(main_second);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(490, 510, 351, 31));
        label_5->setFont(font);
        label_8 = new QLabel(main_second);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(530, 555, 261, 31));
        stackedWidget->addWidget(main_second);
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        stackedWidget_2 = new QStackedWidget(page);
        stackedWidget_2->setObjectName(QStringLiteral("stackedWidget_2"));
        stackedWidget_2->setGeometry(QRect(-1, 39, 281, 720));
        stackedWidget_2->setStyleSheet(QStringLiteral("background-color: rgb(255, 254, 234);"));
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        pushButton_4 = new QPushButton(page_2);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(10, 50, 261, 61));
        pushButton_4->setStyleSheet(QLatin1String("background-color: white;\n"
"font: 16pt \"Rockwell\";\n"
"\n"
"     border-style: solid;\n"
"     border-width: 2px;\n"
"     border-radius: 10px;\n"
"     border-color: lightGray;\n"
"    \n"
"     min-width: 6em;\n"
"     padding: 3px;\n"
"\n"
"\n"
""));
        pushButton_5 = new QPushButton(page_2);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(10, 140, 261, 61));
        pushButton_5->setStyleSheet(QLatin1String("background-color: white;\n"
"font: 16pt \"Rockwell\";\n"
"\n"
"     border-style: solid;\n"
"     border-width: 2px;\n"
"     border-radius: 10px;\n"
"     border-color: lightGray;\n"
"    \n"
"     min-width: 6em;\n"
"     padding: 3px;\n"
""));
        pushButton_6 = new QPushButton(page_2);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(10, 230, 261, 61));
        pushButton_6->setStyleSheet(QLatin1String("background-color: white;\n"
"font: 16pt \"Rockwell\";\n"
"\n"
"     border-style: solid;\n"
"     border-width: 2px;\n"
"     border-radius: 10px;\n"
"     border-color: lightGray;\n"
"    \n"
"     min-width: 6em;\n"
"     padding: 3px;\n"
""));
        pushButton_7 = new QPushButton(page_2);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(10, 320, 261, 61));
        pushButton_7->setStyleSheet(QLatin1String("background-color: white;\n"
"font: 16pt \"Rockwell\";\n"
"\n"
"     border-style: solid;\n"
"     border-width: 2px;\n"
"     border-radius: 10px;\n"
"     border-color: lightGray;\n"
"    \n"
"     min-width: 6em;\n"
"     padding: 3px;\n"
""));
        pushButton_8 = new QPushButton(page_2);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(90, 590, 103, 41));
        pushButton_8->setStyleSheet(QLatin1String("background-color: white;\n"
"font: 16pt \"Rockwell\";\n"
"\n"
"     border-style: solid;\n"
"     border-width: 2px;\n"
"     border-radius: 10px;\n"
"     border-color: lightGray;\n"
"    \n"
"     min-width: 3em;\n"
"     padding: 3px;\n"
""));
        stackedWidget_2->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        stackedWidget_2->addWidget(page_3);
        stackedWidget_3 = new QStackedWidget(page);
        stackedWidget_3->setObjectName(QStringLiteral("stackedWidget_3"));
        stackedWidget_3->setGeometry(QRect(279, 39, 1001, 720));
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        stackedWidget_3->addWidget(page_4);
        page_5 = new QWidget();
        page_5->setObjectName(QStringLiteral("page_5"));
        stackedWidget_3->addWidget(page_5);
        stackedWidget->addWidget(page);
        page_10 = new QWidget();
        page_10->setObjectName(QStringLiteral("page_10"));
        label_7 = new QLabel(page_10);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(440, 70, 141, 31));
        QFont font5;
        font5.setFamily(QStringLiteral("Rockwell"));
        font5.setPointSize(14);
        label_7->setFont(font5);
        Back_2 = new QPushButton(page_10);
        Back_2->setObjectName(QStringLiteral("Back_2"));
        Back_2->setGeometry(QRect(30, 60, 116, 51));
        Back_2->setFont(font3);
        Back_2->setFocusPolicy(Qt::StrongFocus);
        Back_2->setStyleSheet(QLatin1String("background-color: white;\n"
"\n"
"     border-style: solid;\n"
"     border-width: 3px;\n"
"     border-radius: 10px;\n"
"     border-color: lightGray;\n"
" \n"
"font: 14pt \"Rockwell\";\n"
"     min-width: 4em;\n"
"     padding: 3px;\n"
"\n"
""));
        Back_2->setAutoRepeat(false);
        setLogin_2 = new QLineEdit(page_10);
        setLogin_2->setObjectName(QStringLiteral("setLogin_2"));
        setLogin_2->setGeometry(QRect(420, 190, 351, 51));
        setLogin_2->setStyleSheet(QLatin1String("background-color: white;\n"
"     border: 2px solid gray;\n"
"     border-width: 2px;\n"
"     border-radius: 10px;\n"
"     border-color: lightGray;\n"
"     font: bold 14px;\n"
"     min-width: 10em;\n"
"     padding: 6px;"));
        setLogin_2->setClearButtonEnabled(true);
        stackedWidget->addWidget(page_10);
        user_menu = new QWidget();
        user_menu->setObjectName(QStringLiteral("user_menu"));
        stackedWidget_4 = new QStackedWidget(user_menu);
        stackedWidget_4->setObjectName(QStringLiteral("stackedWidget_4"));
        stackedWidget_4->setGeometry(QRect(-1, 39, 281, 720));
        stackedWidget_4->setStyleSheet(QStringLiteral("background-color: rgb(255, 254, 234);"));
        page_6 = new QWidget();
        page_6->setObjectName(QStringLiteral("page_6"));
        stackedWidget_4->addWidget(page_6);
        page_7 = new QWidget();
        page_7->setObjectName(QStringLiteral("page_7"));
        stackedWidget_4->addWidget(page_7);
        stackedWidget_5 = new QStackedWidget(user_menu);
        stackedWidget_5->setObjectName(QStringLiteral("stackedWidget_5"));
        stackedWidget_5->setGeometry(QRect(279, 39, 1001, 720));
        page_8 = new QWidget();
        page_8->setObjectName(QStringLiteral("page_8"));
        stackedWidget_5->addWidget(page_8);
        page_9 = new QWidget();
        page_9->setObjectName(QStringLiteral("page_9"));
        stackedWidget_5->addWidget(page_9);
        stackedWidget->addWidget(user_menu);
        QtWidgetsApplication0Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QtWidgetsApplication0Class);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1280, 26));
        QtWidgetsApplication0Class->setMenuBar(menuBar);

        retranslateUi(QtWidgetsApplication0Class);

        stackedWidget_2->setCurrentIndex(0);
        stackedWidget_3->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(QtWidgetsApplication0Class);
    } // setupUi

    void retranslateUi(QMainWindow *QtWidgetsApplication0Class)
    {
        QtWidgetsApplication0Class->setWindowTitle(QApplication::translate("QtWidgetsApplication0Class", "QtWidgetsApplication0", Q_NULLPTR));
        label->setText(QString());
        question->setText(QApplication::translate("QtWidgetsApplication0Class", "No account? Register now", Q_NULLPTR));
        Register->setText(QApplication::translate("QtWidgetsApplication0Class", "Register now", Q_NULLPTR));
        Log_in->setText(QApplication::translate("QtWidgetsApplication0Class", "Log in", Q_NULLPTR));
        label_4->setText(QString());
#ifndef QT_NO_TOOLTIP
        label_2->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        label_2->setText(QApplication::translate("QtWidgetsApplication0Class", "This program is designed to take into account the availability of places in kindergartens and is not a commercial project.", Q_NULLPTR));
        label_inf->setText(QString());
        label_6->setText(QApplication::translate("QtWidgetsApplication0Class", "Log in", Q_NULLPTR));
        Back->setText(QApplication::translate("QtWidgetsApplication0Class", "Back", Q_NULLPTR));
        label_3->setText(QString());
        Register_begin->setText(QApplication::translate("QtWidgetsApplication0Class", "Register", Q_NULLPTR));
        label_5->setText(QString());
        label_8->setText(QString());
        pushButton_4->setText(QApplication::translate("QtWidgetsApplication0Class", "Manage accounts", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("QtWidgetsApplication0Class", "Manage data", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("QtWidgetsApplication0Class", "PushButton", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("QtWidgetsApplication0Class", "PushButton", Q_NULLPTR));
        pushButton_8->setText(QApplication::translate("QtWidgetsApplication0Class", "Log out", Q_NULLPTR));
        label_7->setText(QApplication::translate("QtWidgetsApplication0Class", "Edit account:", Q_NULLPTR));
        Back_2->setText(QApplication::translate("QtWidgetsApplication0Class", "Back", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QtWidgetsApplication0Class: public Ui_QtWidgetsApplication0Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTWIDGETSAPPLICATION0_H
