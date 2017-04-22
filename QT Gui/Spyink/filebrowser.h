#ifndef FILEBROWSER_H
#define FILEBROWSER_H

#include <QDialog>

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
};

#endif // FILEBROWSER_H
