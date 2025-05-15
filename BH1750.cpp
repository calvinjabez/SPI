#include "BH1750.h"
#include <iostream> // Mock I2C communication for demonstration

// BH1750 Commands
#define BH1750_POWER_ON  0x01
#define BH1750_RESET     0x07
#define BH1750_CONT_HRES_MODE 0x10 // Continuous high-resolution mode

// Constructor
BH1750::BH1750(uint8_t address) : _address(address) {}

// Initialize the sensor
bool BH1750::begin() {
    // Power on the sensor
    if (!writeCommand(BH1750_POWER_ON)) return false;

    // Reset the sensor
    if (!writeCommand(BH1750_RESET)) return false;

    // Set to continuous high-resolution mode
    if (!writeCommand(BH1750_CONT_HRES_MODE)) return false;

    return true;
}

// Read light intensity in lux
float BH1750::readLightLevel() {
    uint16_t rawData = 0;
    if (!readData(rawData)) {
        return -1.0f; // Indicate an error
    }

    // Convert raw data to lux (1 lx = rawData / 1.2)
    return rawData / 1.2f;
}

// Write a command to the sensor
bool BH1750::writeCommand(uint8_t command) {
    // Mock I2C