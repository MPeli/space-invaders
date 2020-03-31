#include "End.h"
#include "GameComponents.h"
#include "Logger.h"
#include "Projector.h"

End::End()
{
    Logger::get() << "Initializing the end slide...\n";
}

SlideType End::getNextSlide()
{
    if (IsKeyDown(VK_SPACE))
    {
        return SlideType::level01;
    }

    return SlideType::end;
}

void End::reset()
{
    Score& score = GameComponents::get().getScore();

    timeValue.setText(std::to_string(Timer::accumulatedTime) + " ms");
    scoreValue.setText(std::to_string(score.getScore()) + " pt");

    // Compute time bonus
    if (Timer::accumulatedTime < 60000)
    {
        int bonus = 60000 - Timer::accumulatedTime;
        timeBonusValue.setText(std::to_string(bonus) + " pt");

        score.addPoints(bonus);
    }
    else
    {
        timeBonusValue.setText("0 pt");
    }

    totalScoreValue.setText(std::to_string(score.getScore()) + " pt");

    const int topScore = score.getTopScore();

    if (topScore < score.getScore())
    {
        firstPlace.setText("you: " + std::to_string(score.getScore()));
        secondPlace.setText("2nd: " + std::to_string(topScore));

        newHightScore.setText("new high score congrats");

        score.saveScore(score.getScore());
    }
    else
    {
        firstPlace.setText("1st: " + std::to_string(topScore));
        secondPlace.setText("you: " + std::to_string(score.getScore()));

        newHightScore.setText("not so bad");
    }
}

void End::tick(const Time currentTime)
{
    header.tick(currentTime);

    time.tick(currentTime);
    timeBonus.tick(currentTime);
    score.tick(currentTime);
    totalScore.tick(currentTime);

    timeValue.tick(currentTime);
    timeBonusValue.tick(currentTime);
    scoreValue.tick(currentTime);
    totalScoreValue.tick(currentTime);

    firstPlace.tick(currentTime);
    secondPlace.tick(currentTime);
    newHightScore.tick(currentTime);
}