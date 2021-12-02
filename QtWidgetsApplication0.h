#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_QtWidgetsApplication0.h"
#include <QPainter>
#include <QLabel>
#include "Registration.h"
#include "AccountsPage.h"
#include "Session.h"
#include "Data.h"
#include "GartenPage.h"
#include "GartensInfo.h"
#include "UserGartensPage.h"


class QtWidgetsApplication0 : public QMainWindow
{
    Q_OBJECT

public:
    QtWidgetsApplication0(QWidget *parent = Q_NULLPTR);
    void set_account_db(SQLdb* accounts_db);
    void set_garten_db(SQLdb* garten);

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
    void on_pushButton_5_clicked();
    void on_add_new_garten_clicked();
    void on_add_account_2_clicked();
    void on_Back_4_clicked();
    void on_Back_9_clicked();
    void on_search_acc_clicked();
    void on_pushButton_10_clicked();
    void on_delete_gart_clicked();
    void on_Back_10_clicked();

private:
    Ui::QtWidgetsApplication0Class ui;
    Account account;
    Gartens* gartens;
    SQLdb* accounts_db;
    SQLdb* garten_db;
    string session_account_login = "";
    SQLdb* sql_db;

};
