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

    text.setText(std::to_string(Timer::accumulatedTime) + " ms");
}

void Timer::tick(const Time time)
{
    if (this->running)
    {
        auto endTime = std::chrono::steady_clock::now();
        auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - this->startTime).count() + Timer::accumulatedTime;

        text.setText(std::to_string(elapsedTime) + " ms");
    }

    text.tick(time);
}

int Timer::accumulatedTime = 0;