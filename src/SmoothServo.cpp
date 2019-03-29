#include "SmoothServo.h"

SmoothServo::SmoothServo(bool left){
    if (left) this->dir = -1;
}

void SmoothServo::setRestPosition(int degrees){
    this->rest = degrees;
}

void SmoothServo::set(int degrees){
    this->set(degrees, 10);
}

void SmoothServo::set(int degrees, long ms){
    this->desired = degrees * this->dir + this->rest;
    this->sleep_ms = ms;
}

void SmoothServo::update(long millis){
    if (millis < this->next) return;
    int step = 0;
    if (this->pos < this->desired)
        this->pos++;
    else if(this->pos > this->desired)
        this->pos--;
    this->write(this->pos);
    this->next = millis + this->sleep_ms;
}

bool SmoothServo::done(){
    return this->pos == this->desired;
}
