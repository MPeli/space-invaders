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
    void start();
    void stop();
    void tick(const Time time) override;
    static int accumulatedTime;

private:
    std::chrono::time_point<std::chrono::steady_clock> startTime;
    std::chrono::time_point<std::chrono::steady_clock> endTime;
    bool running = false;

    std::string textTime;
    Text text = { "", Sprites::get().alphabet, Position(720, 550), Text::Alignment::right, Size(20, 20) };
};