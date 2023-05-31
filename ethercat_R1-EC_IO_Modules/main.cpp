#include "mainwindow.h"

#include <QApplication>
#include <QInputDialog>
#include <QMessageBox>

//SOEM
#include "ethercat.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    bool ifname_is_ok;
       // Ask for birth date as a string.
    QString ifname = QInputDialog::getText(0, "Input dialog",
                                            "set ifname:", QLineEdit::Normal,
                                            "", &ifname_is_ok);

    if ((ifname_is_ok && ec_init(ifname.toStdString().c_str())) && (ec_config_init(FALSE)) > 1)
    {
        MainWindow w;
        w.show();
        return a.exec();
    }
    else if (!ifname_is_ok)
    {
        QMessageBox messageBox;
        messageBox.critical(0,"Error","Please set your ifname");
        messageBox.setFixedSize(500,200);
    }
    else
    {   QMessageBox messageBox;
        messageBox.critical(0,"Error","Can not connect with your ifname! Try with sudo");
        messageBox.setFixedSize(500,200);

        return 1;
    }



}
