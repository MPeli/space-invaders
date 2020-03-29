#pragma once
#include <cstdio>
#include <string>
#include <Windows.h>

class Logger
{
public:
    static Logger& get()
    {
        static Logger logger;
        return logger;
    }

    Logger& operator<<(const char* str)
    {
        // std::puts(str);
        OutputDebugString(str);
        return *this;
    }
    Logger& operator<<(const float number)
    {
        // std::puts(str);
        OutputDebugString(std::to_string(number).c_str());
        return *this;
    }
};

