#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    get_slaves_name_and_update_slaves_combobox();

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update_master_status_label()));
    timer->start(1);
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

void MainWindow::update_master_status_label()
{
    switch (ec_slave[0].state)
    {
        case EC_STATE_NONE:
          ui->master_status_lbl->setText("NONE");
          break;
        case EC_STATE_INIT:
          ui->master_status_lbl->setText("INIT");
          break;
        case EC_STATE_PRE_OP:
          ui->master_status_lbl->setText("PRE_OP");
          break;
        case EC_STATE_BOOT:
          ui->master_status_lbl->setText("BOOT");
          break;
        case EC_STATE_SAFE_OP:
          ui->master_status_lbl->setText("SAFE_OP");
          break;
        case EC_STATE_OPERATIONAL:
          ui->master_status_lbl->setText("OPERATIONAL");
          break;
        case EC_STATE_ACK:
          ui->master_status_lbl->setText("EC_STATE_ACK");
          break;
        case EC_STATE_PRE_OP + EC_STATE_ERROR:
          ui->master_status_lbl->setText("PRE_OP - ERROR");
          break;
        case EC_STATE_SAFE_OP + EC_STATE_ERROR:
          ui->master_status_lbl->setText("SAFE_OP - ERROR");
          break;
        case EC_STATE_OPERATIONAL + EC_STATE_ERROR:
          ui->master_status_lbl->setText("OPERATIONAL - ERROR");
          break;
    }
}

void MainWindow::get_slaves_name_and_update_slaves_combobox()
{
    for (int i = 0; i < ec_slavecount; i++)
    {
        QString slave_name = ec_slave[i+1].name;
        ui->slave_to_set_status_combo->addItem(slave_name);
    }
}

