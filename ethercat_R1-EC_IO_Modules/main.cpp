#include "mainwindow.h"

#include <QApplication>
#include <QInputDialog>
#include <QMessageBox>
#include <QtNetwork/QNetworkInterface>

//SOEM
#include "ethercat.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QList<QNetworkInterface> all_ethernet_interface = QNetworkInterface::allInterfaces();

    QStringList defualt_ethernet_interfaces;

    foreach(QNetworkInterface ethernet_interface, all_ethernet_interface)
    {
        if (ethernet_interface.type() == QNetworkInterface::Ethernet)
        {
            defualt_ethernet_interfaces << ethernet_interface.humanReadableName();
        }
    }


    bool ifname_is_ok;
    QString ifname = QInputDialog::getItem(0, "Select Your Ethernet Interface", "ifname",
                                           defualt_ethernet_interfaces, 0, true, &ifname_is_ok);

    if ((ifname_is_ok && ec_init(ifname.toStdString().c_str())) && (ec_config_init(FALSE)) > 1)
    {
        MainWindow w;
        w.show();
        return a.exec();
    }
    else if (ifname_is_ok && ifname.length() == 0)
    {
        QMessageBox messageBox;
        messageBox.critical(0,"Error","Please set your ifname");
        messageBox.setFixedSize(500,200);
    }
    else if(ifname_is_ok && ifname.length() > 0)
    {   QMessageBox messageBox;
        messageBox.critical(0,"Error","Can not connect with your ifname! Try run  it with sudo");
        messageBox.setFixedSize(500,200);

        return 1;
    }

}
