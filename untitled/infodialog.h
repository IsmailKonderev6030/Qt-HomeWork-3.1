#ifndef INFODIALOG_H
#define INFODIALOG_H

#include <QDialog>
#include <QString>
#include <QFile>

namespace Ui {
class InfoDialog;
}

class InfoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InfoDialog(QWidget *parent = nullptr);
    ~InfoDialog();

    void OpenDialogWindow(const QString);

private:
    Ui::InfoDialog *ui;
};

#endif // INFODIALOG_H
