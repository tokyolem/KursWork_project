#pragma once
#include "QtWidgetsApplication0.h"
#include "Users.h"
#include <QtWidgets/QMainWindow>
#include "SQLDataBase.h"


class AccountsPage : public QMainWindow
{
	Q_OBJECT
public :
	AccountsPage(QWidget* parent, Ui::QtWidgetsApplication0Class* ui, SQLdb* accounts_db);

	void create_table_for_accounts();
	void remove_accounts();
	void open_edit_account_page();
	void edit_account_login();
	void edit_account_access();
	void edit_account_password();

private:
	QWidget* _parent;
	Ui::QtWidgetsApplication0Class* ui;
	SQLdb* accounts_db;
	QPushButton* btn;
	string session_account_login = "";
};

