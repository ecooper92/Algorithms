#pragma once
#include <utility>
#include <algorithm>

namespace algorithms
{
	template <typename T>
	class list
	{
	public:
		list() noexcept :
			_count(0),
			_dataSize(16),
			_data(new T[16]) 
		{
		}

		explicit list(int reserveSize) noexcept :
			_count(0),
			_dataSize(reserveSize),
			_data(new T[reserveSize]) 
		{
		}

		list(T items[], int count) noexcept :
			_count(count),
			_dataSize(count),
			_data(new T[count])
		{
			std::copy(items, items + _count, _data);
		}

		list(std::initializer_list<T> list) noexcept :
			_count(list.size()),
			_dataSize(list.size()),
			_data(new T[list.size()])
		{
			std::copy(list.begin(), list.end(), _data);
		}

		list(const list<T>& other) noexcept :
			_count(other._count),
			_dataSize(other._dataSize),
			_data(new T[other._dataSize])
		{
			std::copy(other._data, other._data + other._dataSize, _data);
		}

		list(list<T>&& other) noexcept :
			_count(other._count),
			_dataSize(other._dataSize),
			_data(other._data)
		{
			other._count = 0;
			other._dataSize = 0;
			other._data = NULL;
		}

		list<T>& operator=(const list<T>& other) noexcept
		{
			list<T>(other).swap(*this);
			return *this;
		}

		list<T>& operator=(list<T>&& other) noexcept
		{
			list<T>(std::move(other)).swap(*this);
			return *this;
		}

		~list() noexcept
		{
			if (_data)
			{
				delete[] _data;
				_data = NULL;
			}

			_dataSize = 0;
			_count = 0;
		}

		inline T& operator[](int index) noexcept
		{
			return _data[index];
		}

		inline void add(const T& item) noexcept
		{
			if (_count >= _dataSize)
			{
				this->increase_capacity();
			}

			_data[_count++] = item;
		}

		inline void add(const T& item, int index) noexcept
		{
			if (_count >= _dataSize)
			{
				this->increase_capacity();
			}
			
			for (int i = count++; i > index; i--)
			{
				_data[i] = _data[i - 1];
			}

			_data[index] = item;
		}

		inline T& remove() noexcept
		{
			return _data[--_count];
		}

		inline T& remove(int index) noexcept
		{
			T item = _data[index];
			for (int i = index + 1; i < _count; i++)
			{
				_data[i - 1] = _data[i];
			}

			_count--;
			return item;
		}

		inline int count() const noexcept
		{
			return _count;
		}

		inline T& first() const noexcept
		{
			return _data[0];
		}

		inline T& last() const noexcept
		{
			return _data[_count - 1];
		}

	private:
		void increase_capacity() noexcept
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

