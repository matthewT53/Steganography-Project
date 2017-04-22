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
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_PasswordForm
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QLabel *label_3;

    void setupUi(QDialog *PasswordForm)
    {
        if (PasswordForm->objectName().isEmpty())
            PasswordForm->setObjectName(QStringLiteral("PasswordForm"));
        PasswordForm->resize(400, 300);
        buttonBox = new QDialogButtonBox(PasswordForm);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(PasswordForm);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 120, 111, 21));
        lineEdit = new QLineEdit(PasswordForm);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(140, 120, 231, 27));
        label_2 = new QLabel(PasswordForm);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(60, 160, 111, 21));
        lineEdit_2 = new QLineEdit(PasswordForm);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(140, 160, 231, 27));
        label_3 = new QLabel(PasswordForm);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(140, 40, 191, 17));

        retranslateUi(PasswordForm);
        QObject::connect(buttonBox, SIGNAL(accepted()), PasswordForm, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), PasswordForm, SLOT(reject()));

        QMetaObject::connectSlotsByName(PasswordForm);
    } // setupUi

    void retranslateUi(QDialog *PasswordForm)
    {
        PasswordForm->setWindowTitle(QApplication::translate("PasswordForm", "Dialog", 0));
        label->setText(QApplication::translate("PasswordForm", "Password:", 0));
        label_2->setText(QApplication::translate("PasswordForm", "Confirm:", 0));
        label_3->setText(QApplication::translate("PasswordForm", "Set a password", 0));
    } // retranslateUi

};

namespace Ui {
    class PasswordForm: public Ui_PasswordForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PASSWORDFORM_H
