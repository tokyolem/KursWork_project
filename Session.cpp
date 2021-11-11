#pragma once
#include "Session.h"

Session::Session(SQLdb* accounts_db, SQLdb* abonent_db, Ui::QtWidgetsApplication0Class* ui) {
	this->accounts_db = accounts_db;
	this->abonent_db = abonent_db;
	this->ui = ui;
}

void Session::start_as_admin(string login) {
	this->session_account_login = login;
	ui->stackedWidget->setCurrentWidget(ui->page);
}

void Session::start_as_user(string login) {
	this->session_account_login = login;
	ui->stackedWidget->setCurrentWidget(ui->user_menu);
}
