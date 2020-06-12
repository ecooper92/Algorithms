#pragma once
#include <utility>
#include "list.h"

namespace algorithms
{
	template <typename T>
	class queue
	{
	public:
		queue() {}

		explicit queue(int reserveSize) :
			_data(reserveSize) {}

		queue(std::initializer_list<T> list) :
			_data(list) {}

		inline void enqueue(T& item)
		{
			_data.push_back(item);
		}

		inline T& dequeue()
		{
			return _data.pop_front();
		}

		inline int size() const
		{
			return _data.size();
		}

		inline T& front() const
		{
			return _data.first();
		}

		inline T& back() const
		{
			return _data.last();
		}

	private:
		list _data;
	};
}
