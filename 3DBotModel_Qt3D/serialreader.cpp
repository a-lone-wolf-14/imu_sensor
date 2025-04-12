#include "serialreader.h"
#include <QDebug>

SerialReader::SerialReader(QObject *parent) : QObject(parent) {
    serial = new QSerialPort(this);
    connect(serial, &QSerialPort::readyRead, this, &SerialReader::readData);
}

void SerialReader::startReading(const QString &portName) {
    serial->setPortName(portName);
    serial->setBaudRate(QSerialPort::Baud115200);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);

    if (serial->open(QIODevice::ReadOnly)) {
        qDebug() << "Connected to" << portName;
    } else {
        qDebug() << "Failed to open port!";
    }
}

void SerialReader::readData() {
    while (serial->canReadLine()) {
        QByteArray line = serial->readLine().trimmed();
        QList<QByteArray> data = line.split(',');

        if (data.size() == 3) {
            float yaw = data[0].toFloat();
            float pitch = data[1].toFloat();
            float roll = data[2].toFloat();

            emit newIMUData(yaw, pitch, roll);
        }
    }
}
