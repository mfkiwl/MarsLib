#ifndef SERIALPORT_H
#define SERIALPORT_H

#include <QSerialPort>
#include <QSerialPortInfo>
#include <QThread>

class SerialportThread: public QThread
{
    Q_OBJECT
public:
    SerialportThread(QString &serialPort,int baudrate);

    ~SerialportThread();

signals:

    void onEvent(QString qEvent);
    void receivedData(char* charData);

protected:

    void run() ;

public slots:

    void stop();
    void sendData(QString &data);

private:
    bool readable =false;
    QSerialPort *m_serialPort;
    QStringList m_portNameList;

};

#endif // SERIALPORT_H
