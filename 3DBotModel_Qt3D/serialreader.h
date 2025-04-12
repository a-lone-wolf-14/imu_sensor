#ifndef SERIALREADER_H
#define SERIALREADER_H

#include <QObject>
#include <QSerialPort>

class SerialReader : public QObject {
    Q_OBJECT

public:
    explicit SerialReader(QObject *parent = nullptr);
    void startReading(const QString &portName);

signals:
    void newIMUData(float yaw, float pitch, float roll);

private slots:
    void readData();

private:
    QSerialPort *serial;
};

#endif // SERIALREADER_H
