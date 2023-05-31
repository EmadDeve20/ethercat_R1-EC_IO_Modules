#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

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
    QTimer *timer;

    void change_slave_status(int &slave_idx, std::string &status);

private slots:
    void on_set_status_btn_clicked();

private:
    Ui::MainWindow *ui;
    int work_count_ethernet;
};
#endif // MAINWINDOW_H
