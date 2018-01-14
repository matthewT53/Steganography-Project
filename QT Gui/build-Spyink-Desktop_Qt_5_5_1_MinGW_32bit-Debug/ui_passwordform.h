/********************************************************************************
** Form generated from reading UI file 'passwordform.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PASSWORDFORM_H
#define UI_PASSWORDFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_PasswordForm
{
public:
    QLabel *label;
    QLineEdit *password_1;
    QLabel *label_2;
    QLineEdit *password_2;
    QLabel *label_3;
    QPushButton *button_cancel;
    QPushButton *button_ok;

    void setupUi(QDialog *PasswordForm)
    {
        if (PasswordForm->objectName().isEmpty())
            PasswordForm->setObjectName(QStringLiteral("PasswordForm"));
        PasswordForm->resize(216, 161);
        label = new QLabel(PasswordForm);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 50, 111, 21));
        password_1 = new QLineEdit(PasswordForm);
        password_1->setObjectName(QStringLiteral("password_1"));
        password_1->setGeometry(QRect(80, 50, 101, 21));
        password_1->setEchoMode(QLineEdit::Password);
        label_2 = new QLabel(PasswordForm);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 80, 111, 21));
        password_2 = new QLineEdit(PasswordForm);
        password_2->setObjectName(QStringLiteral("password_2"));
        password_2->setGeometry(QRect(80, 80, 101, 21));
        password_2->setEchoMode(QLineEdit::Password);
        label_3 = new QLabel(PasswordForm);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(70, 0, 111, 41));
        label_3->setAutoFillBackground(false);
        button_cancel = new QPushButton(PasswordForm);
        button_cancel->setObjectName(QStringLiteral("button_cancel"));
        button_cancel->setGeometry(QRect(120, 120, 61, 21));
        button_ok = new QPushButton(PasswordForm);
        button_ok->setObjectName(QStringLiteral("button_ok"));
        button_ok->setGeometry(QRect(50, 120, 61, 21));

        retranslateUi(PasswordForm);

        QMetaObject::connectSlotsByName(PasswordForm);
    } // setupUi

    void retranslateUi(QDialog *PasswordForm)
    {
        PasswordForm->setWindowTitle(QApplication::translate("PasswordForm", "Enter password", 0));
        label->setText(QApplication::translate("PasswordForm", "Password:", 0));
        label_2->setText(QApplication::translate("PasswordForm", "Confirm:", 0));
        label_3->setText(QApplication::translate("PasswordForm", "<html><head/><body><p>Enter a password</p></body></html>", 0));
        button_cancel->setText(QApplication::translate("PasswordForm", "Cancel", 0));
        button_ok->setText(QApplication::translate("PasswordForm", "Ok", 0));
    } // retranslateUi

};

namespace Ui {
    class PasswordForm: public Ui_PasswordForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PASSWORDFORM_H
