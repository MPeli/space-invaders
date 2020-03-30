#include "Score.h"


void Score::addPoints(const int points)
{
    this->score += points;
}

void Score::setScore(const int score)
{
    this->score = score;
}

void Score::tick(const Time time)
{
    this->textScore = std::to_string(this->score);
    text.setText(this->textScore);
    text.tick(time);
}