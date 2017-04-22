#include "passwordform.h"
#include "ui_passwordform.h"

#include <QMessageBox>

PasswordForm::PasswordForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PasswordForm)
{
    ui->setupUi(this);

    connect(ui->button_ok, SIGNAL(clicked()), this, SLOT( handle_ok_button() ));
    connect(ui->button_cancel, SIGNAL(clicked()), this, SLOT( handle_cancel_button() ));
}

PasswordForm::~PasswordForm()
{
    delete ui;
}

void PasswordForm::handle_ok_button()
{
    QString new_password = ui->password_1->text();
    QString confirm_password = ui->password_2->text();

    if (new_password == confirm_password){
        this->password = new_password;
        this->close();
    }

    else{
        QMessageBox::warning(this, "Password mismatch", "Passwords do not match, please enter the passwords again");
        ui->password_1->setText("");
        ui->password_2->setText("");
    }
}

void PasswordForm::handle_cancel_button()
{
    this->close();
}

QString PasswordForm::getPassword()
{
    return this->password;
}
