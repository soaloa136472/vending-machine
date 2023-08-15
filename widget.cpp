#include "widget.h"
#include "./ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 초기 잔액을 0으로 설정
    money = 0;

    // 돈의 금액에 따라 음료 버튼 활성화/비활성화 설정
    updateButtonActivation();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int diff)
{
    money += diff;
    ui->lcdNumber->display(money);

    // 돈의 금액에 따라 음료 버튼 활성화/비활성화 설정
    updateButtonActivation();
}

void Widget::on_pb10_clicked()
{
    changeMoney(10);
}

void Widget::on_pb50_clicked()
{
    changeMoney(50);
}

void Widget::on_pb100_clicked()
{
    changeMoney(100);
}

void Widget::on_pb500_clicked()
{
    changeMoney(500);
}

void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
}

void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
}

void Widget::on_pbMilk_clicked()
{
    changeMoney(-200);
}

void Widget::on_pbReset_clicked()
{
    // 각 동전/지폐의 개수를 계산하여 보여줌
    QString message = QString("500원: %1개\n100원: %2개\n50원: %3개\n10원: %4개")
                          .arg(money/500).arg(money%500/100).arg(money%100/50).arg(money%50/10);
    QMessageBox::information(this, "Reset", message);

    // 잔액을 0으로 초기화
    money = 0;
    ui->lcdNumber->display(money);

    // 돈의 금액에 따라 음료 버튼 활성화/비활성화 설정
    updateButtonActivation();
}

void Widget::updateButtonActivation()
{
    ui->pbCoffee->setEnabled(money >= 100);
    ui->pbTea->setEnabled(money >= 150);
    ui->pbMilk->setEnabled(money >= 200);
}

