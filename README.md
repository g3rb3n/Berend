# Berend  Library
Just 4 servos that can be controlled at the same time.

``` cpp
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
```

## SmoothServo  Library
An extension of the standard Servo library which enables setting the desired servo angle with a fixed speed without requiring delay.

``` cpp
#include "SmoothServo.h"

SmoothServo servo;
int angle = 50;

void setup() {
    servo.attach(8);
    servo.setRestPosition(90);
    servo.set(angle, 10);
}

void loop() {
    servo.update(millis());
    if(servo.done())
    {
        angle = -angle;
        servo.set(angle, 10); //Move the servo to angle with 10 ms steps.
    }
    //Do other stuff that requires minimal amounts of time
}
```
