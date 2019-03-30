# Berend  Library
4 servos that can be controlled at the same time. With HC-SR04 for avoidance behavior.

See examples:
 * BerendWalks Berend walks straight
 * BerendAvoidsObstacles Berend walks straight up till encountering an obstacle.
 * TestTurnLeft Berend turns left
 * TestTurnRight Berend turns right
 * TestRestPosition Berend calibrated at rest, use this to make sure that the rest angles are proper.
 * TestPositiveAngle Berend has inverted angles for left and right, leftFoot.set(10) and rightFoot.set(10) makes the foot turn upwards.
 * CmdMoves Control Berend from the command line, to test all the different moves.


``` cpp
#include "Berend.h"

Berend berend(12, 13);

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
