#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

//soem
#include <ethercat.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void change_slave_status(int &slave_idx, std::string &status);

private:
    Ui::MainWindow *ui;
    int work_count_ethernet;
};
#endif // MAINWINDOW_H
