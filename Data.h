#pragma once
#include "SQLDataBase.h"
#include <string>

using namespace std;

const string GARTENS_DATABASE_FILENAME = "data.db";
const string GARTENS_DATABASE_NAME = "DATA";

//сруктура хранения перменных детских садов
struct Gartens {
	string number_of_garten = "";
	int quanity_of_group = 0;
	int quanity_of_places = 0;
	string affiliation = "";
	string information = "";
	string certain_places = "";
	int free_places = 0;
};
