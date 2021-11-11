#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_QtWidgetsApplication0.h"
#include <QDebug>
#include "SQLDataBase.h"
#include <QStackedWidget>
#include <QMessageBox>
#include "Users.h"
#include <iostream>
#include "SHA256.h"
#include "registration.h"
#include "Authorization.h"
#include "QtWidgetsApplication0.h"
#include <regex>
#include <conio.h>

class CheckFields
{
public:
	CheckFields() {};
	CheckFields(Ui::QtWidgetsApplication0Class* ui);
	//создание primary key
	string get_exists_call_name(SQLdb* db, string input_user = "Порядковый номер вызова: ");

	//возвращение введённой даты с проверкой через regex
	string get_format_date();
	//возвращение введённого номера телефона с проверкой через regex
	string get_format_number_of_call();
	string get_format_calltype();
	string get_format_time();

	//возварщение введённого пароля с проверкой на допустимые символы
	string password_format_input();
	//возвращает 1, если строка состоит только из букв и цифр
	bool is_all_symbols_and_nums(string line);
	//возварщает введённое интовое значения с проверкой ввода 
	int get_number(bool is_positive = false, string line_for_user = "\n> ");
	//возваращает введённое интовое значения из диапозона от мин до макс с проверкой ввода
	int get_number_from_range(int min, int max, string out_line = "\n> ");
	//возвращает введённый текст 
	string get_txt(string line_for_user);

	//возварщает логин спроверкой ввода
	string get_login(SQLdb* db);
	//возвращет существующий логин 
	string get_exists_login(SQLdb* db);
	//возварщает свободный для регистрации логин 
	string get_free_login(SQLdb* db);
	//возварщает пароль с проверкой ввода на допустимые символы
	string get_password(string true_hash, string true_salt);

	string get_generated_salt();
	string get_generated_hash(string line, string salt);
	string get_symbols_for_salt();
	string generate_salt(int salt_size);
	bool is_symbol_right_for_password(char symbol);

private:
	SQLdb* db = nullptr;
	const int SALT_SIZE = 16;
	const int SYMBOLS_SIZE = 62;
	Ui::QtWidgetsApplication0Class* ui;
};

