#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "Users.h"
#include "welcomewindow.h"
#include "registerwindow.h"

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    ui -> login_status -> setVisible(false);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_login_push_clicked()
{
    for(int i=0;i<100;i++)
    {
        if((ui ->username -> text()) == usernames[i] && (ui-> password->text())==passwords[i])
        {
            hide();
            WelcomeWindow* p= new WelcomeWindow(usernames[i],ages[i],this);
            p->show();
        }
        else
        {
            ui -> login_status -> setVisible(true);
            ui ->login_status -> setText("Wrong Username Or Password");
        }
    }
}


void LoginWindow::on_register_push_clicked()
{
    hide();
    RegisterWindow * R = new RegisterWindow(this);
    R -> show();
}

