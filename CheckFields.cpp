#pragma once
#include "CheckFields.h"

CheckFields::CheckFields(Ui::QtWidgetsApplication0Class* ui) {
	this->ui = ui;
}

using namespace std;

string CheckFields::get_login(SQLdb* db) {
	string input_login;
	input_login = ui->setLogin->text().toStdString();
	while (true) {


		if (input_login.size() < 4) {
			QMessageBox msgBox;
			msgBox.setText("Внимание!");
			msgBox.setIcon(QMessageBox::Information);
			msgBox.setInformativeText("Слишком маленький логин!");
			msgBox.setStandardButtons(QMessageBox::Ok);
			msgBox.setDefaultButton(QMessageBox::Ok);
			int ret = msgBox.exec();

			switch (ret) {
			case QMessageBox::Ok:
				return 0;
			default:
				return 0;
			}
		}

		else if (!CheckFields::is_all_symbols_and_nums(input_login)) {
			QMessageBox msgBox;
			// Заголовок сообщения
			msgBox.setText("Внимание!");
			// Тип иконки сообщения
			msgBox.setIcon(QMessageBox::Information);
			// Основное сообщение Message Box
			msgBox.setInformativeText("Логин содержит недопустимые символы!");
			// Добавление реагирования на софт клавиши
			msgBox.setStandardButtons(QMessageBox::Ok);
			// На какой кнопке фокусироваться по умолчанию
			msgBox.setDefaultButton(QMessageBox::Ok);
			int ret = msgBox.exec();

			switch (ret) {
			case QMessageBox::Ok:
				ui->stackedWidget->setCurrentWidget(ui->page);
			default:
				return 0;
			}
		}
		else {
			return input_login;
		}
	}
}

string CheckFields::get_free_login(SQLdb* db) {
	string input_login = ui->setLoginReg->text().toStdString();
	while (true) {
		if (input_login.size() < 4) {
			ui->label_8->setText("The login must have 4 or more symbols");
		}
		else if (!is_all_symbols_and_nums(input_login)) {
			ui->label_8->setText("The login has ");
		}
		if (db->get_text("ID", input_login, 0) != "") {
			ui->label_8->setText("login");
		}
		else {
			return input_login;
		}
	}
}

string CheckFields::get_exists_login(SQLdb* db) {
	string input_login, account_hash;
	input_login = ui->setLogin->text().toStdString();
	while (true) {
		account_hash = db->get_text("LOGIN", input_login, 1);
		if (input_login.size() < 4) {
			ui->label_5->setText("The login must have 4 or more symbols");
		}
		else if (!is_all_symbols_and_nums(input_login)) {
			ui->label_5->setText("The login has ");
		}
		else if (account_hash == "") {
			ui->label_5->setText("This login is registred yet!");
		}
		else {
			return input_login;
		}
	}
}


string CheckFields::get_password(string true_hash, string true_salt) {
	string input_password = ui->setPassword->text().toStdString();
	//input_password = password_format_input();

	if (true_hash != get_generated_hash(input_password, true_salt)) { // неправильный логин или пароль
		return "-1";
	}
	else { // все хорошо
		return input_password;
	}
}

string CheckFields::get_exists_call_name(SQLdb* db, string line_for_user) {
	string input, reg_name;
	while (true) {
		cout << line_for_user;
		getline(cin, input);

		reg_name = db->get_text("ID", input, 0);

		if (input == "0") { // 0 - ??? ??????
			return "0";
		}
		else if (reg_name == "") {
			//CheckFields::show_info("????? ? ????? ??????? ?? ??????!");
		}
		else {
			return input;
		}
	}
}

string CheckFields::get_format_calltype() {
	string temp = "";
	while (true) {
		cin >> temp;
		regex regular("(incoming|outgoing)");
		cmatch rezult;
		if (regex_match(temp.c_str(), rezult, regular))
			return temp;
		else
		{
			cout << "??????? ???????????? ????????. ?????????? ??? ???!" << endl;
			cin.clear();
			cin.ignore(256, '\n');
		}
	}
}

