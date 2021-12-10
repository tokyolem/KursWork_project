#pragma once
#include "ui_QtWidgetsApplication0.h"
#include <QDebug>
#include <QStackedWidget>
#include <QMessageBox>
#include <iostream>
#include "registration.h"
#include "Authorization.h"
#include "QtWidgetsApplication0.h"


class Session
{
public:
	Session(SQLdb* accounts_db, SQLdb* garten_db, Ui::QtWidgetsApplication0Class* ui);
	void start_as_admin(string login);
	void start_as_user(string login);

private:
	Ui::QtWidgetsApplication0Class* ui;
	SQLdb* sql_db = 0;
	string session_account_login = "";
	SQLdb* garten_db = nullptr;
	SQLdb* accounts_db = nullptr;
};

