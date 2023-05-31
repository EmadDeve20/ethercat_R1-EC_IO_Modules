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
                                            "Date of Birth:", QLineEdit::Normal,
                                            "", &ifname_is_ok);

    if (ifname_is_ok && ec_init(ifname.toStdString().c_str()))
    {
        MainWindow w;
        w.show();
        return a.exec();
    }
    else
    {   QMessageBox messageBox;
        messageBox.critical(0,"Error","Can not connect with your ifname! Try with sudo");
        messageBox.setFixedSize(500,200);

        return 1;
    }



}
