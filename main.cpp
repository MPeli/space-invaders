#include "lib/leetlib.h"
#include <algorithm>
#include <deque>
#include <math.h>

#include "Bullet.h"
#include "Enemy.h"
#include "GameComponent.h"
#include "Player.h"
#include "Sprite.h"
#include "Text.h"

template <typename T>
class Container : public std::deque<T>
{
	using iterator = typename std::deque<T>::iterator;
	using size_type = typename std::deque<T>::size_type;
	using parent = std::deque<T>;

public:
	Container(const size_type count, const T& value)
	{
		for (size_type i = 0; i < count; ++i)
		{
			parent::push_back(value);
		}
	}

	iterator begin() noexcept
	{
		return parent::begin();
	}

	iterator end() noexcept
	{
		return parent::end();
	}

	void next(iterator& iterator)
	{
		iterator = std::next(iterator);
		if (iterator == parent::end())
		{
			iterator = parent::begin();
		}
	}

	template<class... Args>
	T& emplace_back(Args&&... args)
	{
		return parent::emplace_back(std::forward<Args>(args)...);
	}
};

void Game()
{
	Sprites& sprites = Sprites::getSprites();

	// 1 player
	Player player = { sprites.player, Position(400, 550), Size(50, 50) };

	// 10 bullets
	Container<Bullet> bullets = { 10, { sprites.bullet, Size(10, 10) } };

	// 50 enemies
	Container<Enemy> enemies = { 50, { sprites.enemy } };

	// Title
	Text header = { "space invaders 2d", sprites.alphabet, Position(80, 30) };

	int time = 0;
	auto bulletToFire = bullets.begin();
	int counter = 0;
	while (!WantQuit() && !IsKeyDown(VK_ESCAPE))
	{
		++time;

		// Draw header
		header.tick(time);

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
				bullets.next(bulletToFire);

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
