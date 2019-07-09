#include <stdio.h>
#include <nvml.h>
#include "NVML_Wrapper.hpp"
#include <iostream>

int main()
{
    nvmlReturn_t result;
    NVML_Wrapper nvml;

    try
    {
      nvml.init();

      unsigned int device_count = nvml.getDeviceCount();
      for (unsigned int i = 0; i < device_count; i++)
      {
        nvmlDevice_t device = nvml.getDevice(i);
        unsigned int temp = nvml.getTemperature(device);

        std::cout << temp << std::endl;
      }
    }
    catch (std::runtime_error e)
    {
      std::cout << e.what() << std::endl;
    }

    return 0;
}
