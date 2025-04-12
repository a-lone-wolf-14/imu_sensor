#ifndef BOTMODEL_QT3D_H
#define BOTMODEL_QT3D_H

#include <Qt3DCore/QEntity>
#include <Qt3DCore/QTransform>

class BotModel_Qt3D : public QObject {
    Q_OBJECT

public:
    explicit BotModel_Qt3D(Qt3DCore::QEntity *parent = nullptr);
    Qt3DCore::QEntity* getRootEntity() const;

public slots:
    void updateRotation(float yaw, float pitch, float roll);

private:
    Qt3DCore::QEntity *rootEntity;
    Qt3DCore::QTransform *transform;
    Qt3DCore::QEntity *m_rootEntity;
};

#endif // BOTMODEL_QT3D_H
