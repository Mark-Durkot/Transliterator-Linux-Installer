#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>
#include <QFile>
#include <QDir>

#include <QMessageBox>

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
    void installLibrary();
    void makeLibraryDirectory();

    void installFile(const QString &filename);
    void linkFile(const QString &filename, const QString &alias);

    void installBinary();
    void installIcon();
    void installDesktopFile();

    void linkDesktopFile();
    void linkIcon();
    void linkBinary();

private:
    Ui::MainWindow *ui;

    QString transliteratorLibraryPath = "/usr/lib/transliterator";

    QString userPassword;

    QProcess process;
};
#endif // MAINWINDOW_H
