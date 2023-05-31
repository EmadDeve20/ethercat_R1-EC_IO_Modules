#include "mainwindow.h"
#include "./ui_mainwindow.h"

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

void MainWindow::change_slave_status(int &slave_idx, std::string &status)
{
   if (status == "INIT")
   {
        ec_slave[slave_idx].state = EC_STATE_INIT;
        ec_writestate(slave_idx);
        return;
   }

   if (status == "Pre-Operational")
   {
        ec_slave[slave_idx].state = EC_STATE_PRE_OP;
        ec_writestate(slave_idx);
        return;
   }

   if (status == "Safe-Operational")
   {
        ec_slave[slave_idx].state = EC_STATE_SAFE_OP;
        ec_writestate(slave_idx);
        return;
   }

   if (status == "Operational")
   {
        ec_slave[slave_idx].state = EC_STATE_OPERATIONAL;
        ec_writestate(slave_idx);
        return;
   }
}

void MainWindow::on_set_status_btn_clicked()
{
    int slave_idx = ui->slave_to_set_status_combo->currentIndex();
    std::string status =  ui->status_combo->currentText().toStdString();

    change_slave_status(slave_idx, status);
}

