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

    while((username1.isEmpty()) || (pass1.isEmpty()) || (pass2.isEmpty()) || (year.isEmpty()) || (month.isEmpty()) || (day.isEmpty())||(!acctype) || (!genre) || (!gender))
    {
        ui ->register_status -> setVisible(true);
        ui -> register_status -> setText("Missing Parameters, Please Fill Them in");
    }
    for (int i = 0; i < 100 ; i++)
    {
        if (username1 == usernames[i])
        {
            ui -> username_stat -> setVisible(true);
            ui -> username_stat -> setText("Username already exists");

        }

        else
        {
            if (pass1 != pass2)
            {
                ui -> password_stat -> setVisible(true);
                ui -> password_stat -> setText("Passwords Doesnt Match");
            }
            else
            {
                for(int i=usersCount+1;i<100;i++)
                {
                    usernames[i]=username1;
                    passwords[i]=pass1;
                    ages[i]=2024-year.toInt();
                    usersCount++;
                }

            }

        }
    }
}

