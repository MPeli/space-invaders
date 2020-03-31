#include "Timer.h"

void Timer::start()
{
    this->startTime = std::chrono::steady_clock::now();
    this->running = true;
}

void Timer::stop()
{
    this->endTime = std::chrono::steady_clock::now();
    this->running = false;
    Timer::accumulatedTime += std::chrono::duration_cast<std::chrono::milliseconds>(this->endTime - this->startTime).count();
}

void Timer::tick(const Time time)
{
    auto endTime = std::chrono::steady_clock::now();
    auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - this->startTime).count() + Timer::accumulatedTime;

    this->textTime = std::to_string(elapsedTime) + " ms";
    text.setText(this->textTime);
    text.tick(time);
}

int Timer::accumulatedTime = 0;