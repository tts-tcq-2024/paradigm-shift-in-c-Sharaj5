#include <stdio.h>
#include <assert.h>

int isTemperatureOk(float temperature) {
    return temperature < 0 || temperature > 45;
}

int isSocOk(float soc) {
    return soc < 20 || soc > 80;
}

int isChargeRateOk(float chargeRate) {
    return chargeRate > 0.8;
}

void disp_temp(int temp_check){
    
    if(!temp_check){
        printf("Temperature out of range!\n");
    }
}
void disp_soc(int soc_check){
    
    if(!soc_check){
        printf("State of Charge out of range!\n");
    }
}
void disp_cr(int cr_check){
    
    if(!cr_check){
        printf("Charge Rate out of range!\n");
    }
}
int batteryIsOk(float temperature, float soc, float chargeRate) {
    int temp_ok = !isTemperatureOk(temperature);
    int soc_ok = !isSocOk(soc);
    int charge_ok = !isChargeRateOk(chargeRate);
    
    disp_temp(temp_ok);
    disp_soc(soc_ok);
    disp_cr(charge_ok);
    
    return 1;
}
int main() {
    assert(batteryIsOk(25, 70, 0.7));//no print
    assert(batteryIsOk(55, 50, 0.2));//temp out of range
    assert(batteryIsOk(-1, 75, 0.0));//temp out of range
    assert(batteryIsOk(20, 90, 0.2));//Soc Out of range
    assert(batteryIsOk(20, 15, 0.2));//Soc Out of range
    assert(batteryIsOk(25, 25, 0.8));//charge out of range
}
