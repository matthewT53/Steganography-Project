#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "src/headers/steg.h"
#include "src/headers/de_steg.h"

#include <QDebug>

#define MAX_LEN 500

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
    this->hide_file_ = true;
    ui->radio_hide->click();

    this->password_set_ = false;
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
    // get the password
    QString password = "";
    if (password_set_){
        password = ui->password->text();
    }

    if (hide_file_){

    }

    else{

    }
}

void MainWindow::open_file_browse_window()
{
    QString filename = QFileDialog::getOpenFileName(this,
                                         "Select a file",
                                         "",
                                         "All Files (*.*);;BMP images (.bmp);;PNG images (.png);;");
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

    if (radioBut->text() == "Hide"){
        this->hide_file_ = true;
        ui->io_label->setText("Input file:");
        ui->protect_check->setText("Protect with encryption.");
        ui->action->setText("Hide");
    }

    else{
        this->hide_file_ = false;
        ui->io_label->setText("Output file:");
        ui->protect_check->setText("File is encrypted.");
        ui->action->setText("Reveal");
    }
}
