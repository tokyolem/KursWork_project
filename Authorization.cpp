#pragma once
#include "Authorization.h"

Authorization::Authorization(SQLdb* sql_db, Ui::QtWidgetsApplication0Class* ui) {
	this->sql_db = sql_db;
	this->ui = ui;
}

// запуск начала авторизации, возвращает роль
int Authorization::begin() {

	CheckFields checkFields(ui);
	string input_login, db_account_hash, db_account_salt, input_password;

	while (true) {
		input_login = ui->setLogin->text().toStdString();
		//input_login = checkFields.get_login(sql_db);
		
		db_account_hash = sql_db->get_text("LOGIN", input_login, 1);
		db_account_salt = sql_db->get_text("LOGIN", input_login, 2);
		input_password = ui->setPassword->text().toStdString();
		input_password = checkFields.get_password(db_account_hash, db_account_salt);


		if (input_password == "-1") {
		ui->label_inf->setText("Invalid username or password");
		ui->label_inf->setStyleSheet("color:red");
		ui->stackedWidget->setCurrentWidget(ui->main_first);
		return -1;
		}
		else if (sql_db->get_int("LOGIN", input_login, 4) == 0) {
			QMessageBox msgBox;

			ui->label_inf->setText("Account has not been confirmed");
			ui->label_inf->setStyleSheet("color:red");
			// Заголовок сообщения
			msgBox.setText("Oops...");
			// Тип иконки сообщения
			msgBox.setIcon(QMessageBox::Information);
			// Основное сообщение Message Box
			msgBox.setInformativeText("");
			// Добавление реагирования на софт клавиши
			msgBox.setStandardButtons(QMessageBox::Ok);
			// На какой кнопке фокусироваться по умолчанию
			msgBox.setDefaultButton(QMessageBox::Ok);
			msgBox.setStyleSheet("QMessageBox {"
				"border-style: solid;"
				"border-color: rgb(85,0,0);"
				"background-color: rgb(255, 236, 220);"
				"font: 12pt \"Rockwell\"; }"
				"QPushButton {"
				"background-color: rgb(255, 236, 220);"
				"border-style: solid;"
				"border-width: 3px;"
				"border-radius: 15px;"
				"border-color: rgb(85, 0, 0);"
				"color: rgb(85, 0, 0);"
				"font: 14pt \"Rockwell\"; "
				"min-width: 1em;"
				"padding: 3px; }"
				"QPushButton::hover{"
				"background-color: rgb(255, 239, 250);"
				"border-style: solid;"
				"border-color: rgb(180, 155, 255);"
				"color: rgb(180, 155, 255); }");
			int ret = msgBox.exec();

			switch (ret) {
			case QMessageBox::Ok:
				ui->stackedWidget->setCurrentWidget(ui->main_first);
			default:
				return -1;
			}

		}
		else {
			break;
		}
	}

	this->login = input_login;
	return sql_db->get_int("LOGIN", input_login, 3);
}


string Authorization::get_login() {
	return this->login;
}
