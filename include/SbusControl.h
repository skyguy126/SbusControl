#ifndef SBUS_CONTROL_H
#define SBUS_CONTROL_H

#include "./SBUS.h"

// Magic constants
#define CHANNEL_MIN 173
#define CHANNEL_MAX 1811

#define SCALED_MIN 0
#define SCALED_MAX 1000

#define SERIAL_PATH "/dev/serial0"

class SbusControl {
    public:
        SbusControl() : sbus(SERIAL_PATH) {}

        void begin();
        void setChannel(uint16_t channel, uint16_t value);
        void writeAllChannels();
        void end();
    
    private:
        SBUS::SBUS sbus;
        uint16_t channels[16];
};

#endif