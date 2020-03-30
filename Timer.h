#pragma once
#include <chrono>
#include <ctime>
#include <cmath>
#include <string>
#include "Tickable.h"
#include "Text.h"

class Timer : Tickable
{
public:
    double getAccumulatedTime();
    void start();
    void stop();
    void tick(const Time time) override;

private:
    std::chrono::time_point<std::chrono::steady_clock> startTime;
    std::chrono::time_point<std::chrono::steady_clock> endTime;
    bool running = false;
    double accumulatedTime = 0;

    std::string textTime;
    Text text = { "", Sprites::get().alphabet, Position(720, 550), Text::Alignment::right, Size(40, 40) };
};