#pragma once
#include <algorithm>
#include "List.h"

namespace algorithms
{
	template <typename T>
	class stack
	{
	public:
		stack() {}

		explicit stack(int reserveSize) :
			_data(reserveSize) {}

		stack(std::initializer_list<T> list) :
			_data(list) {}

		inline void push(T& item)
		{
			_data.add(item);
		}

		inline T& pop()
		{
			return _data.remove();
		}

		inline int count() const
		{
			return _count;
		}

		inline T& bottom() const
		{
			return _data[0];
		}

		inline T& top() const
		{
			return _data[_count - 1];
		}

	private:
		list _data;
	};
}

