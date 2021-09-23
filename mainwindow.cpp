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
    askForUserPassword();
    installBinary();
    installIcon();
    installDesktopFile();
    updateDesktopDatabase();
}

void MainWindow::askForUserPassword()
{
    PasswordDialog passwordDialog(userPassword, this);
    passwordDialog.exec();
}

void MainWindow::installDesktopFile()
{
    QFile desktopFile(":/Transliterator.desktop");

    desktopFile.copy("/tmp/transliterator.desktop");

    QString installPath = "/usr/share/applications/transliterator.desktop";

    QString command = "/bin/sh -c \"echo \"" + userPassword + "\" | sudo -S cp /tmp/transliterator.desktop " + installPath + "\"";
    QProcess::execute(command);

    QProcess::execute("rm /tmp/transliterator.desktop");
}

void MainWindow::updateDesktopDatabase()
{
    QString command = "/bin/sh -c \"echo \"" + userPassword + "\" | sudo -S update-desktop-database ~/.local/share/applications";
    QProcess::execute(command);
}

void MainWindow::installIcon()
{
    QFile image(":/Transliterator.png");

    image.copy("/tmp/transliterator.png");

    QString installPath = "/usr/share/icons/hicolor/32x32/apps/transliterator.png";

    QString command = "/bin/sh -c \"echo \"" + userPassword + "\" | sudo -S cp /tmp/transliterator.png " + installPath + "\"";
    QProcess::execute(command);

    QProcess::execute("rm /tmp/transliterator.png");
}

void MainWindow::installBinary()
{
    QFile binary(":/Transliterator");
    binary.copy("/tmp/transliterator");

    QString installPath = "/usr/bin/transliterator";

    QString command = "/bin/sh -c \"echo \"" + userPassword + "\" | sudo -S cp /tmp/transliterator " + installPath + "\"";
    QProcess::execute(command);

    QProcess::execute("rm /tmp/transliterator");
}
