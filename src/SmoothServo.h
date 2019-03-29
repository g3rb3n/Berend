#ifndef _SmoothServo_H
#define _SmoothServo_H

#include <Servo.h>

class SmoothServo : public Servo
{
  private:
    int rest = 90;
    int dir = 1;
    int pos = 90;
    long next;
    int desired = 90;
    long sleep_ms = 10;


  public:
    SmoothServo(bool left);
    void setRestPosition(int degrees);
    void update(long millis);
    bool done();
    void set(int degrees);
    void set(int degrees, long sleep_ms);
};

#endif
