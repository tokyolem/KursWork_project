#include "AccountsPage.h"
#include "QMessageBox"
#include <vector>
#include <string>

using namespace std;

AccountsPage::AccountsPage(vector<int>accounts_id) {
	this->accounts_id = accounts_id;
}

AccountsPage::AccountsPage(QWidget * parent, Ui::QtWidgetsApplication0Class * ui, SQLdb * accounts_db) 
	: QMainWindow(parent)
{
	this->_parent = parent;
	this->ui = ui;
	this->accounts_db = accounts_db;
	connect(ui->accept, &QPushButton::clicked, this,
		[=]() {
			edit_account_login();
			edit_account_access();
			edit_account_password();
			edit_account_role();
			ui->access_box->update();
			ui->admin_box->update();
			ui->label_inf_3->setText("Changes have been made!");
			ui->label_inf_3->setGeometry(495, 489, 361, 31);
			ui->label_inf_3->setStyleSheet("color: green");
			remove_accounts();
			create_table_for_accounts();
		});
}

void AccountsPage::create_table_for_accounts() {
	ui->stackedWidget_3->setCurrentWidget(ui->page_4);
	vector<int> ids = accounts_db->get_ints(5);
	QString str;
	QPushButton* btn;

	const int START_X = 15, START_Y = 20, ADD = 245, ADD_Y = 110;

	int col = -1;
	for (int row = 0; row < ids.size(); row++) {
		str = QString::fromStdString(accounts_db->get_text("ID", to_string(ids[row]), 0));
		if (accounts_db->get_int("LOGIN", str.toStdString(), 3) == 1) {
			btn = new QPushButton(str + "\n\n(Admin account)", ui->page_4);
		}
		else {
			btn = new QPushButton(str + "\n\n(User account)", ui->page_4);
		}
		btn->setObjectName("btn_of_accounts");
		if (row % 4 == 0) {
			col++;
		}
		btn->setGeometry(START_X + ADD * (row % 4), START_Y + ADD_Y * col, 235, 100);
		if (accounts_db->get_int("LOGIN", str.toStdString(), 4) == 1) {
			btn->setStyleSheet("QPushButton{"
				"background-color: white; "
				"border-style: solid;"
				"border-width: 2px;"
				"border-radius: 20px;"
				"border-color: green;"
				"font: 14pt \"Rockwell\"; "
				"min-width: 4em;"
				"padding: 3px; }"
				"QPushButton::hover{"
				"background-color: lightGray; }");
		}
		else {
			btn->setStyleSheet("QPushButton{"
				"background-color: white; "
				"border-style: solid;"
				"border-width: 2px;"
				"border-radius: 20px;"
				"border-color: red;"
				"font: 14pt \"Rockwell\"; "
				"min-width: 4em;"
				"padding: 3px; }"
				"QPushButton::hover{"
				"background-color: lightGray; }");
		}
		
		btn->show();
		
		connect(btn, &QPushButton::clicked, this, 
			[=]() {
				ui->label_9->setText(str);
				ui->setLogin_edit->setText(str);
				open_edit_account_page();
				check_access();
				check_role();
				ui->label_inf_3->setText("");
			});
	}
}

void AccountsPage::remove_accounts() {
	qDeleteAll(ui->page_4->findChildren<QPushButton*>("btn_of_accounts"));
}

void AccountsPage::open_edit_account_page() {
	ui->stackedWidget->setCurrentWidget(ui->page_10);
}

void AccountsPage::edit_account_login() {
	string str = ui->label_9->text().toStdString();
	string input_login = ui->setLogin_edit->text().toStdString();

	accounts_db->update("LOGIN","'" + input_login + "'", "LOGIN='" + str + "'");
}

void AccountsPage::edit_account_access() {
	bool is_access = ui->access_box->isChecked();
	string str = ui->label_9->text().toStdString();

	accounts_db->update("ACCESS", to_string(is_access) , "LOGIN='" + str + "'");
}

void AccountsPage::edit_account_password() {
	CheckFields check;
	string str = ui->label_9->text().toStdString();

	string password = ui->set_password_edit->text().toStdString();
	string re_password = ui->set_password_edit_2->text().toStdString();

	if (password == "") {
		return;
	}
	else if (password == re_password) {
		string salt = check.get_generated_salt();
		string hash = check.get_generated_hash(password, salt);

		accounts_db->update("HASH", "'" + hash + "'", "LOGIN='" + str + "'");
		accounts_db->update("SALT", "'" + salt + "'", "LOGIN='" + str + "'");
	}
	else {
		QMessageBox msgBox;
		msgBox.setText("Passwords don't match!");
		msgBox.setIcon(QMessageBox::Information);
		msgBox.setInformativeText("");
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.setDefaultButton(QMessageBox::Ok);
		msgBox.setStyleSheet("QMessageBox{border: 2px solid gray; border-width: 2px; border-radius: 10px; border-color: lightGray; font: bold 14px; min-width: 10em; padding: 6px; background-color: rgb(246, 228, 255); }");
		int ret = msgBox.exec();

		switch (ret) {
		case QMessageBox::Ok:
			ui->stackedWidget->setCurrentWidget(ui->page_10);
		default:
			return ;
		}
	}
}

