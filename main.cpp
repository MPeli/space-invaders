#include "lib/leetlib.h"

#include "GameComponent.h"
#include "Beginning.h"
#include "Bullet.h"
#include "Container.h"
#include "Enemy.h"
#include "Player.h"
#include "Sprite.h"
#include "Sounds.h"
#include "Text.h"
#include "Logger.h"

void Game()
{
	Logger::get() << "The game has started";

	Beginning frame01;
	Level01 level01;

	Sounds::get().setVolume(0.01);

	long long int time = 0;
	while (!WantQuit() && !IsKeyDown(VK_ESCAPE))
	{
		++time;

		frame01.tick(time);
		Sounds::get().tick(time);

		Flip();
	}
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
