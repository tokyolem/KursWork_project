#pragma once
#include <iostream>
#include "users.h"
#include "SQLDataBase.h"
#include "QtWidgetsApplication0.h"
#include "CheckFields.h"
#include "Page.h"

using namespace std;

class Registration : public QMainWindow, public Page
{
public:
	Registration(SQLdb* sql_db, Ui::QtWidgetsApplication0Class* ui);
	Registration(vector<int>accounts_id);
	void begin();
	virtual void update_window() {};

private:
	SQLdb* sql_db = nullptr;
	Account account;
	void add_account_to_data_base();
	Ui::QtWidgetsApplication0Class* ui;
	vector<int>accounts_id;

};