#include "Berend.h"
#include <Arduino.h>

Berend::Berend(int trigger, int echo) :
    sensor(trigger, echo),
    lf(true),
    rf(false),
    lh(true),
    rh(false)
{}

float Berend::distance()
{
    return (this->distanceRightMeters + this->distanceLeftMeters) / 2.;
}

float Berend::distanceRight()
{
    return this->distanceRightMeters;
}

float Berend::distanceLeft()
{
    return this->distanceLeftMeters;
}

void Berend::attach(int rf, int lf, int rh, int lh)
{
    this->setRightFootPin(rf);
    this->setLeftFootPin(lf);
    this->setRightHipPin(rh);
    this->setLeftHipPin(lh);
}

void Berend::setRightFootPin(int pin)
{
    this->rf.attach(pin);
}

void Berend::setLeftFootPin(int pin)
{
    this->lf.attach(pin);
}

void Berend::setRightHipPin(int pin)
{
    this->rh.attach(pin);
}

void Berend::setLeftHipPin(int pin)
{
    this->lh.attach(pin);
}


void Berend::setRestPositions(int rf, int lf, int rh, int lh)
{
    this->setRightFootCenter(rf);
    this->setLeftFootCenter(lf);
    this->setRightHipCenter(rh);
    this->setLeftHipCenter(lh);
}

void Berend::set(int rf, int lf, int rh, int lh)
{
    this->rf.set(rf);
    this->lf.set(lf);
    this->rh.set(rh);
    this->lh.set(lh);
}

void Berend::setRightFootCenter(int degrees)
{
    this->rf.setRestPosition(degrees);
}

void Berend::setLeftFootCenter(int degrees)
{
    this->lf.setRestPosition(degrees);
}

void Berend::setRightHipCenter(int degrees)
{
    this->rh.setRestPosition(degrees);
}

void Berend::setLeftHipCenter(int degrees)
{
    this->lh.setRestPosition(degrees);
}


void Berend::setRightFoot(int degrees, int ms)
{
    this->rf.set(degrees, ms);
}

void Berend::setLeftFoot(int degrees, int ms)
{
    this->lf.set(degrees, ms);
}

void Berend::setRightHip(int degrees, int ms)
{
    this->rh.set(degrees, ms);
}

void Berend::setLeftHip(int degrees, int ms)
{
    this->lh.set(degrees, ms);
}


SmoothServo& Berend::getLeftFoot()
{
    return this->lf;
}

SmoothServo& Berend::getRightFoot()
{
    return this->rf;
}

SmoothServo& Berend::getLeftHip()
{
    return this->lh;
}

SmoothServo& Berend::getRightHip()
{
    return this->rh;
}

void Berend::setBalanceAngle(int angle)
{
    this->footBalanceAngle = angle;
    this->footBalancePushAngle = angle * 3;
}

void Berend::setTurnAngle(int angle)
{
    this->walkTurnAngle = angle;
}

void Berend::setDelay(int delay)
{
    this->footBalanceStepMs = 10 * delay;
    this->footBalancePushStepMs = 2 * delay;
    this->walkTurnStepMs = 3 * delay;
}

void Berend::update()
{
    long ms = millis();
    this->lh.update(ms);
    this->lf.update(ms);
    this->rh.update(ms);
    this->rf.update(ms);
}

bool Berend::allDone()
{
    return this->lh.done()
        && this->lf.done()
        && this->rh.done()
        && this->rf.done();
}

void Berend::toRest()
{
    this->rf.set(0, this->footBalanceStepMs);
    this->lf.set(0, this->footBalanceStepMs);
    this->rh.set(0, this->footBalanceStepMs);
    this->lh.set(0, this->footBalanceStepMs);
    this->waitTillAllDone();
}

void Berend::standStraight()
{
    this->rf.set(0, this->footBalanceStepMs);
    this->lf.set(0, this->footBalanceStepMs);
    this->waitTillAllDone();
}

void Berend::waitTillAllDone()
{
    while (!this->allDone()) this->update();
}

void Berend::balanceOnLeftFoot()
{
    this->lf.set(this->footBalanceAngle, this->footBalanceStepMs);
    this->rf.set(-this->footBalancePushAngle, this->footBalancePushStepMs);
    this->waitTillAllDone();
}

void Berend::balanceOnRightFoot()
{
    this->rf.set(this->footBalanceAngle, this->footBalanceStepMs);
    this->lf.set(-this->footBalancePushAngle, this->footBalancePushStepMs);
    this->waitTillAllDone();
}

