/*
 *
 */

#ifndef GRAVITY_REMOTE_DEVICE_MANAGEMENT_PLUGIN_H
#define GRAVITY_REMOTE_DEVICE_MANAGEMENT_PLUGIN_H

#include <gravityplugin.h>

namespace Hemera {
    class Operation;
}

class RemoteDeviceManagement;

namespace Gravity {

struct Orbit;

class RemoteDeviceManagementPlugin : public Gravity::Plugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.ispirata.Hemera.GravityCenter.Plugin")
    Q_INTERFACES(Gravity::Plugin)

public:
    explicit RemoteDeviceManagementPlugin();
    virtual ~RemoteDeviceManagementPlugin();

protected:
    virtual void unload() override final;
    virtual void load() override final;

private:
    RemoteDeviceManagement *m_remoteDeviceManagement;
};
}

#endif // GRAVITY_REMOTE_DEVICE_MANAGEMENT_PLUGIN_H
