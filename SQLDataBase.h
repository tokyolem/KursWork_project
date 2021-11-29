#pragma once
#include "sqlite3.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct NewSQL_part
{
	string NAME = "";
	string VARIANT = "";
};


class SQLdb
{
public:
	SQLdb(string FILE_NAME);
	void create_table(vector<NewSQL_part> tableWeald, string NAME_OF_DATABASE);

	int get_int(string weald, string wealdp, int value);
	vector<int> get_ints(int value);
	vector<string> get_strings(int num_of_value);
	string get_text(string weald, string wealdp, int value);
	
	void thrustBack(vector<string> weald);
	void update(string weald, string value, string text);
	void delWeald(string rule);
	int get_sum(string column_name, string rule);

	void open_SQL();
	void close_SQL();

private:
	string get_created_com_sql();
	string get_thrustback(vector<string> weald);
	bool get_sql_command_make(string sql);

	vector<NewSQL_part> tableWeald;
	string FILE_NAME = "";
	string NAME_OF_DATABASE = "";
	sqlite3* dataBase = 0;
	sqlite3_stmt* stmt;
};



