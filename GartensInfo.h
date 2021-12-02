#pragma once
#include "QtWidgetsApplication0.h"
#include "Data.h"
#include <QtWidgets/QMainWindow>
#include "SQLDataBase.h"
#include <iostream>


class GartensInfo : public QMainWindow
{
	Q_OBJECT
public:
	GartensInfo(QWidget* parent, Ui::QtWidgetsApplication0Class* ui, SQLdb* gartens_db);
	GartensInfo(vector<string>garten_num);

	void create_table_for_gartens();
	void remove_garten();
	void open_edit_account_page();
	void get_Infromation();

private:

	QWidget* _parent;
	Ui::QtWidgetsApplication0Class* ui;
	SQLdb* gartens_db = nullptr;
	vector<string>num;
};

