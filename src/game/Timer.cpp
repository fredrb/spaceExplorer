#include "Timer.h"

void Timer::start() {
    this->begin = clock();
}

void Timer::stop() {
    this->end = clock();
}

double Timer::getElapsedTime() {
    return (double(this->end - this->begin) / CLOCKS_PER_SEC) * 1000;
}
