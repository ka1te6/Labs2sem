#ifndef LIGHTWEIGHTBABY_H
#define LIGHTWEIGHTBABY_H

#include <QMainWindow>

namespace Ui {
class lightweightbaby;
}

class lightweightbaby : public QMainWindow
{
    Q_OBJECT

public:
    explicit lightweightbaby(QWidget *parent = 0);
    ~lightweightbaby();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_progressBar_valueChanged(int value);

private:
    Ui::lightweightbaby *ui;
};

#endif // LIGHTWEIGHTBABY_H
