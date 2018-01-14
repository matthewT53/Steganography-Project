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

    bool hide_file_; // determines whether we hide or reveal a file
    bool password_set_; // indicates whetehr the password has been set

private slots:
    void close_window();
    void perform_action();
    void open_password_window();
    void open_file_browse_window();
    void handle_radio_change();
};

#endif // MAINWINDOW_H
