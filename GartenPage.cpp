#include "GartenPage.h"

GartenPage::GartenPage(vector<string>garten_id) {
	this->num = garten_id;
}

GartenPage::GartenPage(QWidget* parent, Ui::QtWidgetsApplication0Class* ui, SQLdb* garten_db)
	: QMainWindow(parent) 
{
	this->_parent = parent;
	this->ui = ui;
	this->garten_db = garten_db;
}

void GartenPage::create_table_for_garten() {
	ui->stackedWidget_3->setCurrentWidget(ui->page_5);
	vector<string> ids = garten_db->get_strings(0);
	QString str;
	QPushButton* btn;

	const int START_X = 15, START_Y = 10, ADD = 334, ADD_Y = 265;

	int col = -1;
	
	for (int row = 0; row < ids.size(); row++) {
		str = QString::fromStdString(garten_db->get_text("NUMBER", ids[row], 0));
		btn = new QPushButton(str, ui->page_5);
		btn->setObjectName("btn_of_gartens");
		if (row % 3 == 0)
		{
			col++;
		}
		btn->setGeometry(START_X + ADD* (row % 3), START_Y + ADD_Y * col, 300, 235);
		btn->setStyleSheet("QPushButton{"
			"background-color: white; "
			"border-style: solid;"
			"border-width: 3px;"
			"border-radius: 10px;"
			"border-color: lightGray;"
			"font: 14pt \"Rockwell\"; "
			"min-width: 4em;"
			"padding: 3px; }"
			"QPushButton::hover{"
			"background-color: lightGray; }");

		btn->show();
		
		connect(btn, SIGNAL(clicked()), this, SLOT(open_edit_gartens_page()));
		/*connect(btn, &QPushButton::clicked, this ,
			[=]() {
				open_edit_gartens_page();
			});*/
	}
}

void GartenPage::add_new_garten()
{
	Gartens garten;
	garten.number_of_garten = ui->number_of_garten->text().toStdString();
	garten.quanity_of_group = ui->quanity_of_group->text().toInt();
	garten.quanity_of_places = ui->quanity_of_places->text().toInt();
	garten.affiliation = ui->affiliation->text().toStdString();
	garten.information = ui->information->text().toStdString();
	garten.certain_places = ui->certain_place->text().toStdString();
	garten.free_places = ui->free_places->text().toInt();

	garten_db->thrustBack({ "'" + garten.number_of_garten + "'",
					to_string(garten.quanity_of_group),
					to_string(garten.quanity_of_places),
					"'" + garten.affiliation + "'",
					"'" + garten.information + "'",
					"'" + garten.certain_places + "'",
					to_string(garten.free_places) });
}

void GartenPage::remove_all_gartens() {
	qDeleteAll(ui->page_5->findChildren<QPushButton*>("btn_of_gartens"));
}

void GartenPage::open_edit_gartens_page()
{
	
	/*ui->stackedWidget->setCurrentWidget(ui->page_13);*/
}
