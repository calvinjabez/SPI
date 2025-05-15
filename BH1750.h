#ifndef BH1750_H
#define BH1750_H

#include <stdint.h>

class BH1750 {
public:
    // Constructor to initialize with I2C address
    BH1750(uint8_t address);

    // Initialize the sensor
    bool begin();

    // Read light intensity in lux
    float readLightLevel();

private:
    uint8_t _address; // I2C address of the sensor

    // Helper function to write a command to the sensor
    bool writeCommand(uint8_t command);

    // Helper function to read data from the sensor
    bool readData(uint16_t &data);
};

#endif // BH1750_H