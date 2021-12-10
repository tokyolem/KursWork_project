#include "Registration.h"

Registration::Registration(SQLdb* sql_db, Ui::QtWidgetsApplication0Class* ui)
{
	this->sql_db = sql_db;
	this->ui = ui;
}

Registration::Registration(vector<int>accounts_id) {
	this->accounts_id = accounts_id;
}

void Registration::begin() {
	CheckFields checkFields(ui);
	accounts_id = sql_db->get_ints(5);
	
	string pass_right = ui->RePassword->text().toStdString();
	
	account.id = get_min_nonexist(accounts_id);
	account.login = ui->setLoginReg->text().toStdString();
	string pass = ui->setPasswordReg->text().toStdString();
	account.salt = checkFields.get_generated_salt();
	account.salted_hash_password = checkFields.get_generated_hash(pass, account.salt);

	if (pass_right != pass) {
		ui->label_5->setText("Passwords don't match!");
		ui->label_5->setGeometry(785, 540, 321, 31);
	}
	else {
		ui->label_5->setText("Account has been registred");
		ui->label_5->setGeometry(770, 540, 321, 31);
		add_account_to_data_base();
	}
	
}

void Registration::add_account_to_data_base() {
	sql_db->thrustBack({ "'" + account.login + "'",
						"'" + account.salted_hash_password + "'",
						"'" + account.salt + "'",
					   to_string(account.role),
					   to_string(account.access),
					   to_string(account.id) });
}
