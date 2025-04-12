#include "botmodel_qt3d.h"
#include <Qt3DExtras/QTorusMesh>
#include <Qt3DExtras/QPhongMaterial>
#include <QDebug>

BotModel_Qt3D::BotModel_Qt3D(Qt3DCore::QEntity *parent) : QObject(parent) {
    rootEntity = new Qt3DCore::QEntity(parent);
    qDebug()<<"creating 3d model...";
    // Create 3D object (Torus)
    Qt3DCore::QEntity *modelEntity = new Qt3DCore::QEntity(rootEntity);
    Qt3DExtras::QTorusMesh *mesh = new Qt3DExtras::QTorusMesh();
    mesh->setRadius(2.0);
    mesh->setMinorRadius(0.5);
    mesh->setRings(100);
    mesh->setSlices(20);
    modelEntity->addComponent(mesh);

    // Material
    Qt3DExtras::QPhongMaterial *material = new Qt3DExtras::QPhongMaterial();
    material->setDiffuse(QColor(100, 200, 255));  // Light blue
    modelEntity->addComponent(material);

    // Transform
    transform = new Qt3DCore::QTransform();
    modelEntity->addComponent(transform);
    qDebug()<<"3d model created.";
}

Qt3DCore::QEntity* BotModel_Qt3D::getRootEntity() const {
    return m_rootEntity;
}

void BotModel_Qt3D::updateRotation(float yaw, float pitch, float roll) {
    qDebug() << "Yaw:" << yaw << "Pitch:" << pitch << "Roll:" << roll;
    transform->setRotationX(pitch);
    transform->setRotationY(yaw);
    transform->setRotationZ(roll);
}
