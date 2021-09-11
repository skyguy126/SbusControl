#include <unistd.h>
#include <stdexcept>

#include "../include/pybind11.h"
#include "../include/SbusControl.h"

namespace py = pybind11;

long map(long x, long in_min, long in_max, long out_min, long out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void SbusControl::begin() {
    this->sbus.begin();
}

void SbusControl::setChannel(uint16_t channel, uint16_t value) {
    if (value < SCALED_MIN || value > SCALED_MAX) {
        throw std::invalid_argument("Channel value out of bounds.");
    }

    this->channels[channel] = map(value, SCALED_MIN, SCALED_MAX, CHANNEL_MIN, CHANNEL_MAX);
}

void SbusControl::writeAllChannels() {
    this->sbus.write(this->channels);
}

PYBIND11_MODULE(sbus, m) {
    m.doc() = "Betaflight Sbus Library";
    
    py::class_<SbusControl>(m, "SbusControl")
        .def(py::init<>())
        .def("begin", &SbusControl::begin)
        .def("setChannel", &SbusControl::setChannel)
        .def("writeAllChannels", &SbusControl::writeAllChannels);
}