#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "passworddialog.h"

#include <QMainWindow>
#include <QProcess>
#include <QFile>
#include <QDir>

#include <QMessageBox>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_install_clicked();

private:
    void askForUserPassword();

    void installBinary();
    void installIcon();
    void installDesktopFile();

    void updateDesktopDatabase();

private:
    Ui::MainWindow *ui;
    QString userPassword;
};
#endif // MAINWINDOW_H
