#include "RemoteDeviceManagement.h"

#include "remotedevicemanagementconsumer.h"
#include "RemoteDeviceManagementEventsProducer.h"

#include <QtCore/QLoggingCategory>
#include <QtCore/QTimer>

#include <HemeraCore/CommonOperations>
#include <HemeraCore/Literals>

#include <GravitySupermassive/DeviceManagement>

#include <unistd.h>

Q_LOGGING_CATEGORY(LOG_REMOTEDEVICEMANAGEMENT, "RemoteDeviceManagement")

RemoteDeviceManagement::RemoteDeviceManagement(Gravity::GalaxyManager *manager, QObject *parent)
    : Hemera::AsyncInitObject(parent)
{
}

RemoteDeviceManagement::~RemoteDeviceManagement()
{
}

void RemoteDeviceManagement::initImpl()
{
    //TODO: LOL?
    QTimer::singleShot(30000, this, [this] () {
        m_remoteDeviceManagementEventsProducer = new RemoteDeviceManagementEventsProducer(this);
        m_remoteDeviceManagementConsumer = new RemoteDeviceManagementConsumer(this);
    });

    setReady();
}

void RemoteDeviceManagement::receiveShutdown(int delay)
{
    if (Gravity::DeviceManagement::instance()) {
        // Worship satan
        Gravity::DeviceManagement::instance()->launchShutdownOperation();
    }
}

void RemoteDeviceManagement::receiveReboot(int delay)
{
    if (Gravity::DeviceManagement::instance()) {
        Gravity::DeviceManagement::instance()->launchRebootOperation();
    }
}

void RemoteDeviceManagement::receiveFactoryreset(int delay)
{
    qDebug() << "Not implemented factory reset";
}
