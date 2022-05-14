#include "GartensInfo.h"
#include "QMessageBox"
#include <vector>
#include <string>

using namespace std;

GartensInfo::GartensInfo(vector<int>garten_num) {
	this->num = garten_num;
}

void GartensInfo::update_window()
{
	update_list();
}

GartensInfo::GartensInfo(QWidget* parent, Ui::QtWidgetsApplication0Class* ui, SQLdb* gartens_db)
	: QMainWindow(parent)
{
	this->_parent = parent;
	this->ui = ui;
	this->gartens_db = gartens_db;
	this->page = ui->page_5;

	this->number_of_first_output_element = new int(0);
}

void GartensInfo::create_table_for_gartens(int* number_of_first_output_element) {
	this->number_of_first_output_element = number_of_first_output_element;
	ui->stackedWidget_3->setCurrentWidget(ui->inf_gartens);
	ids = gartens_db->get_ints(8);
	QString str;

	const int START_X = 25, START_Y = 20, ADD = 326, ADD_Y = 265;

	int last_index = (*number_of_first_output_element + NUMBER_OF_GARTENS_ON_PAGE) > ids.size() ? ids.size() : *number_of_first_output_element + NUMBER_OF_GARTENS_ON_PAGE;

	int col = -1;
	for (int row = *number_of_first_output_element; row < last_index; row++)
	{
		str = QString::fromStdString(gartens_db->get_text("ID", to_string(ids[row]), 0));
		QPushButton* btn = new QPushButton(str, ui->inf_gartens);
		btn->setObjectName("btn_of_garten");
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

void GartensInfo::update_list()
{
	ids = gartens_db->get_ints(8);
	ChoisePageButtons* choise = new ChoisePageButtons(_parent, ui, ui->inf_gartens, ids, NUMBER_OF_GARTENS_ON_PAGE, number_of_first_output_element);
	choise->set_pointer_to_page(this);
	if (ids.size() > 6) {
		choise->create_page_buttons(ui->inf_gartens, ids, "btn_of_garten");
	}
	else {
		choise->delete_buttons(ui->inf_gartens);
	}
	remove_garten();
	create_table_for_gartens(number_of_first_output_element);

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





