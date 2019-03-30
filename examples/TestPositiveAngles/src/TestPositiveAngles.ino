#include "Berend.h"

Berend berend(12,13);

int offset = 60;

void setup() {
    Serial.begin(9600);
    //right foot, left foot, right hip, left hip
    berend.attach(8,9,10,11);
    berend.setRestPositions(95, 105, 90, 90);
    berend.toRest();
}

void loop() {
    Serial.println("RF");
    berend.set(offset, 0, 0, 0);
    berend.waitTillAllDone();
    delay(2000);
    berend.toRest();

    Serial.println("LF");
    berend.set(0, offset, 0, 0);
    berend.waitTillAllDone();
    delay(2000);
    berend.toRest();

    Serial.println("RH");
    berend.set(0, 0, offset, 0);
    berend.waitTillAllDone();
    delay(2000);
    berend.toRest();

    Serial.println("LH");
    berend.set(0, 0, 0, offset);
    berend.waitTillAllDone();
    delay(2000);
    berend.toRest();
}
