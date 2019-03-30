#include "Berend.h"

Berend berend(12,13);

int offset = 60;

void setup() {
    Serial.begin(9600);
    //right foot, left foot, right hip, left hip
    berend.attach(8,9,10,11);
    berend.setRestPositions(95, 105, 90, 90);
}

char cmd = 's';
int delay_ms = 2;

void loop() {
    if (Serial.available())
    {
        char c = Serial.read();
        if (c == '+'){
            delay_ms++;
            berend.setDelay(delay_ms);
        }
        else if (c == '-'){
            --delay_ms;
            berend.setDelay(delay_ms);
        }
        else
            cmd = c;
    }
    switch (cmd){
        case '1': berend.balanceOnLeftFoot(); break;
        case '2': berend.withRightFootStraight(); berend.turnBothLegsRight(); break;
        case '3': berend.standStraight(); break;
        case '4': berend.measureDistanceLeft(); Serial.println(berend.distanceLeft()); break;
        case '5': berend.balanceOnRightFoot(); break;
        case '6': berend.withLeftFootStraight(); berend.turnBothLegsLeft(); break;
        case '7': berend.standStraight(); break;
        case '8': berend.measureDistanceRight(); Serial.println(berend.distanceRight()); break;
        case 'w': berend.walk(); break;
        case 'x': berend.walkBackwards(); break;
        case 'q': berend.turnLeft(); break;
        case 'e': berend.turnRight(); break;
        case 'Q': berend.leftFootStraight(); break;
        case 'E': berend.rightFootStraight(); break;
        case 'z': berend.turnLeftOnRightFoot(); break;
        case 'c': berend.turnRightOnLeftFoot(); break;
        case 's': berend.toRest(); break;
        case 'S': berend.standStraight(); break;
        case 'a': berend.balanceOnLeftFoot(); break;
        case 'd': berend.balanceOnRightFoot(); break;
        case 'A': berend.turnBothLegsLeft(); break;
        case 'D': berend.turnBothLegsRight(); break;
        default: Serial.println("Uknown command");
    }
}
