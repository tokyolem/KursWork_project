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
	//�������� primary key
	string get_exists_call_name(SQLdb* db, string input_user = "���������� ����� ������: ");

	//����������� �������� ���� � ��������� ����� regex
	string get_format_date();
	//����������� ��������� ������ �������� � ��������� ����� regex
	string get_format_number_of_call();
	string get_format_calltype();
	string get_format_time();

	//����������� ��������� ������ � ��������� �� ���������� �������
	string password_format_input();
	//���������� 1, ���� ������ ������� ������ �� ���� � ����
	bool is_all_symbols_and_nums(string line);
	//���������� �������� ������� �������� � ��������� ����� 
	int get_number(bool is_positive = false, string line_for_user = "\n> ");
	//����������� �������� ������� �������� �� ��������� �� ��� �� ���� � ��������� �����
	int get_number_from_range(int min, int max, string out_line = "\n> ");
	//���������� �������� ����� 
	string get_txt(string line_for_user);

	//���������� ����� ���������� �����
	string get_login(SQLdb* db);
	//��������� ������������ ����� 
	string get_exists_login(SQLdb* db);
	//���������� ��������� ��� ����������� ����� 
	string get_free_login(SQLdb* db);
	//���������� ������ � ��������� ����� �� ���������� �������
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

