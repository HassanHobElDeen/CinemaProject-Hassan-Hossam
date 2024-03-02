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
    bool found = false;
    QString str=ui -> month ->currentText();
    QString f=ui->day->text();
    QString r=ui->year->text();
    QString username1 =( ui->register_username ->text());
    QString pass1=(ui->register_pass->text());
    QString pass2=(ui->register_pass_2->text());
    //int month = str.toInt();
    //int day=f.toInt();
    int year=r.toInt();
    bool acctype=ui->groupBox_acctype->isChecked();
    bool genre=ui->genre->isChecked();
    bool gender = ui ->groupBox_gender->isChecked();
    if(acctype || genre || gender)
    {

    }
    else
    {
        ui -> register_status ->setVisible(true);
        ui->register_status->setText("ks");
    }

    if ((2024 - year) < 12)
    {
        ui -> year_status -> setVisible(true);
        ui -> year_status -> setText("Under 12 Years Old");
    }

    for (int i = 0; i < 100 ; i++)
    {
        if (username1 != usernames[i])
        {

        }
        else
        {
            found = true;
            break;
        }
    }
    if (found)
    {
        ui -> username_stat -> setVisible(true);
        ui -> username_stat -> setText("Username already exists");

    }

    if (pass1 != pass2)
    {
        ui -> password_stat -> setVisible(true);
        ui -> password_stat -> setText("Passwords Doesnt Match");
    }

    if ((username1 == " ") || (pass1 == " ") || (pass2 == " ") || (str == " ") || (f == " ") || (r == " "))
    {
        ui ->register_status -> setVisible(true);
        ui -> register_status -> setText("Missing Parameters, Please Fill Them in");

    }



}

