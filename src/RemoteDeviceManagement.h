#ifndef DEVICE_INFO_H
#define DEVICE_INFO_H

#include <HemeraCore/AsyncInitObject>

namespace Gravity {
class GalaxyManager;
}

class RemoteDeviceManagementConsumer;
class RemoteDeviceManagementEventsProducer;

class RemoteDeviceManagement : public Hemera::AsyncInitObject
{
    public:
        explicit RemoteDeviceManagement(Gravity::GalaxyManager *manager, QObject *parent = nullptr);
        virtual ~RemoteDeviceManagement();

        void receiveShutdown(int delay);
        void receiveReboot(int delay);
        void receiveFactoryreset(int delay);

    protected:
        virtual void initImpl() override final;

    private:
        RemoteDeviceManagementEventsProducer *m_remoteDeviceManagementEventsProducer;
        RemoteDeviceManagementConsumer *m_remoteDeviceManagementConsumer;
};

#endif
