#pragma once
#include "QtWidgetsApplication0.h"
#include "Data.h"
#include <QtWidgets/QMainWindow>
#include "SQLDataBase.h"
#include <iostream>


class GartenPage: public QMainWindow
{
	Q_OBJECT
public:
	GartenPage(QWidget* parent, Ui::QtWidgetsApplication0Class* ui, SQLdb* garten_db);
	GartenPage(vector<string>garten_id);

	void create_table_for_garten();
	void add_new_garten();
	void remove_all_gartens();
	void open_edit_gartens_page();

private:
	QPushButton* btn;
	QWidget* _parent;
	Ui::QtWidgetsApplication0Class* ui;
	SQLdb* garten_db = nullptr;
	vector<string>num;
};
