#include "GartenPage.h"

using namespace std;

GartenPage::GartenPage(vector<int>garten_num) {
	this->num = garten_num;
}

GartenPage::GartenPage(QWidget* parent, Ui::QtWidgetsApplication0Class* ui, SQLdb* gartens_db)
	: QMainWindow(parent)
{
	this->_parent = parent;
	this->ui = ui;
	this->gartens_db = gartens_db;
	this->page = ui->page_5;

	this->number_of_first_output_element = new int(0);

	connect(ui->accept_edit, &QPushButton::clicked, this, [=]()
		{
			edits_menu();
			update_list();
		});
}

void GartenPage::update_window() {
	update_list();
}

void GartenPage::create_table_for_gartens(int * number_of_output_element) {
	this->number_of_first_output_element = number_of_first_output_element;
	ui->stackedWidget_3->setCurrentWidget(ui->page_5);
	ids = gartens_db->get_ints(8);
	QString str;
	
	const int START_X = 25, START_Y = 20, ADD = 326, ADD_Y = 265;

	int last_index = (*number_of_first_output_element + NUMBER_OF_GARTENS_ON_PAGE) > ids.size() ? ids.size() : *number_of_first_output_element + NUMBER_OF_GARTENS_ON_PAGE;

	int col = -1;
	for (int row = *number_of_first_output_element; row < last_index; row++) 
	{
		str = QString::fromStdString(gartens_db->get_text("ID", to_string(ids[row]), 0));
		QPushButton* btn = new QPushButton(str , ui->page_5);
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
				ui->information_5->setStyleSheet("background-color: rgb(255, 236, 220);"
					"border: 2px solid gray;"
					"border-width: 3px;"
					"border-radius: 50px;"
					"border-color: rgb(85, 0, 0);"
					"font: 14pt \"Rockwell\";"
					"min-width: 10em;"
					"color: rgb(255,236,220);"
					"padding: 6px;"
				);
				set_image_on_edit();
			});
	}
}

void GartenPage::remove_garten() {
	qDeleteAll(ui->page_5->findChildren<QPushButton*>("btn_of_garten"));
}

void GartenPage::open_edit_gartens_page() {
	ui->stackedWidget->setCurrentWidget(ui->page_13);
}

string GartenPage::path_to_image() {
	QString path = QFileDialog::getOpenFileName(this, ("Open file"), ("/home"), ("Images (*.png *.jpg)"));
	return path.toStdString();
}

void GartenPage::add_new_garten()
{
	num = gartens_db->get_ints(8);
	Gartens garten;
	garten.number_of_garten = ui->number_of_garten->text().toStdString();
	garten.quanity_of_group = ui->quanity_of_group->text().toInt();
	garten.quanity_of_places = ui->quanity_of_places->text().toInt();
	garten.affiliation = ui->affiliation->text().toStdString();
	garten.information = ui->information_2->toPlainText().toStdString();
	garten.certain_places = ui->certain_place->text().toStdString();
	garten.free_places = ui->free_places->text().toInt();
	garten.path = ui->information_4->toPlainText().toStdString();
	garten.id = get_min_nonexist(num);
	
	set_image_to_add();

	
	gartens_db->thrustBack({ "'" + garten.number_of_garten + "'",
					to_string(garten.quanity_of_group),
					to_string(garten.quanity_of_places),
					"'" + garten.affiliation + "'",
					"'" + garten.information + "'",
					"'" + garten.certain_places + "'",
					to_string(garten.free_places),
					"'" + garten.path + "'",
					to_string(garten.id)                });
}

void GartenPage::edits_menu() {
	edit_number_of_garten();
	edit_quanity_of_group();
	edit_quanity_of_places();
	edit_information();
	edit_affiliation();
	edit_certain_places();
	edit_free_places();
	edit_image();
	ui->label_31->setText("Changes have been made!");
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
	string image = gartens_db->get_text("NUMBER", field_for_search, 7);
	
	
	ui->quanity_of_group_3->setText(QString::number(quanity_of_group));
	ui->quanity_of_places_3->setText(QString::number(quanity_of_places));
	ui->free_places_3->setText(QString::number(free_places));
	ui->affiliation_3->setText(QString::fromStdString(affiliation));
	ui->information_3->setPlainText(QString::fromStdString(information));
	ui->certain_place_3->setText(QString::fromStdString(certain_places));
	ui->information_5->setPlainText(QString::fromStdString(image));
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

void GartenPage::edit_image() {
	string field_for_search = ui->label_26->text().toStdString();
	string edit_field = ui->information_5->toPlainText().toStdString();

	if (edit_field == "") {
		return;
	}
	else {
		gartens_db->update("PATH","'" + edit_field + "'", "NUMBER='" + field_for_search + "'");
	}
}

QPixmap* GartenPage::get_image_pixpam(QString path_to_img, const int WIDTH, const int HEIGHT)
{
	QPixmap* target = new QPixmap(QSize(WIDTH, HEIGHT));
	target->fill(Qt::transparent);

	QPixmap p = QPixmap(path_to_img);
	p = p.scaled(QSize(WIDTH, HEIGHT), Qt::KeepAspectRatio, Qt::SmoothTransformation);

	QPainter painter(target);
	painter.setRenderHint(QPainter::Antialiasing, true);
	painter.setRenderHint(QPainter::HighQualityAntialiasing, true);
	painter.setRenderHint(QPainter::SmoothPixmapTransform, true);

	QPainterPath path = QPainterPath();
	int start_x = (WIDTH - p.size().width()) / 2;
	int start_y = (HEIGHT - p.size().height()) / 2;
	path.addRoundedRect(start_x, start_y, p.size().width(), p.size().height(), 10, 10);
	painter.setClipPath(path);
	painter.drawPixmap(start_x, start_y, p);

	return target;
}

void GartenPage::update_list()
{
	ids = gartens_db->get_ints(8);
	ChoisePageButtons* choise = new ChoisePageButtons(_parent, ui, ui->page_5, ids, NUMBER_OF_GARTENS_ON_PAGE, number_of_first_output_element);
	choise->set_pointer_to_page(this);
	if (ids.size() > 6) {
		choise->create_page_buttons(ui->page_5, ids, "btn_of_garten");
	}
	else {
		choise->delete_buttons(ui->page_5);
	}
	remove_garten();
	create_table_for_gartens(number_of_first_output_element);

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
		"font: 20pt \"Rockwell\"; "
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

void GartenPage::set_image_on_edit() {
	string field_for_search = ui->label_26->text().toStdString();
	string path = gartens_db->get_text("NUMBER", field_for_search, 7);
	QPixmap pic2(QString::fromStdString(path));
	QSize PicSize(490, 461);
	pic2 = pic2.scaled(PicSize, Qt::KeepAspectRatio);
	ui->label_27->setPixmap(pic2);
}

void GartenPage::set_image_to_add() {
	string path = ui->information_4->toPlainText().toStdString();
	QPixmap pic2(QString::fromStdString(path));
	QSize PicSize(490, 431);
	pic2 = pic2.scaled(PicSize, Qt::KeepAspectRatio);
	ui->label_28->setPixmap(pic2);
}

void GartenPage::set_new_image_on_edit() {
	string path = ui->information_5->toPlainText().toStdString();
	QPixmap* pic2 = new QPixmap(QString::fromStdString(path));
	QSize PicSize(490, 431);
	*pic2 = pic2->scaled(PicSize, Qt::KeepAspectRatio);
	
	ui->label_27->setPixmap(*pic2);
}

