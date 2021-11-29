#pragma once
#include "QtWidgetsApplication0.h"
#include "Users.h"
#include <QtWidgets/QMainWindow>
#include "SQLDataBase.h"
#include <iostream>


class AccountsPage : public QMainWindow
{
	Q_OBJECT
public :
	AccountsPage(QWidget* parent, Ui::QtWidgetsApplication0Class* ui, SQLdb* accounts_db);
	AccountsPage(vector<int>accounts_id);

	void create_table_for_accounts();
	void remove_accounts();
	void open_edit_account_page();
	void edit_account_login();
	void edit_account_access();
	void edit_account_password();
	void edit_account_role();
	void check_access();
	void add_new_account();
	void check_role();
	void find_by_login();
	

private:
	
	QWidget* _parent;
	Ui::QtWidgetsApplication0Class* ui;
	SQLdb* accounts_db = nullptr;
	vector<int>accounts_id;
};

