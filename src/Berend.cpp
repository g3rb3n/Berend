#include "Berend.h"
#include <Arduino.h>

Berend::Berend() :
    lf(true),
    rf(false),
    lh(true),
    rh(false)
{}

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
    this->rf.set(0);
    this->lf.set(0);
    this->waitTillAllDone();
}

void Berend::waitTillAllDone()
{
    while (!this->allDone()) this->update();
}

void Berend::balanceOnLeftFoot()
{
    this->lf.set(this->footBalance, 20);
    this->rf.set(-this->footBalancePush, 4);
    this->waitTillAllDone();
}

void Berend::balanceOnRightFoot()
{
    this->rf.set(this->footBalance, 20);
    this->lf.set(-this->footBalancePush, 4);
    this->waitTillAllDone();
}

void Berend::walk()
{
    this->balanceOnLeftFoot();

    this->getLeftHip().set(-30, 6);
    this->getRightHip().set(30, 6);
    this->getRightFoot().set(0, 6);
    this->waitTillAllDone();

    this->toRest();

    this->balanceOnRightFoot();

    this->getLeftHip().set(30, 6);
    this->getRightHip().set(-30, 6);
    this->getLeftFoot().set(0, 6);
    this->waitTillAllDone();

    this->toRest();
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
