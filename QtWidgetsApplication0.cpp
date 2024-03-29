#include "QtWidgetsApplication0.h"

QtWidgetsApplication0::QtWidgetsApplication0(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
	ui.setLogin->setValidator(new QRegExpValidator(QRegExp("[a-zA-Z|0-9|_|-|.|@]{1,30}")));
	ui.setPassword->setValidator(new QRegExpValidator(QRegExp("[a-zA-Z|0-9|_|-|!|@|#|$|%|^|&|*|(|)]{1,40}")));
}

void QtWidgetsApplication0::set_account_db(SQLdb* accounts_db) {
    this->accounts_db = accounts_db;
}

void QtWidgetsApplication0::set_garten_db(SQLdb* garten_db) {
	this->garten_db = garten_db;
}

void QtWidgetsApplication0::on_Register_clicked()
{
	ui.setLoginReg->setValidator(new QRegExpValidator(QRegExp("[a-zA-Z|0-9|_|-|.|@]{1,30}")));
	ui.setPasswordReg->setValidator(new QRegExpValidator(QRegExp("[a-zA-Z|0-9|_|!|@|#|$|%|^|&|*|(|)]{1,40}")));
	ui.RePassword->setValidator(new QRegExpValidator(QRegExp("[a-zA-Z|0-9|_|!|@|#|$|%|^|&|*|(|)]{1,40}")));
    ui.stackedWidget->setCurrentWidget(ui.main_second);
}

void QtWidgetsApplication0::on_Log_in_clicked()
{
	CheckFields* checkFields = new CheckFields(&ui);
	checkFields->ban();
	
    AccountsPage* page = new AccountsPage(this, &ui, accounts_db);
    page->remove_accounts();
    Session session(accounts_db, garten_db, &ui);
    int role = -1;
    Authorization authorization(accounts_db, &ui);
    role = authorization.begin();
    if (role == 0) {
        session.start_as_user(authorization.get_login());
    }
    else if (role == 1) {
        session.start_as_admin(authorization.get_login());
    }
    AccountsPage *acc = new AccountsPage(this,&ui,accounts_db);

	QString str = QString::fromStdString(ui.setLogin->text().toStdString());

	ui.label_18->setText(str);
	ui.label_14->setText(str);
}

void QtWidgetsApplication0::on_Back_clicked()
{
    ui.stackedWidget->setCurrentWidget(ui.main_first);
	ui.label_5->setText("");
	ui.label_inf->setText("");
	ui.setLoginReg->clear();
	ui.setPasswordReg->clear();
	ui.RePassword->clear();
	ui.setLogin->clear();
	ui.setPassword->clear();
}

void QtWidgetsApplication0::on_Back_2_clicked()
{
	AccountsPage* acc = new AccountsPage(this, &ui, accounts_db);
	acc->remove_accounts();
	acc->create_table_for_accounts();
    ui.stackedWidget->setCurrentWidget(ui.page);
    ui.page->update();
}

void QtWidgetsApplication0::on_Register_begin_clicked()
{
    Registration registration(accounts_db, &ui);
    registration.begin();
}

void QtWidgetsApplication0::on_pushButton_8_clicked()
{
    ui.stackedWidget->setCurrentWidget(ui.main_first);
	ui.setLogin->clear();
	ui.setPassword->clear();
	ui.label_inf->setText("");
}

void QtWidgetsApplication0::on_pushButton_4_clicked()
{
	ui.pushButton_4->setStyleSheet("QPushButton{"
		"background-color: rgb(255, 239, 250);"
		"border-style: solid;"
		"border-width: 3px;"
		"border-color: rgb(85, 0, 0);"
		"border-radius: 25px;"
		"font: 14pt \"Rockwell\";"
		"min-width: 4em;"
		"color: rgb(180, 155, 255);"
		"padding: 3px; }"
		"QPushButton::hover{"
		"background-color: rgb(255, 239, 250);"
		"border-style: solid;"
		"border-color: rgb(180, 155, 255);"
		"color: rgb(180, 155, 255); }");
	ui.pushButton_5->setStyleSheet("QPushButton{"
		"background-color: rgb(255, 236, 220);"
		"border-style: solid;"
		"border-width: 3px;"
		"border-color: rgb(85, 0, 0);"
		"border-radius: 25px;"
		"font: 14pt \"Rockwell\";"
		"min-width: 4em;"
		"padding: 3px; }"
		"QPushButton::hover{"
		"background-color: rgb(255, 239, 250);"
		"border-style: solid;"
		"border-color: rgb(180, 155, 255);"
		"color: rgb(180, 155, 255); }");
	ui.pushButton_10->setStyleSheet("QPushButton{"
		"background-color: rgb(255, 236, 220);"
		"border-style: solid;"
		"border-width: 3px;"
		"border-color: rgb(85, 0, 0);"
		"border-radius: 25px;"
		"font: 14pt \"Rockwell\";"
		"min-width: 4em;"
		"padding: 3px; }"
		"QPushButton::hover{"
		"background-color: rgb(255, 239, 250);"
		"border-style: solid;"
		"border-color: rgb(180, 155, 255);"
		"color: rgb(180, 155, 255); }");
    AccountsPage* page = new AccountsPage(this, &ui, accounts_db);
    page->remove_accounts();
    page->create_table_for_accounts();
}

