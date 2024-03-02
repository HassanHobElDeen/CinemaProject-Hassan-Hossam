#include "welcomewindow.h"
#include "ui_welcomewindow.h"

WelcomeWindow::WelcomeWindow(QString username, int age,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::WelcomeWindow)
{
    ui->setupUi(this);
    QString srt = QString::number(age);

    ui -> hello -> setText("Hello " + username +" " + srt);
    QPixmap pix("C:\\Users\\hassa\\Downloads\\cinema pic.jpg");
    int w = ui ->pic -> width();
    int u = ui -> pic -> height();
    ui -> pic -> setPixmap(pix.scaled(w,u,Qt::KeepAspectRatio));
}

WelcomeWindow::~WelcomeWindow()
{
    delete ui;
}
