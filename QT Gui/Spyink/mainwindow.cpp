#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "src/headers/steg.h"
#include "src/headers/deSteg.h"

#include <QDebug>

#define MAX_LEN 500

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // events
    connect(ui->close, SIGNAL(clicked()), this, SLOT( closeWindow() ));
    connect(ui->action, SIGNAL(clicked()), this, SLOT( performAction() ));


    connect(ui->media_file, SIGNAL(clicked()), this, SLOT( openFileBrowseWindow() ));
    connect(ui->input_file, SIGNAL(clicked()), this, SLOT( openFileBrowseWindow() ));
    connect(ui->output_file, SIGNAL(clicked()), this, SLOT( openFileBrowseWindow() ));


    // set up the file browser and the password form
    this->passwordWindow = new PasswordForm(this);

    // leave the radio button set to hide on default
    connect(ui->radio_hide, SIGNAL(clicked()), this, SLOT( handleRadioChange() ));
    connect(ui->radio_reveal, SIGNAL(clicked()), this, SLOT( handleRadioChange() ));
    this->hideFile = true;
    ui->radio_hide->click();

    this->passwordSet = false;
}

MainWindow::~MainWindow()
{
    delete ui;
}

// function that handles the event when the close button is pressed
void MainWindow::closeWindow()
{
    this->close();
}

// hides or reveals a file
void MainWindow::performAction()
{
    char image_file[MAX_LEN] = {0}, input_file[MAX_LEN] = {0}, output_file[MAX_LEN] = {0}, password[MAX_LEN] = {0};

    if (this->passwordSet == true){
        // convert all the files and password to char * from QString
        QByteArray strBytes = ui->media_edit->text().toLocal8Bit();
        strncpy(image_file, strBytes.data(), MAX_LEN);

        strBytes = ui->input_edit->text().toLocal8Bit();
        strncpy(input_file, strBytes.data(), MAX_LEN);

        strBytes = ui->output_edit->text().toLocal8Bit();
        strncpy(output_file, strBytes.data(), MAX_LEN);

        strBytes = this->passwordWindow->getPassword().toLocal8Bit();
        strncpy(password, strBytes.data(), MAX_LEN);

        if (this->hideFile == true){
            // qDebug() << "In here" << endl;
            // qDebug() << image_file << endl;
            // qDebug() << input_file << endl;
            // qDebug() << output_file << endl;
            // qDebug() << password << endl;
            Hide hideInFile(image_file, input_file, output_file, password);
            hideInFile.beginHide();
        }

        else{
            Reveal hiddenFile(image_file, output_file, password);
            hiddenFile.reveal();
        }

        // refresh the window
        this->passwordSet = false;
        this->media_file_path = "";
        this->input_file_path = "";
        this->output_file_path = "";
        this->passwordWindow->setPassword("");

        ui->input_edit->setText("");
        ui->output_edit->setText("");
        ui->media_edit->setText("");
    }

    else{
        openPasswordWindow();
    }
}

void MainWindow::openPasswordWindow()
{
    this->passwordWindow->setModal(true);
    this->passwordWindow->show();
    this->passwordSet = true;
}

void MainWindow::openFileBrowseWindow()
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

   else if (button_text == "input_file"){
       ui->input_edit->setText(filename);
   }

   else if (button_text == "output_file"){
       ui->output_edit->setText(filename);
   }
}

void MainWindow::handleRadioChange()
{
    QRadioButton *radioBut = (QRadioButton *) QObject::sender();

    this->passwordSet = false;

    if (radioBut->text() == "Hide"){
        this->hideFile = true;
        ui->input_edit->setEnabled(true);
        ui->input_file->setEnabled(true);
        ui->action->setText("Hide");
    }

    else{
        this->hideFile = false;
        ui->input_edit->setEnabled(false);
        ui->input_file->setEnabled(false);
        ui->action->setText("Reveal");
    }
}
