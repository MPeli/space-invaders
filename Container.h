#pragma once

#include <deque>

template <typename T>
class Container : public std::deque<T>
{
	using iterator = typename std::deque<T>::iterator;
	using size_type = typename std::deque<T>::size_type;
	using parent = std::deque<T>;

public:
	Container() = default;

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

	template<class... Args>
	void emplace_back_multiple(const size_type count, Args&&... args)
	{
		for (size_type i = 0; i < count; ++i)
		{
			parent::emplace_back(std::forward<Args>(args)...);
		}
	}
};