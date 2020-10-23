#include "serialportThread.h"


SerialportThread::SerialportThread(QString &serialName,int baudrate)
{
    m_serialPort =new QSerialPort;
    m_serialPort->setPortName(serialName);
    m_serialPort->setBaudRate(baudrate,QSerialPort::AllDirections);//波特率 双工
    m_serialPort->setDataBits(QSerialPort::Data8);
    m_serialPort->setParity(QSerialPort::NoParity);
    m_serialPort->setFlowControl(QSerialPort::NoFlowControl);
    m_serialPort->setStopBits(QSerialPort::OneStop);

    if  (m_serialPort->open(QIODevice::ReadWrite)){
        readable =true;
    }else{
        emit onEvent("can not open "+serialName);
    }
}

SerialportThread::~SerialportThread()
{
    stop();
    delete m_serialPort;
}



void SerialportThread:: run(){

    if (!m_serialPort){
        return ;
    }

    if (!readable){
        return;
    }

    while (m_serialPort->isOpen()) {

        QByteArray byteArray ;
        byteArray =m_serialPort->readLine();
        if (byteArray.isEmpty()){
            sleep(10);
        }else{
            emit receivedData(byteArray.data());
        }

    }

}


void SerialportThread::stop()
{
    if  (m_serialPort->isOpen()){
        m_serialPort->clear();
        m_serialPort->close();
    }
}

void SerialportThread::sendData(QString &data)
{
    if(m_serialPort &&m_serialPort->isOpen()){
        QByteArray bytedate =data.toLatin1();
        m_serialPort->write(bytedate.data());
    }
}


