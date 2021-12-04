#include "QtWidgetsApplication0.h"
#include <QtWidgets/QApplication>
#include "SQLDataBase.h"
#include "Users.h"
#include "Registration.h"

void accounts_database(SQLdb* db);
void gartens_database(SQLdb* db);
void add_admin_in_db_if_not_found(SQLdb* db);
Ui::QtWidgetsApplication0Class* ui;

int main(int argc, char *argv[])
{
    SQLdb accounts_db(ACCOUNTS_DATABASE_FILENAME);
    SQLdb garten_db(GARTENS_DATABASE_FILENAME);

    accounts_database(&accounts_db);
    add_admin_in_db_if_not_found(&accounts_db);
    gartens_database(&garten_db);

    QApplication a(argc, argv);
    QtWidgetsApplication0 w;
    w.setWindowTitle("Application");
    w.setWindowIcon(QIcon("to_do_list_notes_tasks_icon_207099.ico"));
    w.set_account_db(&accounts_db);
    w.set_garten_db(&garten_db);
    w.show();
    return a.exec();
}

void accounts_database(SQLdb* db) {
    db->open_SQL();
    db->create_table({ NewSQL_part{ "LOGIN",  "TEXT NOT NULL"},
                 NewSQL_part{ "HASH",   "TEXT NOT NULL"},
                 NewSQL_part{ "SALT",   "TEXT NOT NULL"},
                 NewSQL_part{ "ROLE",   "INT NOT NULL"},
                 NewSQL_part{ "ACCESS", "INT NOT NULL"},
                 NewSQL_part{ "ID",     "INT PRIMARY KEY NOT NULL"} },
        ACCOUNTS_DATABASE_NAME);
}

void gartens_database(SQLdb* db) {
    db->open_SQL();
    db->create_table({ NewSQL_part{ "NUMBER",   "TEXT PRIMARY KEY NOT NULL"},
                NewSQL_part{ "QGROUP",          "INT NOT NULL"},
                NewSQL_part{ "QPLACES",         "INT NOT NULL"},
                NewSQL_part{ "AFFILICATION",    "TEXT NOT NULL"},
                NewSQL_part{ "INFORMATION",     "TEXT NOT NULL"},
                NewSQL_part{ "CERTAINPLACES",   "TEXT NOT NULL"},
                NewSQL_part{ "FREEPLACES",      "INT NOT NULL"},
                NewSQL_part{ "PATH",            "TEXT NOT NULL"} },
       GARTENS_DATABASE_NAME);
}

void add_admin_in_db_if_not_found(SQLdb* db) {

    CheckFields checkFields(ui);
    if (db->get_text("LOGIN", "admin", 2) == "") {
        string salt = checkFields.get_generated_salt();
        string salted_hash_password = checkFields.get_generated_hash("admin", salt);
        db->thrustBack({ "'admin'", "'" + salted_hash_password + "'", "'" + salt + "'", "1", "1", "1"});
        
    }
}
