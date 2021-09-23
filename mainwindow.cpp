#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    process.open(QIODevice::WriteOnly);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_install_clicked()
{
    installLibrary();
}

void MainWindow::installLibrary()
{
    installBinary();
    installDesktopFile();
    installIcon();
}

void MainWindow::makeLibraryDirectory()
{

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

    desktopFile.copy("tmp/transliterator.desktop");

    process.start("sudo cp /tmp/transliterator.png /usr/share/applications/transliterator.desktop");
    process.waitForReadyRead();
    process.write("****");
    process.waitForFinished();

    process.start("rm /tmp/transliterator.desktop");
    process.waitForFinished();
}

void MainWindow::installIcon()
{
    QFile image(":/Transliterator.png");

    image.copy("/tmp/transliterator.png");

    process.start("sudo cp /tmp/transliterator.png /usr/share/icons/hicolor/32x32/apps/transliterator.png");

    process.waitForReadyRead();
    process.write("****");
    process.waitForFinished();

    process.start("rm /tmp/transliterator.png");
    process.waitForFinished();
}

void MainWindow::installBinary()
{
    QFile binary(":/Transliterator");
    binary.copy("/tmp/transliterator");

    process.start("sudo cp /tmp/transliterator /usr/bin/transliterator");
    process.waitForReadyRead();
    process.write("****");
    process.waitForFinished();

    process.start("rm /tmp/transliterator");
    process.waitForFinished();
}
