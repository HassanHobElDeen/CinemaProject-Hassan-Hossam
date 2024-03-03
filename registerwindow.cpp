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
    bool gendermale = ui -> male -> isChecked();
    bool genderF= ui -> female -> isChecked();
    bool acctypead = ui -> admin -> isChecked();
    bool acctypeus = ui -> user -> isChecked();
    bool action = ui -> action -> isChecked();
    bool comedy = ui -> comedy -> isChecked();
    bool romance = ui ->romantic -> isChecked();
    bool horror = ui -> horror -> isChecked();
    bool drama = ui -> drama -> isChecked();
    bool other = ui -> other -> isChecked();
    ui ->username_stat -> setText(" ");
    ui -> year_status -> setText(" ");
    ui -> password_stat -> setText(" ");
    ui -> register_status -> setText(" ");


    if
        (username1.isEmpty() || pass1.isEmpty() || pass2.isEmpty() ||
        month.isEmpty() || day.isEmpty() || year.isEmpty() ||
        ((!genderF) && (!gendermale)) || ((!acctypead) && (!acctypeus )) ||
        ((!action) && (!comedy) && (!romance) && (!horror) && (!drama) && (!other)))
    {
        ui->register_status->setVisible(true);
        ui -> register_status ->setStyleSheet("QLabel {background-color: transparent; color: red;}");
        ui->register_status->setText("Missing Parameters, Please Fill Them in");
        return;
    }

    if (pass1 != pass2) {
        ui->password_stat->setVisible(true);
        ui -> password_stat ->setStyleSheet("QLabel {background-color: transparent; color: red;}");
        ui->password_stat->setText("Passwords Don't Match");
        return;
    }

    int userYear = year.toInt();
    if ((2024 - userYear) < 12) {
        ui->year_status->setVisible(true);
        ui -> year_status ->setStyleSheet("QLabel {background-color: transparent; color: red;}");
        ui->year_status->setText("Under 12 Years Old");
        return;
    }

    for (int i = 0; i < usersCount; ++i) {
        if (username1 == usernames[i]) {
            ui->username_stat->setVisible(true);
            ui -> username_stat ->setStyleSheet("QLabel {background-color: transparent; color: red;}");
            ui->username_stat->setText("Username already exists");
            return;
        }
    }

    if (usersCount < 100) {
        usernames[usersCount] = username1;
        passwords[usersCount] = pass1;
        ages[usersCount] = 2024 - userYear;
        ++usersCount;
        ui->register_status->setVisible(true);
        ui -> register_status ->setStyleSheet("QLabel {background-color: transparent; color: green;}");
        ui->register_status->setText("Registration Successful");
    } else {
        ui->register_status->setVisible(true);
        ui -> register_status ->setStyleSheet("QLabel {background-color: transparent; color: red;}");
        ui->register_status->setText("Maximum users reached");
    }
}

