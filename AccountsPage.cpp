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
	connect(ui->accept, &QPushButton::clicked, this,
		[=]() {
			edit_account_login();
			edit_account_access();
		});
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
		"background-color: lightGray; }" );

		btn->show();
		//connect(btn, SIGNAL(clicked()), _parent, SLOT(on_btn_clicked()));
		connect(btn, &QPushButton::clicked, this, 
			[=]() {
				ui->label_9->setText(str);
				ui->setLogin_edit->setText(str);
				open_edit_account_page();
				
			});
	}
}

void AccountsPage::remove_accounts() {
	qDeleteAll(ui->page_4->findChildren<QPushButton*>("btn_of_accounts"));
}

void AccountsPage::open_edit_account_page() {
	ui->stackedWidget->setCurrentWidget(ui->main_first);
	ui->stackedWidget->setCurrentWidget(ui->page_10);
}

void AccountsPage::edit_account_login() {
	string str = ui->label_9->text().toStdString();
	string input_login = ui->setLogin_edit->text().toStdString();

	accounts_db->update("LOGIN","'" + input_login + "'", "LOGIN='" + str + "'");
}

void AccountsPage::edit_account_access() {
	bool is_access = ui->access_box->isChecked();
	string str = ui->label_9->text().toStdString();

	accounts_db->update("ACCESS", to_string(is_access) , "LOGIN='" + str + "'");
}




