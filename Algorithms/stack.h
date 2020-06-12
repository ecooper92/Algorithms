#pragma once
#include <utility>
#include "list.h"

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
			return _data.count();
		}

		inline T& bottom() const
		{
			return _data.first();
		}

		inline T& top() const
		{
			return _data.last();
		}

	private:
		list _data;
	};
}

