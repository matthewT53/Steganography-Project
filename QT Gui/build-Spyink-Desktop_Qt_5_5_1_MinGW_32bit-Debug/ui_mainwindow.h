/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *AppName;
    QRadioButton *radio_hide;
    QRadioButton *radio_reveal;
    QPushButton *action;
    QLabel *media_label;
    QLabel *io_label;
    QLineEdit *media_edit;
    QLineEdit *io_edit;
    QToolButton *media_file;
    QToolButton *io_file;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(271, 313);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        AppName = new QLabel(centralWidget);
        AppName->setObjectName(QStringLiteral("AppName"));
        AppName->setGeometry(QRect(30, 10, 251, 61));
        AppName->setStyleSheet(QStringLiteral(""));
        radio_hide = new QRadioButton(centralWidget);
        radio_hide->setObjectName(QStringLiteral("radio_hide"));
        radio_hide->setGeometry(QRect(70, 80, 117, 22));
        radio_hide->setChecked(true);
        radio_reveal = new QRadioButton(centralWidget);
        radio_reveal->setObjectName(QStringLiteral("radio_reveal"));
        radio_reveal->setGeometry(QRect(130, 80, 117, 22));
        action = new QPushButton(centralWidget);
        action->setObjectName(QStringLiteral("action"));
        action->setGeometry(QRect(70, 240, 131, 41));
        media_label = new QLabel(centralWidget);
        media_label->setObjectName(QStringLiteral("media_label"));
        media_label->setGeometry(QRect(30, 110, 81, 17));
        io_label = new QLabel(centralWidget);
        io_label->setObjectName(QStringLiteral("io_label"));
        io_label->setGeometry(QRect(30, 170, 67, 17));
        media_edit = new QLineEdit(centralWidget);
        media_edit->setObjectName(QStringLiteral("media_edit"));
        media_edit->setGeometry(QRect(30, 130, 171, 21));
        io_edit = new QLineEdit(centralWidget);
        io_edit->setObjectName(QStringLiteral("io_edit"));
        io_edit->setGeometry(QRect(30, 200, 171, 21));
        media_file = new QToolButton(centralWidget);
        media_file->setObjectName(QStringLiteral("media_file"));
        media_file->setGeometry(QRect(210, 130, 31, 21));
        io_file = new QToolButton(centralWidget);
        io_file->setObjectName(QStringLiteral("io_file"));
        io_file->setGeometry(QRect(210, 200, 31, 21));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "SpyInk", 0));
        AppName->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:28pt; font-weight:600;\">HideMySh!t</span></p><p><br/></p></body></html>", 0));
        radio_hide->setText(QApplication::translate("MainWindow", "Hide", 0));
        radio_reveal->setText(QApplication::translate("MainWindow", "Reveal", 0));
        action->setText(QApplication::translate("MainWindow", "Hide", 0));
        media_label->setText(QApplication::translate("MainWindow", "Media file:", 0));
        io_label->setText(QApplication::translate("MainWindow", "Input file:", 0));
        media_file->setText(QApplication::translate("MainWindow", "...", 0));
        io_file->setText(QApplication::translate("MainWindow", "...", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