void Berend::measureDistanceLeft()
{
    this->distanceLeftMeters = sensor.meters();
}

void Berend::measureDistanceRight()
{
    this->distanceRightMeters = sensor.meters();
}


void Berend::turnLeftLegLeft()
{
    this->lh.set(this->walkTurnAngle, this->walkTurnStepMs);
    this->rh.set(0, this->walkTurnStepMs);
    this->waitTillAllDone();
}

void Berend::turnLeftLegRight()
{
    this->lh.set(-this->walkTurnAngle, this->walkTurnStepMs);
    this->rh.set(0, this->walkTurnStepMs);
    this->waitTillAllDone();
}

void Berend::turnRightLegRight()
{
    this->rh.set(this->walkTurnAngle, this->walkTurnStepMs);
    this->lh.set(0, this->walkTurnStepMs);
    this->waitTillAllDone();
}

void Berend::turnRightLegLeft()
{
    this->rh.set(-this->walkTurnAngle, this->walkTurnStepMs);
    this->lh.set(0, this->walkTurnStepMs);
    this->waitTillAllDone();
}

void Berend::turnBothLegsRight()
{
    this->rh.set(this->walkTurnAngle, this->walkTurnStepMs);
    this->lh.set(-this->walkTurnAngle, this->walkTurnStepMs);
    this->waitTillAllDone();
}

void Berend::turnBothLegsLeft()
{
    this->lh.set(this->walkTurnAngle, this->walkTurnStepMs);
    this->rh.set(-this->walkTurnAngle, this->walkTurnStepMs);
    this->waitTillAllDone();
}

void Berend::walk()
{
    this->balanceOnLeftFoot();
    this->withRightFootStraight();
    this->turnBothLegsRight();
    this->standStraight();
    this->measureDistanceLeft();

    this->balanceOnRightFoot();
    this->withLeftFootStraight();
    this->turnBothLegsLeft();
    this->standStraight();
    this->measureDistanceRight();
}

void Berend::walkBackwards()
{
    this->balanceOnLeftFoot();
    this->withRightFootStraight();
    this->turnBothLegsLeft();
    this->standStraight();
    this->measureDistanceRight();

    this->balanceOnRightFoot();
    this->withLeftFootStraight();
    this->turnBothLegsRight();
    this->standStraight();
    this->measureDistanceLeft();
}


void Berend::leftFootStraight()
{
    this->withLeftFootStraight();
    this->waitTillAllDone();
}

void Berend::rightFootStraight()
{
    this->withRightFootStraight();
    this->waitTillAllDone();
}

void Berend::withLeftFootStraight()
{
    this->lf.set(0, this->footBalancePushStepMs);
}

void Berend::withRightFootStraight()
{
    this->rf.set(0, this->footBalancePushStepMs);
}

void Berend::turnRight()
{
    this->turnRightOnRightFoot();
}

void Berend::turnLeft()
{
    this->turnLeftOnLeftFoot();
}


void Berend::turnRightOnRightFoot()
{
    this->balanceOnLeftFoot();
    this->withRightFootStraight();
    this->turnRightLegRight();
    this->standStraight();
    this->measureDistanceLeft();

    this->balanceOnRightFoot();
    this->withLeftFootStraight();
    this->turnRightLegLeft();
    this->standStraight();
    this->measureDistanceRight();
}

void Berend::turnLeftOnLeftFoot()
{
    this->balanceOnRightFoot();
    this->withLeftFootStraight();
    this->turnLeftLegLeft();
    this->standStraight();
    this->measureDistanceRight();

    this->balanceOnLeftFoot();
    this->withRightFootStraight();
    this->turnLeftLegRight();
    this->standStraight();
    this->measureDistanceLeft();
}

void Berend::turnRightOnLeftFoot()
{
    this->balanceOnRightFoot();
    this->withLeftFootStraight();
    this->turnLeftLegRight();
    this->standStraight();
    this->measureDistanceLeft();

    this->balanceOnLeftFoot();
    this->withRightFootStraight();
    this->turnLeftLegLeft();
    this->standStraight();
    this->measureDistanceRight();
}

void Berend::turnLeftOnRightFoot()
{
    this->balanceOnLeftFoot();
    this->withRightFootStraight();
    this->turnRightLegLeft();
    this->standStraight();
    this->measureDistanceRight();

    this->balanceOnRightFoot();
    this->withLeftFootStraight();
    this->turnRightLegRight();
    this->standStraight();
    this->measureDistanceLeft();
}