void QtWidgetsApplication0::on_btn_clicked() {
    ui.stackedWidget->setCurrentWidget(ui.main_first);
    ui.stackedWidget->setCurrentWidget(ui.page_10);     
}

void QtWidgetsApplication0::on_remove_acc_clicked()
{
	AccountsPage* account = new AccountsPage(this, &ui, accounts_db);
	account->delete_account();
	account->remove_accounts();
	account->create_table_for_accounts();
}

void QtWidgetsApplication0::on_accounts_edit_clicked()
{
    ui.stackedWidget->setCurrentWidget(ui.page_11);
}

void QtWidgetsApplication0::on_Back_3_clicked()
{
	AccountsPage* account = new AccountsPage(this, &ui, accounts_db);
    ui.stackedWidget->setCurrentWidget(ui.page);
	account->remove_accounts();
	account->create_table_for_accounts();
	ui.setLogin_reg_2->clear();
	ui.set_password_reg->clear();
	ui.set_repassword_reg->clear();
	ui.label_inf_2->setText("");
}

void QtWidgetsApplication0::on_add_account_clicked()
{
	AccountsPage Account(this, &ui, accounts_db);
	QMessageBox msgBox;
	msgBox.setText("Are you sure?");
	msgBox.setIcon(QMessageBox::Information);
	msgBox.setInformativeText("");
	msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
	msgBox.setDefaultButton(QMessageBox::Ok);
	msgBox.setWindowIcon(QPixmap("time_management_tasks_to_do_list_planning_icon_188710.ico"));
	msgBox.setWindowTitle("Confirm menu!");
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
		Account.add_new_account();
	case QMessageBox::Cancel:
		Account.remove_accounts();
		Account.create_table_for_accounts();
		ui.stackedWidget->setCurrentWidget(ui.page_11);
	default:
		return;
	}
}

void QtWidgetsApplication0::on_pushButton_5_clicked()
{
	ui.pushButton_4->setStyleSheet("QPushButton{"
		"background-color: rgb(255, 236, 220);"
		"border-style: solid;"
		"border-width: 3px;"
		"border-color: rgb(85, 0, 0);"
		"border-radius: 25px;"
		"font: 14pt \"Rockwell\";"
		"min-width: 4em;"
		"padding: 3px; }"
		"QPushButton::hover{"
		"background-color: rgb(255, 239, 250);"
		"border-style: solid;"
		"border-color: rgb(180, 155, 255);"
		"color: rgb(180, 155, 255); }");
	ui.pushButton_5->setStyleSheet("QPushButton{"
		"background-color: rgb(255, 239, 250);"
		"border-style: solid;"
		"border-width: 3px;"
		"border-color: rgb(85, 0, 0);"
		"border-radius: 25px;"
		"font: 14pt \"Rockwell\";"
		"min-width: 4em;"
		"color: rgb(180, 155, 255);"
		"padding: 3px; }"
		"QPushButton::hover{"
		"background-color: rgb(255, 239, 250);"
		"border-style: solid;"
		"border-color: rgb(180, 155, 255);"
		"color: rgb(180, 155, 255); }");
	ui.pushButton_10->setStyleSheet("QPushButton{"
		"background-color: rgb(255, 236, 220);"
		"border-style: solid;"
		"border-width: 3px;"
		"border-color: rgb(85, 0, 0);"
		"border-radius: 25px;"
		"font: 14pt \"Rockwell\";"
		"min-width: 4em;"
		"padding: 3px; }"
		"QPushButton::hover{"
		"background-color: rgb(255, 239, 250);"
		"border-style: solid;"
		"border-color: rgb(180, 155, 255);"
		"color: rgb(180, 155, 255); }");

	GartenPage* garten = new GartenPage(this, &ui, garten_db);
	garten->update_list();
	
	
}

void QtWidgetsApplication0::on_add_new_garten_clicked()
{
	GartenPage* garten = new GartenPage(this, &ui, garten_db);
    ui.stackedWidget->setCurrentWidget(ui.page_12);
	ui.information_4->setStyleSheet("background-color: rgb(255, 236, 220);"
		"border: 2px solid gray;"
		"border-width: 3px;"
		"border-radius: 50px;"
		"border-color: rgb(85, 0, 0);"
		"font: 14pt \"Rockwell\";"
		"min-width: 10em;"
		"color: rgb(255,236,220);"
		"padding: 6px;"
	);
	ui.label_28->clear();
}

