#include "welcomewindow.h"
#include "ui_welcomewindow.h"
#include "loginwindow.h"
WelcomeWindow::WelcomeWindow(QString username, int age,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::WelcomeWindow)
{
    ui->setupUi(this);
    QString srt = QString::number(age);

    ui -> hello -> setText("Hello " + username +" " + srt);
    QPixmap pix(":/new/image1/cinema pic.jpg");
    int w = ui ->pic -> width();
    int u = ui -> pic -> height();
    ui -> pic -> setPixmap(pix.scaled(w,u,Qt::KeepAspectRatio));
}

WelcomeWindow::~WelcomeWindow()
{
    delete ui;
}

void WelcomeWindow::on_logout_push_clicked()
{
    hide();
    LoginWindow *q=new LoginWindow(this);
    q -> show();

}

