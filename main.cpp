#include "lib/leetlib.h"

#include "GameComponents.h"
#include "Sounds.h"
#include "Logger.h"
#include "Projector.h"

#include "Slide.h"

void Game()
{
	Logger::get() << "The game has started \n";

	GameComponents::get().getSound().setVolume(0.01);

	long long int time = 0;
	while (!WantQuit() && !IsKeyDown(VK_ESCAPE))
	{
		++time;

		if (IsKeyDown(VK_SPACE) && Projector::get().getActiveSlide() == SlideType::end)
		{
			time = 0;
		}

		Projector::get().tick(time);
		GameComponents::get().getSound().tick(time);

		Flip();
	}

	Logger::get() << "The game has ended \n";
}

void OldGame()
{
	void* sprite = LoadSprite("sprite.png");
	float size = 10;
	float angle = 0;
	while (!WantQuit() && !IsKeyDown(VK_ESCAPE))
	{
		angle += 0.01f;
		float mx, my;
		GetMousePos(mx, my);
		DWORD col = 0xffffffff; // white
		if (IsKeyDown(VK_LBUTTON)) col = 0xffff0000; // solid red
		if (IsKeyDown(VK_RBUTTON)) col = 0x8000ff00; // 50% transparent green
		if (IsKeyDown(VK_UP)) size++;
		if (IsKeyDown(VK_DOWN)) size--;

		DrawSprite(sprite, 400, 300, 100, 100, angle);
		DrawSprite(sprite, mx, my, size, size, 0, col);
		Flip();
	}
}
