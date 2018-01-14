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
    // connect(ui->close, SIGNAL(clicked()), this, SLOT( close_window() ));
    connect(ui->action, SIGNAL(clicked()), this, SLOT( perform_action() ));


    connect(ui->media_file, SIGNAL(clicked()), this, SLOT( open_file_browse_window() ));
    connect(ui->io_file, SIGNAL(clicked(bool)), this, SLOT( open_file_browse_window()));

    // set up the file browser and the password form
    this->passwordWindow = new PasswordForm(this);

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
    char image_file[MAX_LEN] = {0}, io_file[MAX_LEN] = {0}, password[MAX_LEN] = {0};

    if (this->password_set_ == true){
        // convert all the files and password to char * from QString
        QByteArray strBytes = ui->media_edit->text().toLocal8Bit();
        strncpy(image_file, strBytes.data(), MAX_LEN);

        strBytes = ui->io_edit->text().toLocal8Bit();
        strncpy(io_file, strBytes.data(), MAX_LEN);

        strBytes = this->passwordWindow->getPassword().toLocal8Bit();
        strncpy(password, strBytes.data(), MAX_LEN);

        if (this->hide_file_ == true){
            Hide h(image_file, io_file, password);
            h.begin_hide();
            //ui->progressBar->setValue(100); // will actually make this depend on something later
        }

        else{
            Reveal r(image_file, io_file, password);
            r.begin_reveal();
            //ui->progressBar->setValue(100);
        }

        // refresh the window
        this->password_set_ = false;
        this->passwordWindow->setPassword("");

        ui->io_edit->setText("");
        ui->media_edit->setText("");
    }

    else{
        open_password_window();
    }
}

void MainWindow::open_password_window()
{
    this->passwordWindow->setModal(true);
    this->passwordWindow->show();
    this->password_set_ = true;
}

void MainWindow::open_file_browse_window()
{
    QString filename = QFileDialog::getOpenFileName(this,
                                         "Select a file",
                                         "",
                                         "All Files (*.*);;BMP images (.bmp);;PNG images (.png);;");
    QToolButton *button = (QToolButton *)QObject::sender();
    QString button_text = button->objectName();

    // qDebug() << button_text << endl;

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
        ui->action->setText("Hide");
    }

    else{
        this->hide_file_ = false;
        ui->io_label->setText("Output file:");
        ui->action->setText("Reveal");
    }
}
