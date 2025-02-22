#include "lightweightbaby.h"
#include "ui_lightweightbaby.h"

lightweightbaby::lightweightbaby(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::lightweightbaby)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    ui->progressBar->setVisible(false);

}

lightweightbaby::~lightweightbaby()
{
    delete ui;
}

void lightweightbaby::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(ui->stackedWidget->currentIndex() + 1);
}

void lightweightbaby::on_pushButton_2_clicked()
{
    QApplication::quit();
}

void lightweightbaby::on_pushButton_3_clicked()
{
    ui->progressBar->setVisible(true);

    int currentValue = ui->progressBar->value();
    int newValue = currentValue + 50;

    if (newValue > 100) {
        newValue = 100;
    }

    ui->progressBar->setValue(newValue);
}

void lightweightbaby::on_progressBar_valueChanged(int value)
{
    if (value == 100) {
        ui->stackedWidget->setCurrentIndex(ui->stackedWidget->currentIndex() + 1);
    }
}

