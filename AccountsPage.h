#pragma once
#include "QtWidgetsApplication0.h"
#include "Users.h"
#include <QtWidgets/QMainWindow>
#include "SQLDataBase.h"
#include <iostream>
#include "Page.h"


class AccountsPage : public QMainWindow, public Page
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
	void delete_account();
	void remove_accounts_search();
	virtual void update_window() {};

private:
	string session_account_login = "";
	QWidget* _parent;
	Ui::QtWidgetsApplication0Class* ui;
	SQLdb* accounts_db = nullptr;
	vector<int>accounts_id;
};

