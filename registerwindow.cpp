#include "registerwindow.h"
#include "ui_registerwindow.h"
#include "Users.h"



RegisterWindow::RegisterWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);
    ui -> username_stat -> setVisible(false);
    ui -> password_stat -> setVisible(false);
    ui -> year_status -> setVisible(false);
    ui -> register_status -> setVisible(false);
}

RegisterWindow::~RegisterWindow()
{
    delete ui;
}

void RegisterWindow::on_reg_reg_clicked()
{
    QString username1 = ui->register_username->text();
    QString pass1 = ui->register_pass->text();
    QString pass2 = ui->register_pass_2->text();
    QString month = ui->month->currentText();
    QString day = ui->day->text();
    QString year = ui->year->text();
    bool acctype = ui->groupBox_acctype->isChecked();
    bool genre = ui->genre->isChecked();
    bool gender = ui->groupBox_gender->isChecked();

    // Reset all error messages
    ui->register_status->setVisible(false);
    ui->username_stat->setVisible(false);
    ui->password_stat->setVisible(false);

    if (username1.isEmpty() || pass1.isEmpty() || pass2.isEmpty() || year.isEmpty() || month.isEmpty() || day.isEmpty() || !acctype || !genre || !gender)
    {
        // Display error message
        ui->register_status->setVisible(true);
        ui->register_status->setText("Missing Parameters, Please Fill Them in");
        return;
    }
    else if (std::any_of(username1.begin(), username1.end(), [=](const QString& existingUsername) { return existingUsername == username1; }))
    {
        // Check if username already exists
        ui->username_stat->setVisible(true);
        ui->username_stat->setText("Username already exists");
        return;
    }
    else if (pass1 != pass2)
    {
        // Check if passwords match
        ui->password_stat->setVisible(true);
        ui->password_stat->setText("Passwords Don't Match");
        return;
    }
    else
    {
        // Register the user
        usernames[usersCount] = username1;
        passwords[usersCount] = pass1;
        ages[usersCount] = 2024 - year.toInt();
        usersCount++;
    }
}

