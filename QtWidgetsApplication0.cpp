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
}

void QtWidgetsApplication0::on_Back_clicked()
{
    ui.stackedWidget->setCurrentWidget(ui.main_first);
}

void QtWidgetsApplication0::on_Back_2_clicked()
{
    ui.stackedWidget->setCurrentWidget(ui.page);
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

    QString str;
    QLabel* label_acc;

    vector<int>ids = sql_db->get_ints(5);

    for (int row = 0; row < ids.size(); row++) {
        str = QString::fromStdString(accounts_db->get_text("ID", to_string(ids[row]), 0));
        label_acc = new QLabel(str, ui.page_10);
        label_acc->setObjectName("labels");
        label_acc->setGeometry(530, 75, 131, 41);
        label_acc->show();
    }
    
}

void QtWidgetsApplication0::on_checkBox_clicked()
{
    account.access = 1;
}
