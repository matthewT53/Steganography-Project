/********************************************************************************
** Form generated from reading UI file 'filebrowser.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILEBROWSER_H
#define UI_FILEBROWSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_FileBrowser
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *FileBrowser)
    {
        if (FileBrowser->objectName().isEmpty())
            FileBrowser->setObjectName(QStringLiteral("FileBrowser"));
        FileBrowser->resize(400, 300);
        buttonBox = new QDialogButtonBox(FileBrowser);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(FileBrowser);
        QObject::connect(buttonBox, SIGNAL(accepted()), FileBrowser, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), FileBrowser, SLOT(reject()));

        QMetaObject::connectSlotsByName(FileBrowser);
    } // setupUi

    void retranslateUi(QDialog *FileBrowser)
    {
        FileBrowser->setWindowTitle(QApplication::translate("FileBrowser", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class FileBrowser: public Ui_FileBrowser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILEBROWSER_H
