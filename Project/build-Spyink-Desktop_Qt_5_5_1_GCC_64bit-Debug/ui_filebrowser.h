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
#include <QtWidgets/QTreeWidget>

QT_BEGIN_NAMESPACE

class Ui_FileBrowser
{
public:
    QDialogButtonBox *buttonBox;
    QTreeWidget *fileTreeWidget;

    void setupUi(QDialog *FileBrowser)
    {
        if (FileBrowser->objectName().isEmpty())
            FileBrowser->setObjectName(QStringLiteral("FileBrowser"));
        FileBrowser->resize(479, 400);
        buttonBox = new QDialogButtonBox(FileBrowser);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(120, 350, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        fileTreeWidget = new QTreeWidget(FileBrowser);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        fileTreeWidget->setHeaderItem(__qtreewidgetitem);
        fileTreeWidget->setObjectName(QStringLiteral("fileTreeWidget"));
        fileTreeWidget->setGeometry(QRect(20, 20, 441, 311));

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
