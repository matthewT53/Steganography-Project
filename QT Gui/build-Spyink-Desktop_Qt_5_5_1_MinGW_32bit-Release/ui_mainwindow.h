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
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *media_edit;
    QLineEdit *input_edit;
    QLineEdit *output_edit;
    QToolButton *media_file;
    QToolButton *input_file;
    QToolButton *output_file;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(292, 377);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        AppName = new QLabel(centralWidget);
        AppName->setObjectName(QStringLiteral("AppName"));
        AppName->setGeometry(QRect(30, 10, 251, 61));
        radio_hide = new QRadioButton(centralWidget);
        radio_hide->setObjectName(QStringLiteral("radio_hide"));
        radio_hide->setGeometry(QRect(80, 80, 117, 22));
        radio_hide->setChecked(true);
        radio_reveal = new QRadioButton(centralWidget);
        radio_reveal->setObjectName(QStringLiteral("radio_reveal"));
        radio_reveal->setGeometry(QRect(140, 80, 117, 22));
        action = new QPushButton(centralWidget);
        action->setObjectName(QStringLiteral("action"));
        action->setGeometry(QRect(80, 300, 121, 41));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 110, 81, 17));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 170, 67, 17));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 240, 81, 17));
        media_edit = new QLineEdit(centralWidget);
        media_edit->setObjectName(QStringLiteral("media_edit"));
        media_edit->setGeometry(QRect(30, 130, 221, 21));
        input_edit = new QLineEdit(centralWidget);
        input_edit->setObjectName(QStringLiteral("input_edit"));
        input_edit->setGeometry(QRect(30, 200, 221, 21));
        output_edit = new QLineEdit(centralWidget);
        output_edit->setObjectName(QStringLiteral("output_edit"));
        output_edit->setGeometry(QRect(30, 260, 221, 16));
        media_file = new QToolButton(centralWidget);
        media_file->setObjectName(QStringLiteral("media_file"));
        media_file->setGeometry(QRect(480, 140, 41, 31));
        input_file = new QToolButton(centralWidget);
        input_file->setObjectName(QStringLiteral("input_file"));
        input_file->setGeometry(QRect(480, 200, 41, 31));
        output_file = new QToolButton(centralWidget);
        output_file->setObjectName(QStringLiteral("output_file"));
        output_file->setGeometry(QRect(480, 270, 41, 31));
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
        label->setText(QApplication::translate("MainWindow", "Media file:", 0));
        label_2->setText(QApplication::translate("MainWindow", "Input file:", 0));
        label_3->setText(QApplication::translate("MainWindow", "Output file:", 0));
        media_file->setText(QApplication::translate("MainWindow", "...", 0));
        input_file->setText(QApplication::translate("MainWindow", "...", 0));
        output_file->setText(QApplication::translate("MainWindow", "...", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