void QtWidgetsApplication0::on_add_account_2_clicked()
{
	GartenPage garten(this, &ui, garten_db);
	garten.add_new_garten();
}

void QtWidgetsApplication0::on_Back_4_clicked()
{
	GartenPage* garten = new GartenPage(this, &ui, garten_db);
	garten->update_list();
	ui.stackedWidget->setCurrentWidget(ui.page);
}

void QtWidgetsApplication0::on_Back_9_clicked()
{
	ui.stackedWidget->setCurrentWidget(ui.page);
	GartenPage* garten = new GartenPage(this, &ui, garten_db);
	garten->update_list();
	ui.label_31->setText("");
}

void QtWidgetsApplication0::on_search_acc_clicked()
{
	AccountsPage* Account = new AccountsPage(this, &ui, accounts_db);
	Account->remove_accounts_search();
	Account->remove_accounts();
	Account->find_by_login();
}

void QtWidgetsApplication0::on_pushButton_10_clicked()
{
	ui.pushButton_4->setStyleSheet("QPushButton{"
		"background-color: rgb(255, 236, 220);"
		"border-style: solid;"
		"border-width: 3px;"
		"border-color: rgb(85, 0, 0);"
		"border-radius: 25px;"
		"font: 14pt \"Rockwell\";"
		"min-width: 4em;"
		"padding: 3px; }"
		"QPushButton::hover{"
		"background-color: rgb(255, 239, 250);"
		"border-style: solid;"
		"border-color: rgb(180, 155, 255);"
		"color: rgb(180, 155, 255); }");
	ui.pushButton_5->setStyleSheet("QPushButton{"
		"background-color: rgb(255, 236, 220);"
		"border-style: solid;"
		"border-width: 3px;"
		"border-color: rgb(85, 0, 0);"
		"border-radius: 25px;"
		"font: 14pt \"Rockwell\";"
		"min-width: 4em;"
		"padding: 3px; }"
		"QPushButton::hover{"
		"background-color: rgb(255, 239, 250);"
		"border-style: solid;"
		"border-color: rgb(180, 155, 255);"
		"color: rgb(180, 155, 255); }");
	ui.pushButton_10->setStyleSheet("QPushButton{"
		"background-color: rgb(255, 239, 250);"
		"border-style: solid;"
		"border-width: 3px;"
		"border-color: rgb(85, 0, 0);"
		"border-radius: 25px;"
		"font: 14pt \"Rockwell\";"
		"min-width: 4em;"
		"color: rgb(180, 155, 255);"
		"padding: 3px; }"
		"QPushButton::hover{"
		"background-color: rgb(255, 239, 250);"
		"border-style: solid;"
		"border-color: rgb(180, 155, 255);"
		"color: rgb(180, 155, 255); }");

	GartensInfo* garten = new GartensInfo(this, &ui, garten_db);
	garten->update_list();
}

void QtWidgetsApplication0::on_delete_gart_clicked()
{
	GartenPage* garten = new GartenPage(this, &ui, garten_db);
	
	garten->delete_garten();
	garten->update_list();
	ui.stackedWidget->setCurrentWidget(ui.page);
}

void QtWidgetsApplication0::on_Back_10_clicked()
{
	GartensInfo* garten = new GartensInfo(this, &ui, garten_db);
	garten->update_list();
	ui.stackedWidget->setCurrentWidget(ui.page);
}


void QtWidgetsApplication0::on_Path_clicked()
{
	GartenPage* garten = new GartenPage(this, &ui, garten_db);
	ui.information_4->setPlainText(QString::fromStdString(garten->path_to_image()));
	garten->set_image_to_add();
	ui.information_7->setStyleSheet("background-color: rgb(255, 236, 220);"
		"border-style: solid;"
		"border-width: 3px;"
		"border-radius: 5px; "
		"border-color: rgb(85,0,0)");
}

void QtWidgetsApplication0::on_Path_2_clicked()
{
	GartenPage* garten = new GartenPage(this, &ui, garten_db);
	ui.information_5->setPlainText(QString::fromStdString(garten->path_to_image()));
	garten->set_new_image_on_edit();
	
}

void QtWidgetsApplication0::on_Back_12_clicked()
{
	ui.stackedWidget->setCurrentWidget(ui.page_14);
}

void QtWidgetsApplication0::on_view_photo_clicked()
{
	string field_for_search = ui.label_21->text().toStdString();
	string path = garten_db->get_text("NUMBER", field_for_search, 7);
	ui.stackedWidget->setCurrentWidget(ui.page_15);

	QPixmap pic2(QString::fromStdString(path));
	QSize PicSize(801, 571);
	pic2 = pic2.scaled(PicSize, Qt::KeepAspectRatio);

	ui.label_img->setPixmap(pic2);

}
