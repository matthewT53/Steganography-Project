#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "filebrowser.h"
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
    FileBrowser *fileBrowserWindow;

    bool hideFile; // determines whether we hide or reveal a file

private slots:
    void closeWindow();
    void performAction();
    void openPasswordWindow();
    void openFileBrowseWindow();
};

#endif // MAINWINDOW_H
