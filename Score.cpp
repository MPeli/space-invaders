#include "Score.h"


void Score::addPoints(const int points) noexcept
{
    this->score += points;
}

int Score::getScore() const noexcept
{
    return this->score;
}

void Score::setScore(const int score) noexcept
{
    this->score = score;
}

void Score::saveScore(const int score)
{
    LPCSTR reg_path = "SOFTWARE\\SpaceInvaders";

    HKEY default_key;
    auto status = RegCreateKeyExA(HKEY_CURRENT_USER, reg_path, 0, NULL, REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL, &default_key, NULL);
    if (status == ERROR_SUCCESS)
    {
        // Writing
        DWORD value = score;
        status = RegSetValueExA(default_key, "score", 0, REG_DWORD, (const BYTE*)&value, sizeof(value));
    }

    RegCloseKey(default_key);
}

int Score::getTopScore()
{
    DWORD data = 0;

    LPCSTR reg_path = "SOFTWARE\\SpaceInvaders";

    HKEY default_key;
    auto status = RegCreateKeyExA(HKEY_CURRENT_USER, reg_path, 0, NULL, REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL, &default_key, NULL);
    if (status == ERROR_SUCCESS)
    {
        // Reading
        DWORD size = sizeof(DWORD);
        DWORD type = REG_DWORD;
        status = RegQueryValueExA(default_key, "score", NULL, &type, (LPBYTE)&data, &size);
    }

    RegCloseKey(default_key);

    return data;
}

void Score::tick(const Time time)
{
    this->textScore = std::to_string(this->score);
    text.setText(this->textScore);
    text.tick(time);
}