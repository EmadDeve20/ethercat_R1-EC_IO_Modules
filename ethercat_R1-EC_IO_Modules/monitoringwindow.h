#ifndef MONITORINGWINDOW_H
#define MONITORINGWINDOW_H

#include <QMainWindow>

namespace Ui {
class MonitoringWindow;
}

class MonitoringWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MonitoringWindow(QWidget *parent = nullptr);
    ~MonitoringWindow();

private:
    Ui::MonitoringWindow *ui;
};

#endif // MONITORINGWINDOW_H
