#include <stdio.h>
#include <assert.h>

int batteryIsOk(float temperature, float soc, float chargeRate) {
    if (temperature < 0 || temperature > 45) {
        printf("Temperature out of range!\n");
        return 0;
    } else if (soc < 20 || soc > 80) {
        printf("State of Charge out of range!\n");
        return 0;
    } else if (chargeRate > 0.8) {
        printf("Charge Rate out of range!\n");
        return 0;
    }
    return 1;
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