string CheckFields::get_format_number_of_call() {
	string temp = "";
	while (true)
	{
		cin >> temp;
		if (temp == "0") return "";
		regex regular("([\+]375[0-9]{9})");
		cmatch rezult;
		if (regex_match(temp.c_str(), rezult, regular))
			return temp;
		else
		{
			cout << "??????? ???????????? ????????. ?????????? ??? ???!" << endl;
			cin.clear();
			cin.ignore(256, '\n');
		}
	}
}
//("(incoming|outgoing)")
//("([a-zA-Z]{1-15})")
//regex regular("(+375[0-9]{9})")
// ?????????? ???? ? ????????? ?????
string CheckFields::get_format_date() {
	string temp = "";
	while (true)
	{
		cin >> temp;
		regex regular("(19[0-9]{2}|20[0-1][0-9]|202[0-1])(.)(0[1-9]|1[0-2])(.)(0[1-9]|1[0-9]|2[0-9]|3[0-1])");
		cmatch rezult;
		if (regex_match(temp.c_str(), rezult, regular))
			return temp;
		else
		{
			cout << "??????? ???????????? ????????. ?????????? ??? ???!" << endl;
			cin.clear();
			cin.ignore(256, '\n');
		}
	}
}

string CheckFields::get_format_time() {
	string temp = "";
	while (true) {
		cin >> temp;
		if (temp == "0") return "";
		regex regular("(0[0-9]|1[0-9])|2[0-4](:)(0[0-9]|1[0-9]|2[0-9]|3[0-9]|4[0-9]|5[0-9])");
		cmatch rezult;
		if (regex_match(temp.c_str(), rezult, regular)) return temp;

		else
		{
			cout << "??????? ???????????? ????????. ?????????? ??? ???!" << endl;
			cin.clear();
			cin.ignore(256, '\n');
		}
	}
}

// ?????????? ????????? ??????????? ??????
string CheckFields::password_format_input() {
	string input_password = ui->setPassword->text().toStdString();
	unsigned char symbol;
	do
	{
		symbol = _getch();

		if (symbol == 13) {
			cout << endl;
			break;
		}
		else if (symbol == '\b' && !input_password.empty()) {
			cout << '\b' << ' ' << '\b';
			input_password.pop_back();
		}
		else if (is_symbol_right_for_password(symbol)) {

			input_password.push_back(symbol);
		}

	} while (true);

	return input_password;
}

// ?????????? true, ???? ?????? ???????? ??? ??????
bool CheckFields::is_symbol_right_for_password(char symbol) {
	string right_symbols = "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm1234567890!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";
	for (int i = 0; i < right_symbols.size(); i++) {
		if (symbol == right_symbols[i]) return true;
	}
	return false;
}

// ?????????? true, ???? ?????? ??????? ?????? ?? ???? ? ????
bool CheckFields::is_all_symbols_and_nums(string line) {
	for (int symbol = 0, i = 0; i < line.size(); i++) {
		symbol = (int)line[i];
		if (symbol < 48 || symbol > 57 && symbol < 65 || symbol > 90 && symbol < 97 || symbol > 122) {
			return false;
		}
	}
	return true;
}

// ?????????? ????? ????? ? ????????? ?????
int CheckFields::get_number(bool is_positive, string line_for_user) {
	int number;
	while (true) {
		cout << line_for_user;
		cin >> number;

		if (cin.get() == '\n') {
			if (is_positive && number >= 0) {
				break;
			}
			else if (!is_positive) {
				break;
			}
			else {
				//show_info("????? ?????? ???? ?????????????");
			}
		}
		else {
			cin.clear();
			cin.ignore(256, '\n');
			//CheckFields::show_info("???????????? ????");
		}
	}
	return number;
}

// ?????????? ????? ????? ? ????????? ????? ?? ?????????
int CheckFields::get_number_from_range(int min, int max, string line_for_user) {
	int number;

	while (true) {
		number = get_number(false, line_for_user);
		if (number >= min && number <= max) return number;
		//else show_info("????????? ???????? ?????? ???????????? ?????????? [" + to_string(min) + ", " + to_string(max) + "]");
	}
}

// ?????????? ??????????????? ???????? ????
string CheckFields::get_generated_salt() {
	return generate_salt(SALT_SIZE);
}

// ?????????? ???????????? ????? ??????
string CheckFields::get_generated_hash(string line, string salt) {
	return sha1(sha1(line + salt) + sha1(line));
}

// ?????????? ?????? ?? ???????? ? ????? ??? ????
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

// ?????????? ??????????????? ????
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

string CheckFields::get_txt(string line_for_user) {
	string temp = "";
	cout << line_for_user;
	while (true)
	{
		cin >> temp;
		regex regular("([a-zA-Z\\s]{1,50})");
		cmatch rezult;
		if (regex_match(temp.c_str(), rezult, regular))
			return temp;
		else
		{
			cout << "??????? ???????????? ????????. ?????????? ??? ???!" << endl;
			cin.clear();
			cin.ignore(256, '\n');

		}
	}
}