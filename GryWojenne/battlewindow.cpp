#include "battlewindow.h"
#include "ui_battlewindow.h"

battlewindow::battlewindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::battlewindow)
{
    ui->setupUi(this);
}

battlewindow::~battlewindow()
{
    delete ui;
}

void battlewindow::on_pushButton_clicked()
{
    exit (1);
}

