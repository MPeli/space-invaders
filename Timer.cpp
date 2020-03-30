#include "Timer.h"

double Timer::getAccumulatedTime()
{
    return this->accumulatedTime;
}

void Timer::start()
{
    this->startTime = std::chrono::steady_clock::now();
    this->running = true;
}

void Timer::stop()
{
    this->endTime = std::chrono::steady_clock::now();
    this->running = false;
    this->accumulatedTime += std::chrono::duration_cast<std::chrono::milliseconds>(this->endTime - this->startTime).count();
}

void Timer::tick(const Time time)
{
    this->textTime = std::to_string(this->accumulatedTime) + " ms";
    text.setText(this->textTime);
    text.tick(time);
}