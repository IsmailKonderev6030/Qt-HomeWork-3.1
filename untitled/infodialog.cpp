#include "infodialog.h"
#include "ui_infodialog.h"

InfoDialog::InfoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InfoDialog)
{
    ui->setupUi(this);
}

InfoDialog::~InfoDialog()
{
    delete ui;
}

void InfoDialog::OpenDialogWindow(const QString DirFile){
    if(DirFile.size()){
        QFile infoFile(DirFile);
        if(infoFile.open(QIODevice::ReadOnly)){
            QByteArray infoText = infoFile.readAll();
            ui->textBrowser->setText(infoText);
        }
    }
}

