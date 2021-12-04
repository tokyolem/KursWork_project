#pragma once
#include "QtWidgetsApplication0.h"
#include "Data.h"
#include <QtWidgets/QMainWindow>
#include "SQLDataBase.h"
#include <iostream>
#include <QWidget>
#include "GartenPage.h"


class ChoisePageButtons : public QMainWindow 
{
	Q_OBJECT
public:
	ChoisePageButtons (QWidget* parent, Ui::QtWidgetsApplication0Class* ui, SQLdb* gartens_db);
	ChoisePageButtons (vector<string>garten_num);
	void show_buttons();

private:
	QWidget* page;
	QWidget* _parent;
	Ui::QtWidgetsApplication0Class* ui;
	SQLdb* gartens_db = nullptr;
	vector<string>num;
	const int WIDTH = 41;
	const int HEIGHT = 28;
	const int X_PLACE = 550;
	const int Y_PLACE = 570;
	const int ADD_X = 60;

	void create_buttons();
	void delete_buttons();
	void page_next();
	void page_back();
};


