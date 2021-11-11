#pragma once
#include <string>
#include "SQLDataBase.h"

using namespace std;

const string ACCOUNTS_DATABASE_FILENAME = "users.db";
const string ACCOUNTS_DATABASE_NAME = "ACCOUNTS";

//сруктура хранения перменных аккаунта
struct Account {
	string login = "";
	string salted_hash_password = "";
	string salt = "";
	int role = 0;
	bool access = false;
	int id = 0;
};
