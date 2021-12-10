#pragma once
#include "QtWidgetsApplication0.h"
#include <QPushButton>
#include <QtWidgets/QMainWindow>
#include <QWidget>
#include <QPainter>
#include <QLabel>
#include <vector>
#include "GartenPage.h"
#include "Page.h"


class ChoisePageButtons : public QMainWindow
{
	Q_OBJECT
public:
	ChoisePageButtons(QWidget* parent, Ui::QtWidgetsApplication0Class* ui, QWidget* page, vector<int>num, const int NUMBER_OF_ELEMENTS_ON_PAGE, int* number_of_first_element_on_page);

	void delete_buttons(QWidget* page);
	void delete_elements_on_page(QWidget* page, QString element);
	void create_page_buttons(QWidget* page, vector<int> size, QString element);
	void page_next(QString element, vector<int> size, QWidget* page);
	void page_back(QString element, vector<int> size, QWidget* page);
	void set_pointer_to_page(Page* _page);

private:
	Page* _page;
	QWidget* _parent;
	QWidget* page;
	vector<int>num_garten;
	SQLdb* garten_db;
	Ui::QtWidgetsApplication0Class* ui;

	int* number_of_first_element_on_page = 0;
	const int NUMBER_OF_ELEMENTS_ON_PAGE;
	int number_of_elements;

	const int SIZE_X = 31;
	const int SIZE_Y = 28;
};


