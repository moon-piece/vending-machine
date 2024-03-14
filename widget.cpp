#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this); // created
    changeEnabled();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeEnabled(){
//    if (money >= 100)
//        ui->pbCoffee->setEnabled(true);
//    else
//        ui->pbCoffee->setEnabled(false);
    ui->pbCoffee->setEnabled(money >= 100);
    ui->pbTea->setEnabled(money >= 200);
    ui->pbTang->setEnabled(money >= 300);
    ui->pbReset->setEnabled(money > 0);
}

void Widget::changeMoney(int diff) {
    money += diff;
    ui->lcdNumber->display(money);
    changeEnabled();
}

void Widget::on_pbCoin10_clicked()
{
    changeMoney(10);
}


void Widget::on_pbCoin50_clicked()
{
    changeMoney(50);
}


void Widget::on_pbCoin100_clicked()
{
    changeMoney(100);
}


void Widget::on_pbCoin500_clicked()
{
    changeMoney(500);
}


void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
}


void Widget::on_pbTea_clicked()
{
    changeMoney(-200);
}


void Widget::on_pbTang_clicked()
{
    changeMoney(-300);
}


void Widget::on_pbReset_clicked()
{
    QMessageBox mb;
    int change_500, change_100, change_50, change_10;
    QString msg = "";

    if (money >= 500) {
        change_500 = int(money / 500);
        money %= 500;
        msg = msg + "500won: " + QString::number(change_500) + "EA\n";

    }
    if (money >= 100) {
        change_100 = int(money / 100);
        money %= 100;
        msg = msg + "100won: " + QString::number(change_100) + "EA\n";
    }
    if (money >= 50) {
        change_50 = int(money / 50);
        money %= 50;
        msg = msg + "50won: " + QString::number(change_50) + "EA\n";
    }
    if (money >= 10) {
        change_10 = int(money / 10);
        money %= 10;
        msg = msg + "10won: " + QString::number(change_10) + "EA\n";
    }

    mb.information(nullptr, "Change", msg);
    changeMoney(0);
}

