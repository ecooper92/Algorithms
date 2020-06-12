#pragma once
#include <algorithm>

namespace Algorithms
{
	template <typename T>
	class List
	{
	public:
		List() :
			_count(0),
			_dataSize(16),
			_data(new T[16]) 
		{
		}

		explicit List(int reserveSize) :
			_count(0),
			_dataSize(reserveSize),
			_data(new T[reserveSize]) 
		{
		}

		List(T items[], int count) :
			_count(count),
			_dataSize(count),
			_data(new T[count])
		{
			std::copy(items, items + _count, _data);
		}

		List(std::initializer_list<T> list) :
			_count(list.size()),
			_dataSize(list.size()),
			_data(new T[list.size()])
		{
			std::copy(list.begin(), list.end(), _data);
		}

		List(const List<T>& other) :
			_count(other._count),
			_dataSize(other._dataSize),
			_data(new T[other._dataSize])
		{
			std::copy(other._data, other._data + other._dataSize, _data);
		}

		List<T>& operator=(const List<T>& other)
		{
			List<T> copy(other);
			std::swap(*this, copy);
			return *this;
		}

		List(const List<T>&& other) :
			_count(other._count),
			_dataSize(other._dataSize),
			_data(other._data)
		{
			other._data = NULL;
		}

		List<T>& operator=(const List<T>&& other)
		{
			List<T> move(other);
			std::swap(*this, move);
			return *this;
		}

		~List()
		{
			if (_data)
			{
				delete[] _data;
				_data = NULL;
			}

			_dataSize = 0;
			_count = 0;
		}

		inline T& operator[](int index)
		{
			return _data[index];
		}

		inline void Add(T item)
		{
			if (_count >= _dataSize)
			{
				this->IncreaseCapacity();
			}

			_data[_count++] = item;
		}

		inline T Remove()
		{
			return _data[--_count];
		}

		inline int Count() const
		{
			return _count;
		}

		inline T First() const
		{
			return _data[0];
		}

		inline T Last() const
		{
			return _data[_count - 1];
		}

	private:
		void IncreaseCapacity()
		{
			T* newData = new T[_dataSize * 2];
			std::copy(_data, _data + _dataSize, newData);
			_dataSize = _dataSize * 2;
			delete[] _data;
			_data = newData;
		}

		T* _data;
		int _count;
		int _dataSize;
	};
}

