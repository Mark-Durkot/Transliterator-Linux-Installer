#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_install_clicked()
{
    process.start("echo **** | sudo -S -s");
    process.waitForFinished();

    installLibrary();
}

void MainWindow::installLibrary()
{
    makeLibraryDirectory();

//    installFile("transliterator");
//    installFile("transliterator.desktop");
//    installFile("transliterator.png");

//    linkFile("/usr/lib/transliterator/transliterator", "/usr/bin/transliterator");
//    linkFile("/usr/lib/trasnliterator/transliterator.desktop", "/usr/share/applications/transliterator.desktop");
//    linkFile("/usr/bin/transliterator/transliterator.png", "/usr/share/incons/hicolor/256x256/apps/transliterator.png");
}

void MainWindow::makeLibraryDirectory()
{
    QString usrLibDirectoryPath = "/usr/lib/transliterator/";

    QDir usrLibDirectory("/usr/lib/transliterator");

    process.start("echo **** | sudo -S mkdir " + transliteratorLibraryPath);

//    if (usrLibDirectory.exists())
//    {
//        throw "The application seems to be already installed\nDirectory /usr/lib/transliterator/ already exists";
//    }

//    if (!usrLibDirectory.mkdir(usrLibDirectoryPath))
//    {
//        throw "Failed to install the libraries";
//    }
}

void MainWindow::installFile(const QString &filename)
{
    QFile file(filename);
    file.copy("/usr/lib/transliterator/" + filename);
}

void MainWindow::linkFile(const QString &filename, const QString &aliasname)
{
    QFile::link(filename, aliasname);
}

void MainWindow::installDesktopFile()
{
    QFile desktopFile("Transliterator.desktop");
    desktopFile.copy("/usr/share/applications/Transliterator.desktop");
}

void MainWindow::installIcon()
{
    QFile image("/Users/md/Desktop/Transliterator_logo.png");

    image.copy(transliteratorLibraryPath + "Transliterator_logo.png");
    image.copy("/usr/share/icons/hicolor/256x256/apps/transliterator.png");
}

void MainWindow::installBinary()
{
    QFile binary("Transliterator");
    binary.copy("/usr/bin/Transliterator");
}
