#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    int money = 0; // 현재 잔액

    void updateButtonActivation(); // 돈의 금액에 따라 음료 버튼 활성화/비활성화 설정

private slots:
    void changeMoney(int diff);
    void on_pb10_clicked();
    void on_pb50_clicked();
    void on_pb100_clicked();
    void on_pb500_clicked();
    void on_pbCoffee_clicked();
    void on_pbTea_clicked();
    void on_pbMilk_clicked();
    void on_pbReset_clicked();
};

#endif // WIDGET_H
