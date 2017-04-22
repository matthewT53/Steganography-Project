#ifndef FILEBROWSER_H
#define FILEBROWSER_H

#include <QDialog>
#include <QString>
#include <QTreeWidgetItem>

namespace Ui {
class FileBrowser;
}

class FileBrowser : public QDialog
{
    Q_OBJECT

public:
    explicit FileBrowser(QWidget *parent = 0);
    ~FileBrowser();

private:
    Ui::FileBrowser *ui;

    void addRoot(QString filename);

    void addChild(QTreeWidgetItem root, QString filename);
};

#endif // FILEBROWSER_H
