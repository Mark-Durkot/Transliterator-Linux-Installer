#include "passworddialog.h"
#include "ui_passworddialog.h"

PasswordDialog::PasswordDialog(QString &pass, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PasswordDialog),
    password(pass)
{
    ui->setupUi(this);
}

PasswordDialog::~PasswordDialog()
{
    delete ui;
}

void PasswordDialog::on_buttonBox_accepted()
{
    password = ui->lineEdit_password->text();
    this->accept();
}

void PasswordDialog::on_buttonBox_rejected()
{
    password = "";
    this->reject();
}
