#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QDir>
#include "passwordform.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    PasswordForm *passwordWindow;

    bool hideFile; // determines whether we hide or reveal a file

    QString media_file_path; // file paths
    QString input_file_path;
    QString output_file_path;

    QString password;

private slots:
    void closeWindow();
    void performAction();
    void openPasswordWindow();
    void openFileBrowseWindow();
};

#endif // MAINWINDOW_H
