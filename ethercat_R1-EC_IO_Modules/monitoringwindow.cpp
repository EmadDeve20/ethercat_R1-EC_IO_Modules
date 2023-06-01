#include "monitoringwindow.h"
#include "ui_monitoringwindow.h"

MonitoringWindow::MonitoringWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MonitoringWindow)
{
    ui->setupUi(this);

    ui->tableWidget->setRowCount(ec_slavecount);

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

        //TODO: Fix it To Show Status
//        for (auto c = 0; ui->tableWidget->columnCount(); c++)
//        {
//            switch (ec_slave[r+1].state)
//            {
//              case EC_STATE_NONE:
//                ui->tableWidget->setItem(r, c, new QTableWidgetItem(tr("NONE")));
//                break;
//              case EC_STATE_INIT:
//                ui->tableWidget->setItem(r, c, new QTableWidgetItem(tr("INIT")));
//                break;
//              case EC_STATE_PRE_OP:
//                ui->tableWidget->setItem(r, c, new QTableWidgetItem(tr("PRE_OP")));
//                break;
//              case EC_STATE_BOOT:
//                ui->tableWidget->setItem(r, c, new QTableWidgetItem(tr("BOOT")));
//                break;
//              case EC_STATE_SAFE_OP:
//                ui->tableWidget->setItem(r, c, new QTableWidgetItem(tr("SAFE_OP")));
//                break;
//              case EC_STATE_OPERATIONAL:
//                ui->tableWidget->setItem(r, c, new QTableWidgetItem(tr("OP")));
//                break;
//              case EC_STATE_ACK:
//                ui->tableWidget->setItem(r, c, new QTableWidgetItem(tr("ACK")));
//                break;
//              case EC_STATE_PRE_OP + EC_STATE_ERROR:
//                ui->tableWidget->setItem(r, c, new QTableWidgetItem(tr("PRE_OP-ERR")));
//                break;
//              case EC_STATE_SAFE_OP + EC_STATE_ERROR:
//                ui->tableWidget->setItem(r, c, new QTableWidgetItem(tr("SAFE_OP-ERR")));
//                break;
//              case EC_STATE_OPERATIONAL + EC_STATE_ERROR:
//                ui->tableWidget->setItem(r, c, new QTableWidgetItem(tr("OP-ERR")));
//                break;
//            }
//        }
    }
}
