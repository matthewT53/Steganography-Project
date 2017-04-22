#include "filebrowser.h"
#include "ui_filebrowser.h"

FileBrowser::FileBrowser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FileBrowser)
{
    ui->setupUi(this);
    ui->fileTreeWidget->setColumnCount(1);

    // traverse the
}

FileBrowser::~FileBrowser()
{
    delete ui;
}

void FileBrowser::addRoot(QString filename)
{
    QTreeWidgetItem rootItem = new QTreeWidgetItem(ui->fileTreeWidget);
    rootItem.setText(0, filename);
    ui->fileTreeWidget->addTopLevelItem(rootItem);
}

void FileBrowser::addChild(QTreeWidgetItem root, QString filename)
{
    QTreeWidgetItem newItem = new QTreeWidgetItem();
    newItem.setText(0, filename);
    root.addChild(newItem);
}
