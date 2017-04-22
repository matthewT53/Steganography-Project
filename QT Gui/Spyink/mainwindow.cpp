#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    this->fileBrowserWindow = new FileBrowser(this);

    // leave the radio button set to hdie on default
    this->hideFile = true;
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
    this->fileBrowserWindow->setModal(true);
    this->fileBrowserWindow->show();
}
