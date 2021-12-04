#include "ChoisePageButtons.h"

ChoisePageButtons::ChoisePageButtons(QWidget* parent, Ui::QtWidgetsApplication0Class* ui, SQLdb* gartens_db)
	:QMainWindow(parent)
{
	this->_parent = parent;
	this->ui = ui;
	this->gartens_db = gartens_db;
	this->page = ui->page_5;

}

ChoisePageButtons::ChoisePageButtons(vector<string> garten_num)
{
	this->num = garten_num;
}

void ChoisePageButtons::show_buttons() 
{	
	vector<string>ids = gartens_db->get_strings(0);
	if (ids.size() <= 6) {
		delete_buttons();
	}

	else if (ids.size() > 6) {
		create_buttons();
	}
}

void ChoisePageButtons::create_buttons()
{
	QPushButton* front = new QPushButton(">", page);
	QPushButton* back = new QPushButton("<", page);
	front->setObjectName("front");
	back->setObjectName("back");
	front->setGeometry(610, 570, 41, 28);
	back->setGeometry(550, 570, 41, 28);
	front->setStyleSheet("QPushButton{"
		"background-color: rgb(255, 236, 220);"
		"border-style: solid;"
		"border-width: 3px;"
		"border-radius: 10px;"
		"border-color: rgb(85, 0, 0);"
		"color: rgb(85, 0, 0);"
		"font: 14pt \"Rockwell\"; "
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
		"font: 14pt \"Rockwell\"; "
		"min-width: 1em;"
		"padding: 3px; }"
		"QPushButton::hover{"
		"background-color: rgb(255, 239, 250);"
		"border-style: solid;"
		"border-color: rgb(180, 155, 255);"
		"color: rgb(180, 155, 255); }");
	front->show();
	back->show();
	
	connect(front, &QPushButton::clicked, this, [=]() {
		page_next();
		});
	connect(back, &QPushButton::clicked, this, [=]() {
		page_back();
		});
}

void ChoisePageButtons::delete_buttons() {
	qDeleteAll(ui->page_5->findChildren<QPushButton*>("front"));
	qDeleteAll(ui->page_5->findChildren<QPushButton*>("back"));
}

void ChoisePageButtons::page_next()
{
	
}

void ChoisePageButtons::page_back()
{

}
