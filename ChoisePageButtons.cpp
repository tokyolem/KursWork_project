#include "ChoisePageButtons.h"

ChoisePageButtons::ChoisePageButtons(QWidget* parent, Ui::QtWidgetsApplication0Class* ui, QWidget* page, vector<int> num, const int NUMBER_OF_ELEMENTS_ON_PAGE, int* number_of_first_element_on_page)
	: QMainWindow(parent), NUMBER_OF_ELEMENTS_ON_PAGE(NUMBER_OF_ELEMENTS_ON_PAGE)
{
	this->ui = ui;
	this->page = page;
	this->num_garten = num;
	this->number_of_first_element_on_page = number_of_first_element_on_page;
	this->_parent = parent;
}

void ChoisePageButtons::create_page_buttons(QWidget* page, vector<int> size, QString element) {
	QPushButton* front = new QPushButton(">", page);
	QPushButton* back = new QPushButton("<", page);

	front->setObjectName("front");
	back->setObjectName("back");

	front->setGeometry(640, 572, SIZE_X, SIZE_Y);
	back->setGeometry(560, 572, SIZE_X, SIZE_Y);

	front->setStyleSheet("QPushButton{"
		"background-color: rgb(255, 236, 220);"
		"border-style: solid;"
		"border-width: 3px;"
		"border-radius: 10px;"
		"border-color: rgb(85, 0, 0);"
		"color: rgb(85, 0, 0);"
		"font: 20pt \"Rockwell\"; "
		"min-width: 1em;"
		"padding: 3px; }"
		"QPushButton::hover{"
		"background-color: rgb(255, 239, 250);"
		"border-style: solid;"
		"border-color: rgb(180, 155, 255);"
		"color: rgb(180, 155, 255); }");
	back->setStyleSheet("QPushButton{"
		"background-color: rgb(255, 236, 220);"
		"border-style: solid;"
		"border-width: 3px;"
		"border-radius: 10px;"
		"border-color: rgb(85, 0, 0);"
		"color: rgb(85, 0, 0);"
		"font: 20pt \"Rockwell\"; "
		"min-width: 1em;"
		"padding: 3px; }"
		"QPushButton::hover{"
		"background-color: rgb(255, 239, 250);"
		"border-style: solid;"
		"border-color: rgb(180, 155, 255);"
		"color: rgb(180, 155, 255); }");

	front->show();
	back->show();

	connect(front, &QPushButton::clicked, page, [=]() {
		page_next(element, size, page);
		_page->update_window();
		});
	connect(back, &QPushButton::clicked, page, [=]() {
		page_back(element, size, page);
		_page->update_window();
		});
}

void ChoisePageButtons::page_next(QString element, vector<int> vector, QWidget* page)
{
	int size_of_vector = vector.size();
	
	if (*number_of_first_element_on_page + NUMBER_OF_ELEMENTS_ON_PAGE <= size_of_vector) {
		*number_of_first_element_on_page += 6;
	}
}

void ChoisePageButtons::page_back(QString element, vector<int> vector, QWidget* page)
{
	
	int size_of_vector = vector.size();

	if (*number_of_first_element_on_page - NUMBER_OF_ELEMENTS_ON_PAGE >=  0) {
		*number_of_first_element_on_page -= 6;
	}
	else {
		*number_of_first_element_on_page = 0;
	}
}

void ChoisePageButtons::delete_buttons(QWidget* page) {
	qDeleteAll(page->findChildren<QPushButton*>("front"));
	qDeleteAll(page->findChildren<QPushButton*>("back"));
}

void ChoisePageButtons::delete_elements_on_page(QWidget* page, QString element) {
	qDeleteAll(page->findChildren<QPushButton*>(element));
}

void ChoisePageButtons::set_pointer_to_page(Page* _page) {
	this->_page = _page;
}