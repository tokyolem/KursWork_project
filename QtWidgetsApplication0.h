#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_QtWidgetsApplication0.h"
#include <QPainter>
#include <QLabel>
#include "Registration.h"
#include "AccountsPage.h"
#include "Session.h"

class QtWidgetsApplication0 : public QMainWindow
{
    Q_OBJECT

public:
    QtWidgetsApplication0(QWidget *parent = Q_NULLPTR);
    void set_account_db(SQLdb* accounts_db);

private slots:
    void on_Register_clicked();
    void on_Log_in_clicked();
    void on_Back_clicked();
    void on_Register_begin_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_4_clicked();
    void on_btn_clicked();
    void on_Back_2_clicked();
    
    void on_remove_acc_clicked();

    void on_accounts_edit_clicked();

    void on_Back_3_clicked();

    void on_add_account_clicked();

private:
    Ui::QtWidgetsApplication0Class ui;
    Account account;
    SQLdb* accounts_db;
    SQLdb* abonent_db;
    string session_account_login = "";
    SQLdb* sql_db;
};
