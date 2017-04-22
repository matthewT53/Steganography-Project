#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // events
    connect(ui->close, SIGNAL(clicked()), this, SLOT( closeWindow() ));
    connect(ui->action, SIGNAL(clicked()), this, SLOT( openPasswordWindow() ));


    connect(ui->media_file, SIGNAL(clicked()), this, SLOT( openFileBrowseWindow() ));
    connect(ui->input_file, SIGNAL(clicked()), this, SLOT( openFileBrowseWindow() ));
    connect(ui->output_file, SIGNAL(clicked()), this, SLOT( openFileBrowseWindow() ));


    // set up the file browser and the password form
    this->passwordWindow = new PasswordForm(this);

    // leave the radio button set to hdie on default
    this->hideFile = true;
    ui->radio_hide->click();
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

}

void MainWindow::openPasswordWindow()
{
    this->passwordWindow->setModal(true);
    this->passwordWindow->show();
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
       this->media_file_path = filename;
       ui->media_edit->setText(filename);
   }

   else if (button_text == "input_file"){
       this->input_file_path = filename;
       ui->input_edit->setText(filename);
   }

   else if (button_text == "output_file"){
       this->output_file_path = filename;
       ui->output_edit->setText(filename);
   }
}
