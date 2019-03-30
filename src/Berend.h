#ifndef _Berend_H
#define _Berend_H

#include <SmoothServo.h>
#include <HCSR04.h>

class Berend
{
  private:

    SmoothServo lf;
    SmoothServo rf;
    SmoothServo lh;
    SmoothServo rh;

    HCSR04 sensor;

    float distanceLeftMeters = 1;
    float distanceRightMeters = 1;

    int footBalanceAngle = 25;
    int footBalanceStepMs = 20;

    int footBalancePushAngle = 75;
    int footBalancePushStepMs = 4;

    int walkTurnAngle = 30;
    int walkTurnStepMs = 6;


  public:
    Berend(int trigger, int echo);

    void attach(int rf, int lf, int rh, int lh);
    void setRestPositions(int rf, int lf, int rh, int lh);
    void set(int rf, int lf, int rh, int lh);

    void setLeftFootPin(int pin);
    void setRightFootPin(int pin);
    void setLeftHipPin(int pin);
    void setRightHipPin(int pin);

    void setLeftFootCenter(int degrees);
    void setRightFootCenter(int degrees);
    void setLeftHipCenter(int degrees);
    void setRightHipCenter(int degrees);

    void setLeftFoot(int degrees, int ms = 10);
    void setRightFoot(int degrees, int ms = 10);
    void setLeftHip(int degrees, int ms = 10);
    void setRightHip(int degrees, int ms = 10);

    void setBalanceAngle(int angle);
    void setTurnAngle(int angle);
    void setDelay(int delay);

    void update();
    bool allDone();
    void waitTillAllDone();

    void toRest();
    void standStraight();
    void balanceOnLeftFoot();
    void balanceOnRightFoot();

    void withLeftFootStraight();
    void withRightFootStraight();
    void leftFootStraight();
    void rightFootStraight();
    void turnBothLegsLeft();
    void turnBothLegsRight();
    void turnRightLegRight();
    void turnRightLegLeft();
    void turnLeftLegLeft();
    void turnLeftLegRight();

    void walk();
    void walkBackwards();

    void turnLeft();
    void turnRight();
    void turnLeftOnRightFoot();
    void turnRightOnLeftFoot();
    void turnLeftOnLeftFoot();
    void turnRightOnRightFoot();

    float distance();
    float distanceRight();
    float distanceLeft();

    void measureDistanceLeft();
    void measureDistanceRight();

    SmoothServo &getLeftFoot();
    SmoothServo &getRightFoot();
    SmoothServo &getLeftHip();
    SmoothServo &getRightHip();
};

#endif
