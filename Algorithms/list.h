#pragma once
#include <algorithm>

namespace algorithms
{
	template <typename T>
	class list
	{
	public:
		list() :
			_count(0),
			_dataSize(16),
			_data(new T[16]) 
		{
		}

		explicit list(int reserveSize) :
			_count(0),
			_dataSize(reserveSize),
			_data(new T[reserveSize]) 
		{
		}

		list(T items[], int count) :
			_count(count),
			_dataSize(count),
			_data(new T[count])
		{
			std::copy(items, items + _count, _data);
		}

		list(std::initializer_list<T> list) :
			_count(list.size()),
			_dataSize(list.size()),
			_data(new T[list.size()])
		{
			std::copy(list.begin(), list.end(), _data);
		}

		list(const list<T>& other) :
			_count(other._count),
			_dataSize(other._dataSize),
			_data(new T[other._dataSize])
		{
			std::copy(other._data, other._data + other._dataSize, _data);
		}

		list<T>& operator=(const list<T>& other)
		{
			list<T>(other).swap(*this);
			return *this;
		}

		list(list<T>&& other) :
			_count(other._count),
			_dataSize(other._dataSize),
			_data(other._data)
		{
			other._count = 0;
			other._dataSize = 0;
			other._data = NULL;
		}

		list<T>& operator=(list<T>&& other)
		{
			list<T>(std::move(other)).swap(*this);
			return *this;
		}

		~list()
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

		inline void add(T item)
		{
			if (_count >= _dataSize)
			{
				this->increase_capacity();
			}

			_data[_count++] = item;
		}

		inline T remove()
		{
			return _data[--_count];
		}

		inline int count() const
		{
			return _count;
		}

		inline T first() const
		{
			return _data[0];
		}

		inline T last() const
		{
			return _data[_count - 1];
		}

	private:
		void increase_capacity()
		{
			T* newData = new T[_dataSize * 2];
			std::copy(_data, _data + _dataSize, newData);
			_dataSize = _dataSize * 2;
			delete[] _data;
			_data = newData;
		}

		void swap(list& that) noexcept {
			std::swap(_count, that._count);
			std::swap(_dataSize, that._dataSize);
			std::swap(_data, that._data);
		}

		T* _data;
		int _count;
		int _dataSize;
	};
}

