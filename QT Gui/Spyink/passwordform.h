#ifndef PASSWORDFORM_H
#define PASSWORDFORM_H

#include <QDialog>
#include <QString>

namespace Ui {
class PasswordForm;
}

class PasswordForm : public QDialog
{
    Q_OBJECT

public:
    explicit PasswordForm(QWidget *parent = 0);
    QString getPassword();
    ~PasswordForm();

private:
    Ui::PasswordForm *ui;
    QString password;

private slots:
    void handle_ok_button();
    void handle_cancel_button();

};

#endif // PASSWORDFORM_H
