#pragma once
#include "QtWidgetsApplication0.h"
#include "Data.h"
#include "SQLDataBase.h"
#include "ChoisePageButtons.h"
#include "Page.h"

class GartenPage : public QMainWindow, public Page
{
	Q_OBJECT
public:
	GartenPage(QWidget* parent, Ui::QtWidgetsApplication0Class* ui, SQLdb* gartens_db);
	GartenPage(vector<int>garten_num);
	virtual void update_window();

	void create_table_for_gartens(int *number_of_first_output_element);
	void remove_garten();
	void open_edit_gartens_page();
	void delete_garten();
	void add_new_garten();
	string path_to_image();
	void set_image_on_edit();
	void set_image_to_add();
	void set_new_image_on_edit();
	QPixmap* get_image_pixpam(QString path_to_img, const int WIDTH, const int HEIGHT);
	void update_list();
	

private:
	QWidget* page;
	QWidget* _parent;
	Ui::QtWidgetsApplication0Class* ui;
	SQLdb* gartens_db = nullptr;
	vector<int> num;

	vector<int> ids;

	int *number_of_first_output_element;
	const int NUMBER_OF_GARTENS_ON_PAGE = 6;
	int current_page = 0;

	void edits_menu();
	void edit_number_of_garten();
	void value_quanity();
	void edit_quanity_of_group();
	void edit_quanity_of_places();
	void edit_information();
	void edit_affiliation();
	void edit_certain_places();
	void edit_free_places();
	void edit_image();
};

