CFLAGS = -shared -std=c++11 -Wall -Werror -fPIC
PYBIND11_CFLAGS := $(shell python3 -m pybind11 --includes)
EXTENSION := $(shell python3-config --extension-suffix)

all:
	g++ -o sbus$(EXTENSION) ./src/SbusControl.cpp ./lib/libsbus.a -I./include $(CFLAGS) $(PYBIND11_CFLAGS)

clean:
	rm -rf sbus$(EXTENSION)