#include <stdio.h>
#include <assert.h>
 
int checkRange(float value, float min, float max, const char* message) {
    if (value < min || value > max) {
        printf("%s\n", message);
        return 0;
    }
    return 1;
}
int checkChargeRate(float value, float max, const char* message)
{
    if (value > max) {
        printf("%s\n", message);
        return 0;
    }
    return 1;
}
 
 
int isTemperatureOutOfRange(float temperature) {
	return checkRange(temperature, 0, 45, "Temperature out of range!");
}
 
int isSocOutOfRange(float soc) {
	return checkRange(soc, 20, 80, "State of Charge out of range!");
}
 
int isChargeRateOutOfRange(float chargeRate) {
	return checkChargeRate(chargeRate,0.8, "Charge Rate out of range!");
}
 
int batteryIsOk(float temperature, float soc, float chargeRate) {
	return (isTemperatureOutOfRange(temperature) && isSocOutOfRange(soc) && isChargeRateOutOfRange(chargeRate));
 
}

int main() {
    assert(batteryIsOk(25, 70, 0.7) == 1); // Should pass
    assert(batteryIsOk(50, 85, 0) == 0);   // Should fail batteryIsOk checks
    assert(batteryIsOk(-5, 50, 0.5) == 0);  // Out of temperature range
    assert(batteryIsOk(25, 10, 0.5) == 0);  // Out of SOC range
    assert(batteryIsOk(25, 50, 0.9) == 0);  // Out of charge rate range

    printf("All assertions passed.\n");
    return 0;
}
