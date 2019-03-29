#include "Berend.h"

Berend berend;

void setup() {
    //right foot, left foot, right hip, left hip
    berend.attach(8,9,10,11);
    berend.setRestPositions(95, 105, 90, 90);

    berend.toRest();
    delay(2000);
}

void loop() {
    berend.walk();
}
