#ifndef _Berend_H
#define _Berend_H

#include <SmoothServo.h>

class Berend
{
  private:

    SmoothServo lf;
    SmoothServo rf;
    SmoothServo lh;
    SmoothServo rh;

    int footBalance = 25;
    int footBalancePush = 80;

  public:
    Berend();

    void attach(int rf, int lf, int rh, int lh);
    void setRestPositions(int rf, int lf, int rh, int lh);

    void setLeftFootPin(int pin);
    void setRightFootPin(int pin);
    void setLeftHipPin(int pin);
    void setRightHipPin(int pin);

    void setLeftFootCenter(int degrees);
    void setRightFootCenter(int degrees);
    void setLeftHipCenter(int degrees);
    void setRightHipCenter(int degrees);

    void update();
    bool allDone();
    void waitTillAllDone();

    void toRest();
    void balanceOnLeftFoot();
    void balanceOnRightFoot();
    void walk();

    SmoothServo &getLeftFoot();
    SmoothServo &getRightFoot();
    SmoothServo &getLeftHip();
    SmoothServo &getRightHip();
};

#endif
