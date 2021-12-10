#pragma once
#include "CheckFields.h"

CheckFields::CheckFields(Ui::QtWidgetsApplication0Class* ui) {
	this->ui = ui;
}

using namespace std;

string CheckFields::get_password(string true_hash, string true_salt) {
	string input_password = ui->setPassword->text().toStdString();

	if (true_hash != get_generated_hash(input_password, true_salt)) { 
		return "-1";
	}
	else { // все хорошо
		return input_password;
	}
}

string CheckFields::get_generated_salt() {
	return generate_salt(SALT_SIZE);
}

string CheckFields::get_generated_hash(string line, string salt) {
	return sha1(sha1(line + salt) + sha1(line));
}

string CheckFields::get_symbols_for_salt() {
	string symbols;
	symbols.reserve(SYMBOLS_SIZE);

	char little_letter = 'a';
	char big_letter = 'A';
	char number = '0';
	for (int k = 0; k < 26; k++) {
		symbols.push_back(little_letter++);
		symbols.push_back(big_letter++);
		if (k < 10) symbols.push_back(number++);
	}

	return symbols;
}

string CheckFields::generate_salt(int salt_size) {
	string symbols = get_symbols_for_salt();

	srand(time(0));

	string salt;
	salt.reserve(salt_size);

	for (int i = 0; i < salt_size; i++) {
		salt.push_back(symbols[rand() % SYMBOLS_SIZE]);
	}

	return salt;
}

void CheckFields::ban() {
	get_symbols_for_information();
	get_symbols_for_login();
	get_symbols_for_password();
}

void CheckFields::get_symbols_for_login() {
	ui->setLogin_edit->setValidator(new QRegExpValidator(QRegExp("[a-zA-Z|0-9|_|-|.|@]{1,30}")));
	ui->setLogin_reg_2->setValidator(new QRegExpValidator(QRegExp("[a-zA-Z|0-9|_|-|.|@]{1,30}")));
}

void CheckFields::get_symbols_for_password() {
	ui->set_password_edit->setValidator(new QRegExpValidator(QRegExp("[a-zA-Z|0-9|_|!|@|#|$|%|^|&|*|(|)]{1,40}")));
	ui->set_password_edit_2->setValidator(new QRegExpValidator(QRegExp("[a-zA-Z|0-9|_|!|@|#|$|%|^|&|*|(|)]{1,40}")));
	ui->set_password_reg->setValidator(new QRegExpValidator(QRegExp("[a-zA-Z|0-9|_|!|@|#|$|%|^|&|*|(|)]{1,40}")));
	ui->set_repassword_reg->setValidator(new QRegExpValidator(QRegExp("[a-zA-Z|0-9|_|!|@|#|$|%|^|&|*|(|)]{1,40}")));
}

void CheckFields::get_symbols_for_information() {
	ui->number_of_garten->setValidator(new QRegExpValidator(QRegExp("[a-zA-Z| |0-9]{1,50}")));
	ui->certain_place->setValidator(new QRegExpValidator(QRegExp("[a-zA-Z| |,]{1,25}")));
	ui->affiliation->setValidator(new QRegExpValidator(QRegExp("[a-zA-Z]{1,25}")));
	ui->certain_place_3->setValidator(new QRegExpValidator(QRegExp("[a-zA-Z| |,]{1,25}")));
	ui->affiliation_3->setValidator(new QRegExpValidator(QRegExp("[a-zA-Z]{1,25}")));
	ui->number_of_garten_3->setValidator(new QRegExpValidator(QRegExp("[a-zA-Z| |0-9]{1,50}")));
	ui->free_places->setValidator(new QRegExpValidator(QRegExp("[0-9]{1,5}")));
	ui->free_places_3->setValidator(new QRegExpValidator(QRegExp("[0-9]{1,5}")));
	ui->quanity_of_group->setValidator(new QRegExpValidator(QRegExp("[0-9]{1,5}")));
	ui->quanity_of_group_3->setValidator(new QRegExpValidator(QRegExp("[0-9]{1,5}")));
	ui->quanity_of_places->setValidator(new QRegExpValidator(QRegExp("[0-9]{1,7}")));
	ui->quanity_of_places_3->setValidator(new QRegExpValidator(QRegExp("[0-9]{1,7}")));
}

