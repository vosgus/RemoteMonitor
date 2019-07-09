#pragma once
#include <nvml.h>
#include <string>

class NVML_Wrapper
{
  public:
    void init();
    void shutdown();
    unsigned int getDeviceCount();

    nvmlDevice_t getDevice(unsigned int i);
    std::string getDeviceName(const nvmlDevice_t &device);

    unsigned int getTemperature(const nvmlDevice_t &device);
};