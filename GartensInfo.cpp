#include "GartensInfo.h"
#include "QMessageBox"
#include <vector>
#include <string>

using namespace std;

GartensInfo::GartensInfo(vector<string>garten_num) {
	this->num = garten_num;
}

GartensInfo::GartensInfo(QWidget* parent, Ui::QtWidgetsApplication0Class* ui, SQLdb* gartens_db)
	: QMainWindow(parent)
{
	this->_parent = parent;
	this->ui = ui;
	this->gartens_db = gartens_db;
}

void GartensInfo::create_table_for_gartens() {
	ui->stackedWidget_3->setCurrentWidget(ui->inf_gartens);
	vector<string> ids = gartens_db->get_strings(0);
	QString str;

	const int START_X = 25, START_Y = 20, ADD = 326, ADD_Y = 265;

	int col = -1;
	for (int row = 0; row < ids.size(); row++) {
		str = QString::fromStdString(gartens_db->get_text("NUMBER", ids[row], 0));
		QPushButton* btn = new QPushButton(str, ui->inf_gartens);
		btn->setObjectName("btn_of_gartensinf");
		if (row % 3 == 0) {
			col++;
		}
		btn->setGeometry(START_X + ADD * (row % 3), START_Y + ADD_Y * col, 300, 235);
		btn->setStyleSheet("QPushButton{"
			"background-color: rgb(255, 236, 220);"
			"border-style: solid;"
			"border-width: 3px;"
			"border-radius: 40px;"
			"border-color: rgb(85, 0, 0);"
			"color: rgb(85, 0, 0);"
			"font: 20pt \"Rockwell\"; "
			"min-width: 4em;"
			"padding: 3px; }"
			"QPushButton::hover{"
			"background-color: rgb(255, 239, 250);"
			"border-style: solid;"
			"border-color: rgb(180, 155, 255);"
			"color: rgb(180, 155, 255); }");


		btn->show();
		//connect(btn, SIGNAL(clicked()), _parent, SLOT(on_btn_clicked()));
		connect(btn, &QPushButton::clicked, this,
			[=]() {

				open_edit_account_page();
				ui->label_21->setText(str);
				get_Infromation();
			});
	}
}

void GartensInfo::remove_garten() {
	qDeleteAll(ui->inf_gartens->findChildren<QPushButton*>("btn_of_gartensinf"));
}

void GartensInfo::open_edit_account_page() {
	ui->stackedWidget->setCurrentWidget(ui->page_14);
}

void GartensInfo::get_Infromation() {
	string field_for_search = ui->label_21->text().toStdString();
	string number_of_garten = gartens_db->get_text("NUMBER", field_for_search, 0);
	int amount_of_groups = gartens_db->get_int("NUMBER", field_for_search, 1);
	int amount_of_places = gartens_db->get_int("NUMBER", field_for_search, 2);
	string affliation = gartens_db->get_text("NUMBER", field_for_search, 3);
	string information = gartens_db->get_text("NUMBER", field_for_search, 4);
	string certain_places = gartens_db->get_text("NUMBER", field_for_search, 5);
	int amount_of_free_places = gartens_db->get_int("NUMBER", field_for_search, 6);

	ui->Number->setText(QString::fromStdString(number_of_garten));
	ui->Groups->setText(QString::number(amount_of_groups));
	ui->Places->setText(QString::number(amount_of_places));
	ui->Affiliation->setText(QString::fromStdString(affliation));
	ui->get_information->setText(QString::fromStdString(information));
	ui->Certain->setText(QString::fromStdString(certain_places));
	ui->Free->setText(QString::number(amount_of_free_places));
}





