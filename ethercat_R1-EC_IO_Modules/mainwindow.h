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
    void update_master_status_label();

private:
    Ui::MainWindow *ui;
    int work_count_ethernet;
    void get_slaves_name_and_update_slaves_combobox();
};
#endif // MAINWINDOW_H
