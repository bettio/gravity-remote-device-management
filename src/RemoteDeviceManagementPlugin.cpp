/*
 *
 */

#include "RemoteDeviceManagementPlugin.h"

#include "RemoteDeviceManagement.h"

#include <QtCore/QLoggingCategory>

#include <HemeraCore/CommonOperations>

#include <GravitySupermassive/GalaxyManager>

Q_LOGGING_CATEGORY(LOG_DEVELOPERMODE, "RemoteDeviceManagementPlugin")

using namespace Gravity;

RemoteDeviceManagementPlugin::RemoteDeviceManagementPlugin()
    : Gravity::Plugin()
{
    setName(QStringLiteral("Remote Device Management"));
}

RemoteDeviceManagementPlugin::~RemoteDeviceManagementPlugin()
{
}

void RemoteDeviceManagementPlugin::unload()
{
    qCDebug(LOG_DEVELOPERMODE) << "Remote device management plugin unloaded";
    setUnloaded();
}

void RemoteDeviceManagementPlugin::load()
{
    m_remoteDeviceManagement = new RemoteDeviceManagement(galaxyManager());

    connect(m_remoteDeviceManagement->init(), &Hemera::Operation::finished, this, [this] (Hemera::Operation *op){
        if (op->isError()) {
            qCDebug(LOG_DEVELOPERMODE) << "Error in loading RemoteDeviceManagement: " << op->errorName() << op->errorMessage();
        } else {
            qCDebug(LOG_DEVELOPERMODE) << "Remote device management plugin loaded";
            setLoaded();
        }
    });
}
