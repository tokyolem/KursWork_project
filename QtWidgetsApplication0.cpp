#include "QtWidgetsApplication0.h"

QtWidgetsApplication0::QtWidgetsApplication0(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
   
}

void QtWidgetsApplication0::set_account_db(SQLdb* accounts_db) {
    this->accounts_db = accounts_db;
}

void QtWidgetsApplication0::on_Register_clicked()
{
    ui.stackedWidget->setCurrentWidget(ui.main_second);
}

void QtWidgetsApplication0::on_Log_in_clicked()
{
    AccountsPage* page = new AccountsPage(this, &ui, accounts_db);
    page->remove_accounts();
    Session session(accounts_db, abonent_db, &ui);
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
}

void QtWidgetsApplication0::on_Back_2_clicked()
{
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
}

void QtWidgetsApplication0::on_pushButton_4_clicked()
{
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
	string str = ui.label_14->text().toStdString();
	string field_for_delete = ui.label_9->text().toStdString();

	this->session_account_login = session_account_login;

	//if (str == session_account_login) {
 //       ui.label_15->setText("You can't to delete yourself account!");
	//	ui.stackedWidget->setCurrentWidget(ui.page_10);
	//}
	//else {
		QMessageBox msgBox;
		msgBox.setText("Are you sure?");
		msgBox.setIcon(QMessageBox::Information);
		msgBox.setInformativeText("");
		msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
		msgBox.setDefaultButton(QMessageBox::Ok);
		msgBox.setStyleSheet("QMessageBox{border: 2px solid gray; border-width: 2px; border-radius: 10px; border-color: lightGray; font: bold 14px; min-width: 10em; padding: 6px; background-color: rgb(246, 228, 255); }");
		int ret = msgBox.exec();

		switch (ret) {
		case QMessageBox::Ok:
            ui.stackedWidget->setCurrentWidget(ui.page);
			accounts_db->delWeald("LOGIN='" + field_for_delete + "'");
		case QMessageBox::Cancel:
			ui.stackedWidget->setCurrentWidget(ui.page_10);
		default:
			return;
		}
	/*}*/
}
