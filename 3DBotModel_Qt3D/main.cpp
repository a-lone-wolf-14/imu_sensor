#include "botmodel_qt3d.h"
#include <QGuiApplication>
#include <Qt3DExtras/Qt3DWindow>
#include <Qt3DCore/QEntity>
#include <Qt3DRender/QCamera>
#include <QtSerialPort/QSerialPort>
#include <Qt3DExtras/QForwardRenderer>
#include <QDebug>

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    // Create 3D Window
    Qt3DExtras::Qt3DWindow *view = new Qt3DExtras::Qt3DWindow();
    view->defaultFrameGraph()->setClearColor(QColor(50, 50, 50));

    // Create root entity
    Qt3DCore::QEntity *rootEntity = new Qt3DCore::QEntity();
    BotModel_Qt3D botModel(rootEntity);
    view->setRootEntity(rootEntity);

    // Setup Camera
    Qt3DRender::QCamera *camera = view->camera();
    camera->setPosition(QVector3D(0, 0, 10));
    camera->setViewCenter(QVector3D(0, 0, 0));

    // Setup Serial Port
    QSerialPort serial;
    serial.setPortName("COM10");
    serial.setBaudRate(QSerialPort::Baud115200);
    serial.setDataBits(QSerialPort::Data8);
    serial.setParity(QSerialPort::NoParity);
    serial.setStopBits(QSerialPort::OneStop);
    serial.setFlowControl(QSerialPort::NoFlowControl);

    if (serial.open(QIODevice::ReadOnly)) {
        qDebug() << "Serial port opened successfully!";
    } else {
        qDebug() << "Error opening serial port: " << serial.errorString();
    }

    // Read Serial Data and Update Rotation
    QObject::connect(&serial, &QSerialPort::readyRead, [&]() {
        while (serial.canReadLine()) {
            QByteArray line = serial.readLine();
            QString data = QString::fromUtf8(line).trimmed();  // Ensure `data` is declared
            qDebug() << "Received: " << data;

            // Split the data based on commas
            QStringList values = data.split(",");
            if (values.size() >= 3) {  // Ensure at least 3 values exist
                float yaw = values[0].toFloat();
                float pitch = values[1].toFloat();
                float roll = values[2].toFloat();

                qDebug() << "Yaw:" << yaw << " Pitch:" << pitch << " Roll:" << roll;

                // Apply rotation to the bot model
                botModel.updateRotation(yaw, pitch, roll);
            }
        }
    });


    view->show();
    return app.exec();
}
