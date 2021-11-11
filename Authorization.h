#pragma once
#include <iostream>
#include "SQLDataBase.h"
#include <string>
#include "CheckFields.h"
#include "QtWidgetsApplication0.h"
#include "Users.h"
#include <QTextCodec>


using namespace std;


class Authorization
{
public:
	Authorization(SQLdb* sql_db, Ui::QtWidgetsApplication0Class* ui);

	string get_login();
	int begin();


private:
	SQLdb* sql_db = nullptr;
	string login = "";
	Ui::QtWidgetsApplication0Class* ui;
};