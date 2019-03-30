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
    berend.turnLeft();
}
