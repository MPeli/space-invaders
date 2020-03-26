#include "lib/leetlib.h"
#include <math.h>
#include <algorithm>

#include "Bullet.h"
#include "Enemy.h"
#include "Player.h"
#include "Sprite.h"
#include "GameComponent.h"

void Game()
{
	Sprites& sprites = Sprites::getSprites();

	// 1 player
	Player player = { sprites.player, Position(400, 550), Size(50, 50) };

	// 10 bullets
	std::vector<Bullet> bullets = { 10, { sprites.bullet, Size(10, 10) } };

	// 50 enemies
	std::vector<Enemy> enemies = { 50, { sprites.enemy } };

	int time = 0;
	auto bulletToFire = bullets.begin();
	int counter = 0;
	while (!WantQuit() && !IsKeyDown(VK_ESCAPE))
	{
		++time;

		// Draw enemies
		for (auto& enemy : enemies)
		{
			enemy.tick(time);
		}

		// Draw the user ship
		player.tick(time);

		// Handle shooting
		if (IsKeyDown(VK_SPACE))
		{
			if (counter == 0)
			{
				bulletToFire->setPosition(player.position);
				++bulletToFire;
				if (bulletToFire == bullets.end())
				{
					bulletToFire = bullets.begin();
				}

				counter = 15;
			}
			else
			{
				--counter;
			}
		}
		else
		{
			counter = 0;
		}

		// Draw bullets
		for (auto& bullet : bullets)
		{
			bullet.tick(time);
		}

		// Draw text
		auto constexpr text = "space invaders 2d";

		for (int i = 0; i < strlen(text); ++i)
		{
			if (const auto search = sprites.alphabet.find(text[i]); search != sprites.alphabet.end())
			{
				DrawSprite(search->second, i * 40 + 80, 30, 20, 20, sin(time * 0.1) * i * 0.01);
			}
		}

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
