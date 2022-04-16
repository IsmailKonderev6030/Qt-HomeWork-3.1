#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    file.setFileName("");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,"Выбор файла txt",QDir::currentPath(),"Text(*.txt)");
    if(filename.size()){
        file.setFileName(filename);
        if(file.open(QIODevice::ReadWrite)){
            QByteArray text = file.readAll();
            ui->plainTextEdit->setPlainText(text);
        }
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    QString filename = QFileDialog::getSaveFileName(this,"Выбор файла txt",QDir::currentPath(),"Text(*.txt)");
    if(filename.size()){
        file.setFileName(filename);
        if(file.open(QIODevice::WriteOnly)){
            QString str = ui->plainTextEdit->toPlainText();
            QByteArray text = str.toUtf8();
            file.write(text);
            file.close();
            ui->plainTextEdit->setPlainText("");
        }
    }
}


void MainWindow::on_pushButton_3_clicked()
{
    InfoDialog test;
    test.OpenDialogWindow("about.txt");
    test.exec();
}

