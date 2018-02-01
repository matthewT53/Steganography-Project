#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "src/headers/steg.h"
#include "src/headers/de_steg.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // events
    connect(ui->action, SIGNAL(clicked()), this, SLOT( perform_action() ));

    connect(ui->media_file, SIGNAL(clicked()), this, SLOT( open_file_browse_window() ));
    connect(ui->io_file, SIGNAL(clicked(bool)), this, SLOT( open_file_browse_window()));

    // leave the radio button set to hide on default
    connect(ui->radio_hide, SIGNAL(clicked()), this, SLOT( handle_radio_change() ));
    connect(ui->radio_reveal, SIGNAL(clicked()), this, SLOT( handle_radio_change() ));
    connect(ui->protect_check, SIGNAL(clicked(bool)), this, SLOT( handle_check_change() ));

    this->hide_file_ = true;
    this->password_set_ = false;

    ui->radio_hide->click();
    ui->password->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// function that handles the event when the close button is pressed
void MainWindow::close_window()
{
    this->close();
}

// hides or reveals a file
void MainWindow::perform_action()
{
    std::string media_filename = ui->media_edit->text().toLocal8Bit().constData();
    std::string io_filename = ui->io_edit->text().toLocal8Bit().constData();
    std::string password = "";

    // get the password
    if (password_set_){
        password = ui->password->text().toLocal8Bit().constData();
    }

    if (hide_file_){
        Hide h(media_filename, io_filename, password);
        h.begin_hide(password_set_);
    }

    else{
        Reveal r(media_filename, io_filename, password);
        r.begin_reveal(password_set_);
    }
}

void MainWindow::handle_check_change()
{
    bool is_checked = ui->protect_check->isChecked();

    if (is_checked){
        ui->password->setEnabled(true);
    }

    else{
        ui->password->setEnabled(false);
    }
}

void MainWindow::open_file_browse_window()
{
    QString filename = QFileDialog::getOpenFileName(this,
                                         "Select a file",
                                         "",
                                         "All Files (*.*);;BMP images (*.bmp);;PNG images (*.png);;");
    QToolButton *button = (QToolButton *)QObject::sender();
    QString button_text = button->objectName();

   // store the filename and set the line edit appropriately
   if (button_text == "media_file"){
       ui->media_edit->setText(filename);
   }

   else if (button_text == "io_file"){
       ui->io_edit->setText(filename);
   }
}

void MainWindow::handle_radio_change()
{
    QRadioButton *radioBut = (QRadioButton *) QObject::sender();

    this->password_set_ = false;

    // clear the input fields
    ui->io_edit->clear();
    ui->media_edit->clear();
    ui->password->clear();

    if (radioBut->text() == "Hide"){
        this->hide_file_ = true;
        ui->io_label->setText("Input file:");
        ui->protect_check->setText("Protect with encryption.");
        ui->action->setText("Hide");
    }

    else{
        this->hide_file_ = false;
        ui->io_label->setText("Output file:");
        ui->protect_check->setText("Decrypt hidden file.");
        ui->action->setText("Reveal");
    }
}
