#include "monitoringwindow.h"
#include "ui_monitoringwindow.h"

MonitoringWindow::MonitoringWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MonitoringWindow)
{
    ui->setupUi(this);

    ui->tableWidget->setRowCount(ec_slavecount);

//    for (auto r = 0; r < ui->tableWidget->rowCount(); r++)
//    {
//        ui->tableWidget->setItem(r, 0, new QTableWidgetItem(tr(ec_slave[r+1].name)));

//        //TODO: Fix it To Show Status
//        for (auto c = 1; ui->tableWidget->columnCount(); c++)
//        {
//            ui->tableWidget->setItem(r, c, new QTableWidgetItem(tr("NONE")));
//        }
//    }

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update_status_table()));
    timer->start(1);

}

MonitoringWindow::~MonitoringWindow()
{
    delete ui;
}

void MonitoringWindow::update_status_table()
{
    for (auto r = 0; r < ui->tableWidget->rowCount(); r++)
    {
        ui->tableWidget->setItem(r, 0, new QTableWidgetItem(tr(ec_slave[r+1].name)));
        std::string status;

            switch (ec_slave[r+1].state)
            {
              case EC_STATE_NONE:
                status = "NONE";
                break;
              case EC_STATE_INIT:
                status = "INIT";
                break;
              case EC_STATE_PRE_OP:
                status = "PRE_OP";
                break;
              case EC_STATE_BOOT:
                status = "BOOT";
                break;
              case EC_STATE_SAFE_OP:
                status = "SAFE_OP";
                break;
              case EC_STATE_OPERATIONAL:
                status = "OP";
                break;
              case EC_STATE_ACK:
                status = "ACK";
                break;
              case EC_STATE_PRE_OP + EC_STATE_ERROR:
                status = "PRE_OP-ERR";
                break;
              case EC_STATE_SAFE_OP + EC_STATE_ERROR:
                status = "SAFE_OP-ERR";
                break;
              case EC_STATE_OPERATIONAL + EC_STATE_ERROR:
                status = "OP-ERR";
                break;
            }

            ui->tableWidget->setItem(r, 1, new QTableWidgetItem(tr(status.c_str())));
     }
}
