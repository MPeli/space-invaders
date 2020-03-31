#pragma once

#include <string>
#include "Tickable.h"
#include "Text.h"

class Score : public Tickable
{
public:
    void addPoints(const int points) noexcept;
    int  getScore() const noexcept;
    void setScore(const int score) noexcept;
    int getTopScore();
    void saveScore(const int score);
    void tick(const Time time) override;

private:
    long int score = 0;
    std::string textScore;
    Text text = { "", Sprites::get().alphabet, Position(720, 30), Text::Alignment::right, Size(40, 40) };
};