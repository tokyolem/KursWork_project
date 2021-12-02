#pragma once
#include "QtWidgetsApplication0.h"
#include "Data.h"
#include <QtWidgets/QMainWindow>
#include "SQLDataBase.h"
#include <iostream>


class GartenPage : public QMainWindow
{
	Q_OBJECT
public:
	GartenPage(QWidget* parent, Ui::QtWidgetsApplication0Class* ui, SQLdb* gartens_db);
	GartenPage(vector<string>garten_num);

	void create_table_for_gartens();
	void remove_garten();
	void open_edit_gartens_page();
	void add_new_garten();
	void edits_menu();
	void edit_number_of_garten();
	void value_quanity();
	void edit_quanity_of_group();
	void edit_quanity_of_places();
	void edit_information();
	void edit_affiliation();
	void edit_certain_places();
	void edit_free_places();
	void delete_garten();

private:

	QWidget* _parent;
	Ui::QtWidgetsApplication0Class* ui;
	SQLdb* gartens_db = nullptr;
	vector<string>num;
};

