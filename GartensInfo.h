#pragma once
#include "QtWidgetsApplication0.h"
#include "Data.h"
#include <QtWidgets/QMainWindow>
#include "SQLDataBase.h"
#include <iostream>
#include "ChoisePageButtons.h"
#include "Page.h"


class GartensInfo : public QMainWindow, public Page
{
	Q_OBJECT
public:
	GartensInfo(QWidget* parent, Ui::QtWidgetsApplication0Class* ui, SQLdb* gartens_db);
	GartensInfo(vector<int>garten_num);
	virtual void update_window();

	void create_table_for_gartens(int* number_of_first_output_element);
	void remove_garten();
	void open_edit_account_page();
	void get_Infromation();
	void update_list();

private:

	vector<int> ids;

	int* number_of_first_output_element;
	const int NUMBER_OF_GARTENS_ON_PAGE = 6;
	int current_page = 0;

	QWidget* page;
	QWidget* _parent;
	Ui::QtWidgetsApplication0Class* ui;
	SQLdb* gartens_db = nullptr;
	vector<int>num;
};

