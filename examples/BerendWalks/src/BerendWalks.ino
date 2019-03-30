#include "Berend.h"

Berend berend(12,13);

void setup() {
    Serial.begin(9600);
    //right foot, left foot, right hip, left hip
    berend.attach(8,9,10,11);
    berend.setRestPositions(95, 105, 90, 90);
    berend.toRest();
    delay(2000);
}

void loop() {
    float distance = berend.distance();
    float distanceLeft = berend.distanceLeft();
    float distanceRight = berend.distanceRight();
    Serial.print(distanceLeft);
    Serial.print(" ");
    Serial.println(distanceRight);
    if (distanceLeft > .2 && distanceRight > .2)
    {
        Serial.println("walk");
        berend.walk();
    }
    else if (distanceLeft < .1 || distanceRight < .1)
    {
        Serial.println("back");
        berend.walkBackwards();
    }
    else if (distanceLeft < distanceRight)
    {
        Serial.println("right");
        berend.turnRight();
    }
    else {
        Serial.println("left");
        berend.turnLeft();
    }
}
