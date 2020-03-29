#pragma once

#include <string>
#include "Tickable.h"
#include "Text.h"

class Score : public Tickable
{
public:
    void addPoints(const int points);

    void tick(const Time time) override;

    operator std::string() const;

private:
    long int score = 0;
    Text text = { "", Sprites::get().alphabet, Position(400, 200), Text::Alignment::center, Size(40, 40) };
};