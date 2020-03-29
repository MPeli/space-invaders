#pragma once

#include <string>
#include "Singleton.h"
#include <Windows.h>

class Logger : public Singleton<Logger>
{
    friend Singleton<Logger>;
public:
    Logger& operator<<(const char* str)
    {
        OutputDebugString(str);
        return *this;
    }
    Logger& operator<<(const float number)
    {
        OutputDebugString(std::to_string(number).c_str());
        return *this;
    }
};

