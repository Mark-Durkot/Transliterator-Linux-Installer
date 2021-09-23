#ifndef PASSWORDDIALOG_H
#define PASSWORDDIALOG_H

#include <QDialog>

namespace Ui {
class PasswordDialog;
}

class PasswordDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PasswordDialog(QString &pass, QWidget *parent = nullptr);
    ~PasswordDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::PasswordDialog *ui;
    QString &password;
};

#endif // PASSWORDDIALOG_H
