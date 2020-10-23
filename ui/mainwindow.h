#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QSerialPortInfo>
#include "utils/serialportThread.h"
#include "obsdialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QStringList getPortNameList();
    void ReadObs(const QStringList &files);


private slots:
    void on_actionserial_triggered();
    void dataReceive();
    void on_actionAnalysis_triggered();

private:
    Ui::MainWindow *ui;
    SerialportThread *m_serialPortThread;
    QStringList m_portNameList;
    ObsDialog *obsDialog;


};
#endif // MAINWINDOW_H
