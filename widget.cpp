#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setControl();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int coin)
{
    money += coin;
    ui->lcdNumber->display(money);
    setControl();
}

void Widget::setControl()
{
    ui->pbCoffee->setEnabled(money >= 200);
    ui->pbTea->setEnabled(money >= 150);
    ui->pbMilk->setEnabled(money >= 100);
}


void Widget::on_pbCoin500_clicked()
{
   changeMoney(500);
}


void Widget::on_pbCoin100_clicked()
{
    changeMoney(100);
}



void Widget::on_pbCoin50_clicked()
{
    changeMoney(50);
}



void Widget::on_pbCoin10_clicked()
{
   changeMoney(10);
}


void Widget::on_pbCoffee_clicked()
{
    changeMoney(-200);
}


void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
}


void Widget::on_pbMilk_clicked()
{
    changeMoney(-100);
}




void Widget::on_pbReset_clicked()
{
    int changes500 = 0, changes100 = 0, changes50 = 0, changes10 = 0;
    QMessageBox msgBox;
    QString message;

    changes500 = (money / 100) / 5;
    changes100 = (money / 100) % 5;
    changes50 = (money % 100) / 50;
    changes10 = ((money % 100) % 50)/10;

    message = QString(" 500 : %1 \n 100 : %2\n 50 : %3\n 10 : %4").arg(changes500).arg(changes100).arg(changes50).arg(changes10);

    msgBox.information(this, "reset", message, QMessageBox::Ok);
    changeMoney(-money);
}

