#pragma once

#include "Slide.h"
#include "Text.h"

class End : public Slide
{
public:
    End();
    SlideType getNextSlide() override;

    void reset() override;
    void tick(const Time currentTime) override;

private:
    Text header = { "the end", sprites.alphabet, Position(400, 50), Text::Alignment::center, Size(40, 40) };

    Text time = { "time", sprites.alphabet, Position(80, 150), Text::Alignment::left, Size(30, 30) };
    Text timeBonus = { "time bonus", sprites.alphabet, Position(80, 200), Text::Alignment::left, Size(30, 30) };
    Text score = { "score", sprites.alphabet, Position(80, 250), Text::Alignment::left, Size(30, 30) };
    Text totalScore = { "total score", sprites.alphabet, Position(80, 300), Text::Alignment::left, Size(30, 30) };

    Text timeValue = { "", sprites.alphabet, Position(720, 150), Text::Alignment::right, Size(30, 30) };
    Text timeBonusValue = { "0 pt", sprites.alphabet, Position(720, 200), Text::Alignment::right, Size(30, 30) };
    Text scoreValue = { "", sprites.alphabet, Position(720, 250), Text::Alignment::right, Size(30, 30) };
    Text totalScoreValue = { "", sprites.alphabet, Position(720, 300), Text::Alignment::right, Size(30, 30) };

    Text firstPlace = { "", sprites.alphabet, Position(80, 400), Text::Alignment::left, Size(30, 30) };
    Text secondPlace = { "", sprites.alphabet, Position(80, 450), Text::Alignment::left, Size(30, 30) };
    Text newHightScore = { "", sprites.alphabet, Position(80, 520), Text::Alignment::left, Size(30, 30) };


};