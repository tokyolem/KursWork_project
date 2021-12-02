#include "GartenPage.h"
#include "QMessageBox"
#include <vector>
#include <string>

using namespace std;

GartenPage::GartenPage(vector<string>garten_num) {
	this->num = garten_num;
}

GartenPage::GartenPage(QWidget* parent, Ui::QtWidgetsApplication0Class* ui, SQLdb* gartens_db)
	: QMainWindow(parent)
{
	this->_parent = parent;
	this->ui = ui;
	this->gartens_db = gartens_db;

	connect(ui->accept_edit, &QPushButton::clicked, this, [=]()
		{
			edits_menu();
			remove_garten();
			create_table_for_gartens();
		});
}

void GartenPage::create_table_for_gartens() {
	ui->stackedWidget_3->setCurrentWidget(ui->page_5);
	vector<string> ids = gartens_db->get_strings(0);
	QString str;

	const int START_X = 25, START_Y = 20, ADD = 326, ADD_Y = 265;

	int col = -1;
	for (int row = 0; row < ids.size(); row++) {
		str = QString::fromStdString(gartens_db->get_text("NUMBER", ids[row], 0));
		QPushButton* btn = new QPushButton(str + "            " + "\n\n\n\n\n\n\n\n", ui->page_5);
		btn->setObjectName("btn_of_garten");
		if (row % 3 == 0) {
			col++;
		}
		btn->setGeometry(START_X + ADD * (row % 3), START_Y + ADD_Y * col, 300, 235);
		btn->setStyleSheet("QPushButton{"
			"background-color: rgb(255, 236, 220);"
			"border-style: solid;"
			"border-width: 3px;"
			"border-radius: 20px;"
			"border-color: rgb(85, 0, 0);"
			"color: rgb(85, 0, 0);"
			"font: 14pt \"Rockwell\"; "
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
				ui->label_26->setText(str);
				open_edit_gartens_page();
				ui->number_of_garten_3->setText(str);
				value_quanity();
				ui->number_of_garten->clear();
				ui->quanity_of_group->clear();
				ui->quanity_of_places->clear();
				ui->affiliation->clear();
				ui->free_places->clear();
				ui->information_2->clear();
				ui->certain_place->clear();
			});
	}
}

void GartenPage::remove_garten() {
	qDeleteAll(ui->page_5->findChildren<QPushButton*>("btn_of_garten"));
}

void GartenPage::open_edit_gartens_page() {
	ui->stackedWidget->setCurrentWidget(ui->page_13);
}

void GartenPage::add_new_garten()
{
	Gartens garten;
	garten.number_of_garten = ui->number_of_garten->text().toStdString();
	garten.quanity_of_group = ui->quanity_of_group->text().toInt();
	garten.quanity_of_places = ui->quanity_of_places->text().toInt();
	garten.affiliation = ui->affiliation->text().toStdString();
	garten.information = ui->information_2->toPlainText().toStdString();
	garten.certain_places = ui->certain_place->text().toStdString();
	garten.free_places = ui->free_places->text().toInt();

	gartens_db->thrustBack({ "'" + garten.number_of_garten + "'",
					to_string(garten.quanity_of_group),
					to_string(garten.quanity_of_places),
					"'" + garten.affiliation + "'",
					"'" + garten.information + "'",
					"'" + garten.certain_places + "'",
					to_string(garten.free_places) });
}

void GartenPage::edits_menu() {
	edit_number_of_garten();
	edit_quanity_of_group();
	edit_quanity_of_places();
	edit_information();
	edit_affiliation();
	edit_certain_places();
	edit_free_places();
}

void GartenPage::value_quanity()
{
	string field_for_search = ui->label_26->text().toStdString();
	int quanity_of_group = gartens_db->get_int("NUMBER", field_for_search, 1);
	int quanity_of_places = gartens_db->get_int("NUMBER", field_for_search, 2);
	int free_places = gartens_db->get_int("NUMBER", field_for_search, 6);
	string affiliation = gartens_db->get_text("NUMBER", field_for_search, 3);
	string information = gartens_db->get_text("NUMBER", field_for_search, 4);
	string certain_places = gartens_db->get_text("NUMBER", field_for_search, 5);
	
	ui->quanity_of_group_3->setText(QString::number(quanity_of_group));
	ui->quanity_of_places_3->setText(QString::number(quanity_of_places));
	ui->free_places_3->setText(QString::number(free_places));
	ui->affiliation_3->setText(QString::fromStdString(affiliation));
	ui->information_3->setPlainText(QString::fromStdString(information));
	ui->certain_place_3->setText(QString::fromStdString(certain_places));
}

