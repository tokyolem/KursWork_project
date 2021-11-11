#include "registration.h"

Registration::Registration(SQLdb* sql_db, Ui::QtWidgetsApplication0Class* ui) {
	this->sql_db = sql_db;
	this->ui = ui;
}

Registration::Registration(vector<int>accounts_id) {
	this->accounts_id = accounts_id;
}

int Registration::get_min_nonexist_id() {
	accounts_id = sql_db->get_ints(5);
	int min_nonexistent = 1;
	if (accounts_id.size() != 0) {
		for (int i = 0; i < *max_element(accounts_id.begin(), accounts_id.end()), +2; i++) {
			if (accounts_id.end() == find(accounts_id.begin(), accounts_id.end(), min_nonexistent)) {
				break;
			}
			min_nonexistent++;
		}
	}
	return min_nonexistent;
}

void Registration::begin() {
	CheckFields checkFields(ui);
	
	string pass_right = ui->RePassword->text().toStdString();

	account.id = get_min_nonexist_id();
	account.login = checkFields.get_free_login(sql_db);
	string pass = ui->setPasswordReg->text().toStdString();
	account.salt = checkFields.get_generated_salt();
	account.salted_hash_password = checkFields.get_generated_hash(pass, account.salt);

	if (pass_right != pass) {
		ui->label_5->setText("Passwords don't match! Make sure that the input is valid.");
	}
	else {
		ui->label_5->setText("Account has been registred");
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
