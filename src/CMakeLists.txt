set(GravityRemoteDeviceManagementPlugin_SRCS
    RemoteDeviceManagementPlugin.cpp
    RemoteDeviceManagement.cpp
)

# Hyperspace interface
hyperspace_add_qt5_producer(GravityRemoteDeviceManagementPlugin_SRCS ${CMAKE_SOURCE_DIR}/share/com.ispirata.Hemera.RemoteDeviceManagement.Events.json
                            RemoteDeviceManagementEventsProducer RemoteDeviceManagementEventsProducer)

hyperspace_add_qt5_consumer(GravityRemoteDeviceManagementPlugin_SRCS ${CMAKE_SOURCE_DIR}/share/com.ispirata.Hemera.RemoteDeviceManagement.json RemoteDeviceManagement.h RemoteDeviceManagement)

# final lib
add_library(gravity-center-plugin-remote-device-management SHARED ${GravityRemoteDeviceManagementPlugin_SRCS})

target_link_libraries(gravity-center-plugin-remote-device-management
                      Gravity::Supermassive
                      HemeraQt5SDK::Core
                      HyperspaceQt5::Core HyperspaceQt5::ProducerConsumer
                      Qt5::Core Qt5::Network Qt5::DBus
                      ${LIBSYSTEMD_JOURNAL_LIBRARIES}
                     )

# Install phase
install(TARGETS gravity-center-plugin-remote-device-management
        RUNTIME DESTINATION "${GRAVITY_PLUGINS_DIR}" COMPONENT bin
        LIBRARY DESTINATION "${GRAVITY_PLUGINS_DIR}" COMPONENT shlib
        ARCHIVE DESTINATION "${GRAVITY_PLUGINS_DIR}" COMPONENT shlib
        COMPONENT gravity-remote-device-management)
