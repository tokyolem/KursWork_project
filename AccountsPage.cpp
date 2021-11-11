#include "AccountsPage.h"
#include "QMessageBox"
#include <vector>
#include <string>

using namespace std;

AccountsPage::AccountsPage(QWidget * parent, Ui::QtWidgetsApplication0Class * ui, SQLdb * accounts_db) 
	: QMainWindow(parent)
{
	this->_parent = parent;
	this->ui = ui;
	this->accounts_db = accounts_db;
}

void AccountsPage::create_table_for_accounts() {
	ui->stackedWidget_3->setCurrentWidget(ui->page_4);
	vector<int> ids = accounts_db->get_ints(5);
	QString str;

	const int START_X = 15, START_Y = 10, ADD = 245, ADD_Y = 110;

	int col = -1;
	for (int row = 0; row < ids.size(); row++) {
		str = QString::fromStdString(accounts_db->get_text("ID", to_string(ids[row]), 0));
		btn = new QPushButton(str, ui->page_4);
		btn->setObjectName("btn_of_accounts");
		if (row % 4 == 0) {
			col++;
		}
		btn->setGeometry(START_X + ADD * (row % 4), START_Y + ADD_Y * col, 235, 100);
		btn->setStyleSheet("background-color: white; border-style: solid; border-width: 2px; border-radius: 10px; border-color: lightGray; font: bold 14px; min-width: 10em; padding: 6px;");
		btn->show();
		connect(btn, SIGNAL(clicked()), _parent, SLOT(on_btn_clicked()));
	}
}

void AccountsPage::remove_accounts() {
	qDeleteAll(ui->page_4->findChildren<QPushButton*>("btn_of_accounts"));
}

void AccountsPage::edit_account() {
	string input_login = ui->setLogin_2->text().toStdString();
}




