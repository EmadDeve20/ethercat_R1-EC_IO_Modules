#ifndef MONITORINGWINDOW_H
#define MONITORINGWINDOW_H

#include <QMainWindow>
#include <QTimer>

// soem
#include <ethercat.h>

namespace Ui {
class MonitoringWindow;
}

class MonitoringWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MonitoringWindow(QWidget *parent = nullptr);
    ~MonitoringWindow();
    QTimer *timer;

private slots:
    void update_status_table();

private:
    Ui::MonitoringWindow *ui;
};

#endif // MONITORINGWINDOW_H
