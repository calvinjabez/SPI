#include <iostream>
#include "BH1750.h"

int main() {
    // Initialize the BH1750 sensor with its default I2C address
    uint8_t sensorAddress = 0x23; // Default I2C address for BH1750
    BH1750 lightSensor(sensorAddress);

    // Initialize the sensor
    if (!lightSensor.begin()) {
        std::cerr << "Failed to initialize the BH1750 sensor!" << std::endl;
        return -1;
    }

    // Read light intensity
    float lux = lightSensor.readLightLevel();
    if (lux == -1.0f) {
        std::cerr << "Failed to read data from the BH1750 sensor!" << std::endl;
        return -1;
    }

    // Display the light intensity
    std::cout << "Ambient Light Intensity: " << lux << " lux" << std::endl;

    return 0;
}