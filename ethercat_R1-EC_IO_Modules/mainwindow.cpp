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
        return;
   }

   if (status == "Pre-Operational")
   {
        ec_slave[slave_idx].state = EC_STATE_PRE_OP;
        return;
   }

   if (status == "Safe-Operational")
   {
        ec_slave[slave_idx].state = EC_STATE_SAFE_OP;
        return;
   }

   if (status == "Operational")
   {
        ec_slave[slave_idx].state = EC_STATE_OPERATIONAL;
        return;
   }


}