void AccountsPage::edit_account_role() {
	bool is_access = ui->admin_box->isChecked();
	string str = ui->label_9->text().toStdString();

	accounts_db->update("ROLE", to_string(is_access), "LOGIN='" + str + "'");
}

void AccountsPage::check_access() {
	string str = ui->label_9->text().toStdString();
	if (str == "admin") {
		ui->access_box->setEnabled(false);
	}
	else if (accounts_db->get_int("LOGIN", str, 4) == 1) {
		ui->access_box->setEnabled(true);
		ui->access_box->setChecked(true);
	}
	else {
		ui->access_box->setEnabled(true);
		ui->access_box->setChecked(false);
	}
}

void AccountsPage::check_role() {
	string str = ui->label_9->text().toStdString();
	if (str == "admin") {
		ui->admin_box->setEnabled(false);
	}
	else if (accounts_db->get_int("LOGIN", str, 3) == 1) {
		ui->admin_box->setEnabled(true);
		ui->admin_box->setChecked(true);
	}
	else {
		ui->admin_box->setEnabled(true);
		ui->admin_box->setChecked(false);
	}
}

void AccountsPage::add_new_account() {
	Account account;
	Registration registration(accounts_db, ui);
	CheckFields checkfields(ui);
	string pass_right = ui->set_repassword_reg->text().toStdString();

	account.id = registration.get_min_nonexist_id();
	account.login = ui->setLogin_reg_2->text().toStdString();
	string pass = ui->set_password_reg->text().toStdString();
	account.salt = checkfields.get_generated_salt();
	account.salted_hash_password = checkfields.get_generated_hash(pass, account.salt);
	account.access = 1;
	account.role = ui->admin_box_2->isChecked();

	if (pass == pass_right) {
		accounts_db->thrustBack({ "'" + account.login + "'",
								"'" + account.salted_hash_password + "'",
								"'" + account.salt + "'",
								to_string(account.role),
								to_string(account.access),
								to_string(account.id) });
		ui->label_inf_2->setText("Account has been added!");
		ui->label_inf_2->setStyleSheet("color: green");
	}
	else {
		ui->label_inf_2->setText("Passwords don't match!");
		ui->label_inf_2->setStyleSheet("color: red");
	}
}

void AccountsPage::find_by_login()
{
	QString str;
	vector<int> ids = accounts_db->get_ints(5);
	string search_accounts = ui->search_line->text().toStdString();
	string search_true = accounts_db->get_text("LOGIN", search_accounts, 0);

	QPushButton* btn;

	const int START_X = 15, START_Y = 10, ADD = 245, ADD_Y = 110;

	int col = -1;
	for (int row = 0; row < ids.size(); row++) {
		str = QString::fromStdString(accounts_db->get_text("ID", to_string(ids[row]), 0));
		if (accounts_db->get_int("LOGIN", str.toStdString(), 3) == 1) {
			btn = new QPushButton(str + "\n\n(Admin account)", ui->page_4);
		}
		else {
			btn = new QPushButton(str + "\n\n(User account)", ui->page_4);
		}
		btn->setObjectName("btn_of_accounts_search");
		if (row % 4 == 0) {
			col++;
		}
		btn->setGeometry(START_X, START_Y, 235, 100);
		if (accounts_db->get_int("LOGIN", str.toStdString(), 4) == 1) {
			btn->setStyleSheet("QPushButton{"
				"background-color: white; "
				"border-style: solid;"
				"border-width: 1px;"
				"border-radius: 10px;"
				"border-color: green;"
				"font: 14pt \"Rockwell\"; "
				"min-width: 4em;"
				"padding: 3px; }"
				"QPushButton::hover{"
				"background-color: lightGray; }");
		}
		else {
			btn->setStyleSheet("QPushButton{"
				"background-color: white; "
				"border-style: solid;"
				"border-width: 1px;"
				"border-radius: 10px;"
				"border-color: red;"
				"font: 14pt \"Rockwell\"; "
				"min-width: 4em;"
				"padding: 3px; }"
				"QPushButton::hover{"
				"background-color: lightGray; }");
		}

		if (search_true == str.toStdString()) {
			btn->show();
		}
		else {
			
		}
		connect(btn, &QPushButton::clicked, this,
			[=]() {
				ui->label_9->setText(str);
				ui->setLogin_edit->setText(str);
				open_edit_account_page();
				check_access();
				check_role();
				ui->label_inf_3->setText("");
			});
	}


}




