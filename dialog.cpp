#include "dialog.h"
#include "ui_dialog.h"
#include <QFile>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    QFile file("about.txt");
    if(file.open(QIODevice::ReadOnly)){
        QString str = file.readAll();
        ui->label->setText(str);
    }
}

Dialog::~Dialog()
{
    delete ui;
}
