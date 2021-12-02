#pragma once
#include "Session.h"

Session::Session(SQLdb* accounts_db, SQLdb* abonent_db, Ui::QtWidgetsApplication0Class* ui) {
	this->accounts_db = accounts_db;
	this->garten_db = abonent_db;
	this->ui = ui;
}

void Session::start_as_admin(string login) {
	this->session_account_login = login;
	ui->stackedWidget->setCurrentWidget(ui->page);
	ui->pushButton_4->setVisible(true);
	ui->pushButton_5->setVisible(true);
	ui->search_acc->setVisible(true);
	ui->accounts_edit->setVisible(true);
	ui->search_line->setVisible(true);
	ui->add_new_garten->setVisible(true);
	ui->pushButton_10->setGeometry(10, 210, 261, 91);
}

void Session::start_as_user(string login) {
	this->session_account_login = login;
	ui->stackedWidget->setCurrentWidget(ui->page);
	ui->pushButton_4->setVisible(false);
	ui->pushButton_5->setVisible(false);
	ui->pushButton_10->setGeometry(10, 10, 261, 91);
	ui->search_acc->setVisible(false);
	ui->accounts_edit->setVisible(false);
	ui->search_line->setVisible(false);
	ui->add_new_garten->setVisible(false);
}
