//
// Created by VitorVRS on 9/30/16.
//

#ifndef STAR_EXPLORER_TIMER_H
#define STAR_EXPLORER_TIMER_H

#include <ctime>

class Timer {
private:
    clock_t begin;
    clock_t end;

public:
    void start();
    void stop();
    double getElapsedTime();
};

#endif //STAR_EXPLORER_TIMER_H
