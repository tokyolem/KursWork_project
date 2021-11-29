#pragma once
#include "SQLDatabase.h"

SQLdb::SQLdb(string FILE_NAME) {
	this->FILE_NAME = FILE_NAME;
}


void SQLdb::create_table(vector<NewSQL_part> tableWeald, string NAME_OF_DATABASE) {
	this->tableWeald = tableWeald;
	this->NAME_OF_DATABASE = NAME_OF_DATABASE;
	get_sql_command_make(get_created_com_sql());
}


string SQLdb::get_created_com_sql() {
	string sql = " CREATE TABLE IF NOT EXISTS " + NAME_OF_DATABASE + " ( ";

	for (int i = 0; i < tableWeald.size(); i++) {
		sql += tableWeald[i].NAME + " " + tableWeald[i].VARIANT;
		if (i != tableWeald.size() - 1) sql += ",";
		sql += " ";
	}

	sql += " ); ";
	return sql;
}


void SQLdb::open_SQL() {
	if (sqlite3_open(FILE_NAME.c_str(), &dataBase)) {
		cout << "Ошибка открытия/создания БД:" << sqlite3_errmsg(dataBase);
	}
}


void SQLdb::close_SQL() {
	if (sqlite3_close(dataBase) == SQLITE_BUSY) {
		cout << "Ошибка закрытия БД." << endl;
	}
}

void SQLdb::thrustBack(vector<string> field) {
	string sql = get_thrustback(field);
	get_sql_command_make(sql);
}


string SQLdb::get_thrustback(vector<string> weald) {
	string sql = "INSERT INTO " + NAME_OF_DATABASE + " ( ";
	for (int i = 0; i < tableWeald.size(); i++) {
		sql += tableWeald[i].NAME;
		if (i != tableWeald.size() - 1) sql += ",";
		sql += " ";
	}

	sql += " ) VALUES ( ";

	for (int i = 0; i < weald.size(); i++) {
		sql += weald[i];
		if (i != weald.size() - 1) sql += ",";
		sql += " ";
	}

	sql += " );";
	return sql;
}


void SQLdb::update(string weald, string value, string text) {
	string sql = "UPDATE " + NAME_OF_DATABASE + " set " + weald + " = " + value + " where " + text + " ;";
	get_sql_command_make(sql);
}


void SQLdb::delWeald(string rule) {
	string sql = "DELETE from " + NAME_OF_DATABASE + " where " + rule + " ;";
	get_sql_command_make(sql);
}

int SQLdb::get_int(string db_field, string field_for_search, int num_of_value) {
	string sql = "SELECT * FROM " + NAME_OF_DATABASE + " WHERE " + db_field + " GLOB '" + field_for_search + "';";

	sqlite3_prepare_v2(dataBase, sql.c_str(), -1, &stmt, NULL);

	int rc, value = 0;
	if ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
		value = sqlite3_column_int(stmt, num_of_value);
	}

	sqlite3_finalize(stmt);
	return value;
}

vector<int> SQLdb::get_ints(int num_of_value) {
	string sql = "SELECT * FROM " + NAME_OF_DATABASE + " ;";
	sqlite3_prepare_v2(dataBase, sql.c_str(), -1, &stmt, NULL);

	int rc = 0;
	vector<int> value;
	while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
		value.push_back(sqlite3_column_int(stmt, num_of_value));
	}

	sqlite3_finalize(stmt);
	return value;
}

vector<string> SQLdb::get_strings(int num_of_value)
{
	string sql = "SELECT * FROM " + NAME_OF_DATABASE + " ;";
	sqlite3_prepare_v2(dataBase, sql.c_str(), -1, &stmt, NULL);

	int rc = 0;
	vector<string> text;
	while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
		text.push_back(reinterpret_cast<const char*>(sqlite3_column_text(stmt, num_of_value)));
	}

	sqlite3_finalize(stmt);
	return text;
}


string SQLdb::get_text(string db_field, string field_for_search, int num_of_value) {
	string text, sql = "SELECT * FROM " + NAME_OF_DATABASE + " WHERE " + db_field + " GLOB '" + field_for_search + "';";

	sqlite3_prepare_v2(dataBase, sql.c_str(), -1, &stmt, NULL);

	int rc;
	while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
		text = reinterpret_cast<const char*>(sqlite3_column_text(stmt, num_of_value));
	}

	sqlite3_finalize(stmt);
	return text;
}


bool SQLdb::get_sql_command_make(string sql) {
	char* error = 0;
	if (sqlite3_exec(dataBase, sql.c_str(), 0, 0, &error))
	{
		cout << "Ошибка БД: " << error << endl;
		sqlite3_free(error);
		return false;
	}
	else {
		return true;
	}
}

int SQLdb::get_sum(string column_name, string rule) {
	string sql = "SELECT SUM( " + column_name + " ) FROM " + NAME_OF_DATABASE + rule + ";";

	sqlite3_prepare_v2(dataBase, sql.c_str(), -1, &stmt, NULL);

	int rc = 0, value = 0;
	if ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
		value = sqlite3_column_int(stmt, 0);
	}

	sqlite3_finalize(stmt);
	return value;
}

