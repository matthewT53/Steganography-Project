#ifndef PASSWORDFORM_H
#define PASSWORDFORM_H

#include <QDialog>

namespace Ui {
class PasswordForm;
}

class PasswordForm : public QDialog
{
    Q_OBJECT

public:
    explicit PasswordForm(QWidget *parent = 0);
    ~PasswordForm();

private:
    Ui::PasswordForm *ui;

};

#endif // PASSWORDFORM_H
