#include "Berend.h"

Berend berend(12,13);

void setup() {
    Serial.begin(9600);
    //right foot, left foot, right hip, left hip
    berend.attach(8,9,10,11);
}

int center = 90;
int offset = 150;

void loop() {
    Serial.println("None");
    berend.setRestPositions(center, center, center, center);
    berend.toRest();
    delay(2000);

    Serial.println("RF");
    berend.setRestPositions(offset, center, center, center);
    berend.toRest();
    delay(2000);

    Serial.println("LF");
    berend.setRestPositions(center, offset, center, center);
    berend.toRest();
    delay(2000);

    Serial.println("RH");
    berend.setRestPositions(center, center, offset, center);
    berend.toRest();
    delay(2000);

    Serial.println("LH");
    berend.setRestPositions(center, center, center, offset);
    berend.toRest();
    delay(2000);
}