void GartenPage::edit_number_of_garten() {
	string field_for_search = ui->label_26->text().toStdString();
	string edit_field = ui->number_of_garten_3->text().toStdString();

	if (edit_field == "") {
		return;
	}
	else {
		gartens_db->update("NUMBER", "'" + edit_field + "'", "NUMBER='" + field_for_search + "'");
	}
}

void GartenPage::edit_quanity_of_group() {
	string field_for_search = ui->label_26->text().toStdString();
	int edit_field = ui->quanity_of_group_3->text().toInt();

	if (edit_field == NULL) {
		return;
	}
	else {
		gartens_db->update("QGROUP", to_string(edit_field) , "NUMBER='" + field_for_search + "'");
	}
}

void GartenPage::edit_quanity_of_places() {
	string field_for_search = ui->label_26->text().toStdString();
	int edit_field = ui->quanity_of_places_3->text().toInt();

	if (edit_field == NULL) {
		return;
	}
	else {
		gartens_db->update("QPLACES", to_string(edit_field), "NUMBER='" + field_for_search + "'");
	}
}

void GartenPage::edit_information() {
	string field_for_search = ui->label_26->text().toStdString();
	string edit_field = ui->information_3->toPlainText().toStdString();

	if (edit_field == "") {
		return;
	}
	else {
		gartens_db->update("INFORMATION", "'" + edit_field + "'", "NUMBER='" + field_for_search + "'");
	}
}

void GartenPage::edit_affiliation() {
	string field_for_search = ui->label_26->text().toStdString();
	string edit_field = ui->affiliation_3->text().toStdString();

	if (edit_field == "") {
		return;
	}
	else {
		gartens_db->update("AFFILICATION", "'" + edit_field + "'", "NUMBER='" + field_for_search + "'");
	}
}

void GartenPage::edit_certain_places() {
	string field_for_search = ui->label_26->text().toStdString();
	string edit_field = ui->certain_place_3->text().toStdString();

	if (edit_field == "") {
		return;
	}
	else {
		gartens_db->update("CERTAINPLACES", "'" + edit_field + "'", "NUMBER='" + field_for_search + "'");
	}
}

void GartenPage::edit_free_places() {
	string field_for_search = ui->label_26->text().toStdString();
	int edit_field = ui->free_places_3->text().toInt();

	if (edit_field == NULL) {
		return;
	}
	else {
		gartens_db->update("FREEPLACES", to_string(edit_field), "NUMBER='" + field_for_search + "'");
	}
}

void GartenPage::delete_garten()
{
	QString str1 = ui->label_26->text();
	string field_for_search = ui->label_26->text().toStdString();
	QMessageBox msgBox;
	msgBox.setText("Do you really want to delete \n" + str1 + "?");
	msgBox.setIcon(QMessageBox::Information);
	msgBox.setInformativeText("");
	msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
	msgBox.setDefaultButton(QMessageBox::Ok);
	
	msgBox.setStyleSheet("QMessageBox {"
		"border-style: solid;"
		"border-color: rgb(85,0,0);"
		"background-color: rgb(255, 236, 220);"
		"font: 12pt \"Rockwell\"; }"
		"QPushButton {"
		"background-color: rgb(255, 236, 220);"
		"border-style: solid;"
		"border-width: 3px;"
		"border-radius: 15px;"
		"border-color: rgb(85, 0, 0);"
		"color: rgb(85, 0, 0);"
		"font: 14pt \"Rockwell\"; "
		"min-width: 4em;"
		"padding: 3px; }"
		"QPushButton::hover{"
		"background-color: rgb(255, 239, 250);"
		"border-style: solid;"
		"border-color: rgb(180, 155, 255);"
		"color: rgb(180, 155, 255); }");
	int ret = msgBox.exec();

	switch (ret) {
	case QMessageBox::Ok:
		gartens_db->delWeald("NUMBER='" + field_for_search + "'");
	case QMessageBox::Cancel:
		ui->stackedWidget->setCurrentWidget(ui->page_13);
	default:
		return;
	}
}
