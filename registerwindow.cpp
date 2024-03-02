#include "registerwindow.h"
#include "ui_registerwindow.h"

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
    QString str=ui -> month ->currentText();
    QString f=ui->day->text();
    QString r=ui->year->text();
    QString x =( ui->register_username ->text());
    QString y=(ui->register_pass->text());
    QString z=(ui->register_pass_2->text());
    int month = str.toInt();
    int day=f.toInt();
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




}

