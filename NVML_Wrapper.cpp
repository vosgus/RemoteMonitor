#include "NVML_Wrapper.hpp"
#include <stdexcept>
#include <nvml.h>

void NVML_Wrapper::init()
{
  nvmlReturn_t result = nvmlInit();
  if (result != NVML_SUCCESS)
  {
    throw std::runtime_error(nvmlErrorString(result));
  }
}

void NVML_Wrapper::shutdown()
{
  nvmlReturn_t result = nvmlShutdown();
  if (result != NVML_SUCCESS)
  {
    throw std::runtime_error(nvmlErrorString(result));
  }
}

unsigned int NVML_Wrapper::getDeviceCount()
{
  unsigned int device_count = 0;
  nvmlReturn_t result = nvmlDeviceGetCount(&device_count);
  if (result != NVML_SUCCESS)
  {
    throw std::runtime_error(nvmlErrorString(result));
  }

  return device_count;
}

nvmlDevice_t NVML_Wrapper::getDevice(unsigned int i)
{
  nvmlDevice_t device = 0;
  nvmlReturn_t result = nvmlDeviceGetHandleByIndex(i, &device);
  if (result != NVML_SUCCESS)
  {
    throw std::runtime_error(nvmlErrorString(result));
  }

  return device;
}

std::string NVML_Wrapper::getDeviceName(const nvmlDevice_t & device)
{
  char name_buffer[NVML_DEVICE_NAME_BUFFER_SIZE] = {0};
  nvmlReturn_t result = nvmlDeviceGetName(device, name_buffer, NVML_DEVICE_NAME_BUFFER_SIZE);
  if (result != NVML_SUCCESS)
  {
    throw std::runtime_error(nvmlErrorString(result));
  }

  return std::string(name_buffer);
}

unsigned int NVML_Wrapper::getTemperature(const nvmlDevice_t &device)
{
  unsigned int temp = 0;
  nvmlReturn_t result = nvmlDeviceGetTemperature(device, NVML_TEMPERATURE_GPU, &temp);
  if (result != NVML_SUCCESS)
  {
    throw std::runtime_error(nvmlErrorString(result));
  }

  return temp;
}