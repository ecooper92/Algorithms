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
			_first_index(0),
			_last_index(-1),
			_size(0),
			_dataSize(16),
			_data(new T[16]) 
		{
		}

		explicit list(int reserveSize) noexcept :
			_first_index(0),
			_last_index(-1),
			_size(0),
			_dataSize(reserveSize),
			_data(new T[reserveSize]) 
		{
		}

		list(T items[], int size) noexcept :
			_first_index(0),
			_last_index(size - 1),
			_size(size),
			_dataSize(size),
			_data(new T[size])
		{
			std::copy(items, items + _size, _data);
		}

		list(std::initializer_list<T> list) noexcept :
			_first_index(0),
			_last_index(list.size() - 1),
			_size(list.size()),
			_dataSize(list.size()),
			_data(new T[list.size()])
		{
			std::copy(list.begin(), list.end(), _data);
		}

		list(const list<T>& other) noexcept :
			_first_index(other._first_index),
			_last_index(other._last_index),
			_size(other._size),
			_dataSize(other._dataSize),
			_data(new T[other._dataSize])
		{
			std::copy(other._data, other._data + other._dataSize, _data);
		}

		list(list<T>&& other) noexcept :
			_first_index(other._first_index),
			_last_index(other._last_index),
			_size(other._size),
			_dataSize(other._dataSize),
			_data(other._data)
		{
			other._size = 0;
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

			_first_index = 0;
			_last_index = -1;

			_size = 0;
			_dataSize = 0;
		}

		inline T& operator[](int index) noexcept
		{
			return _data[(_first_index + index) % _dataSize];
		}

		inline void push_back(const T& item) noexcept
		{
			if (_size >= _dataSize)
			{
				this->increase_capacity();
			}

			_last_index = (_last_index + 1) % _dataSize;
			_size++;

			_data[_last_index] = item;
		}

		/*inline void add(const T& item, int index) noexcept
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
		}*/

		inline T& pop_back() noexcept
		{
			if (_size > 0)
			{
				T& item = _data[_last_index--];
				if (_last_index < 0)
				{
					_last_index = _dataSize - 1;
				}

				_size--;
				return item;
			}
		}

		/*inline T& remove(int index) noexcept
		{
			T& item = _data[index];
			for (int i = index + 1; i < _count; i++)
			{
				_data[i - 1] = _data[i];
			}

			_count--;
			return item;
		}*/

		inline int size() const noexcept
		{
			return _size;
		}

		inline T& first() const noexcept
		{
			return _data[_first_index];
		}

		inline T& last() const noexcept
		{
			return _data[_last_index];
		}

	private:
		void increase_capacity() noexcept
		{
			int newDataSize = _dataSize * 2;
			T* newData = new T[newDataSize];
			for (int i = 0; i < _size; i++)
			{
				newData[i] = _data[(_first_index + i) % _dataSize];
			}

			_first_index = 0;
			_last_index = _size - 1;
			_dataSize = newDataSize;
			delete[] _data;
			_data = newData;
		}

		void swap(list& that) noexcept {
			std::swap(_size, that._size);
			std::swap(_first_index, that._first_index);
			std::swap(_last_index, that._last_index);
			std::swap(_dataSize, that._dataSize);
			std::swap(_data, that._data);
		}

		T* _data;
		int _dataSize;

		int _size;
		int _first_index;
		int _last_index;
	};
}

