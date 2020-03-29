#include "Score.h"


void Score::addPoints(const int points)
{
    this->score += points;
}

void Score::tick(const Time time)
{

}

Score::operator std::string() const
{
    return std::to_string(this->score);
}