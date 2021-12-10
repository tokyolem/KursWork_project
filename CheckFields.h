#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_QtWidgetsApplication0.h"
#include "SQLDataBase.h"
#include <QMessageBox>
#include <iostream>
#include "SHA256.h"
#include "QtWidgetsApplication0.h"
#include <regex>

class CheckFields
{
public:
	CheckFields(Ui::QtWidgetsApplication0Class* ui);
	//возварщает введённое интовое значения с проверкой ввода 
	string get_generated_salt();
	string get_generated_hash(string line, string salt);
	string get_symbols_for_salt();
	string generate_salt(int salt_size);

	string get_password(string true_hash, string true_salt);
	void ban();

private:
	void get_symbols_for_login();
	void get_symbols_for_password();
	void get_symbols_for_information();
	SQLdb* db = nullptr;
	const int SALT_SIZE = 16;
	const int SYMBOLS_SIZE = 62;
	Ui::QtWidgetsApplication0Class* ui;
};

