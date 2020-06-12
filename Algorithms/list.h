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
			_data_size(16),
			_data(new T[16]) 
		{
		}

		explicit list(int reserveSize) noexcept :
			_first_index(0),
			_last_index(-1),
			_size(0),
			_data_size(reserveSize),
			_data(new T[reserveSize]) 
		{
		}

		list(T items[], int size) noexcept :
			_first_index(0),
			_last_index(size - 1),
			_size(size),
			_data_size(size),
			_data(new T[size])
		{
			std::copy(items, items + _size, _data);
		}

		list(std::initializer_list<T> list) noexcept :
			_first_index(0),
			_last_index(list.size() - 1),
			_size(list.size()),
			_data_size(list.size()),
			_data(new T[list.size()])
		{
			std::copy(list.begin(), list.end(), _data);
		}

		list(const list<T>& other) noexcept :
			_first_index(other._first_index),
			_last_index(other._last_index),
			_size(other._size),
			_data_size(other._data_size),
			_data(new T[other._data_size])
		{
			std::copy(other._data, other._data + other._data_size, _data);
		}

		list(list<T>&& other) noexcept :
			_first_index(other._first_index),
			_last_index(other._last_index),
			_size(other._size),
			_data_size(other._data_size),
			_data(other._data)
		{
			other._size = 0;
			other._data_size = 0;
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
			_data_size = 0;
		}

		inline T& operator[](int index) noexcept
		{
			return _data[(_first_index + index) % _data_size];
		}
		
		inline void push_front(const T& item) noexcept
		{
			if (_size >= _data_size)
			{
				this->increase_capacity();
			}

			_size++;
			_first_index--;
			if (_first_index < 0)
			{
				_first_index = _data_size - 1;
			}

			_data[_first_index] = item;
		}

		inline void push_back(const T& item) noexcept
		{
			if (_size >= _data_size)
			{
				this->increase_capacity();
			}

			_last_index = (_last_index + 1) % _data_size;
			_size++;

			_data[_last_index] = item;
		}

		inline T& pop_front() noexcept
		{
			if (_size > 0)
			{
				_size--;
				T& item = _data[_first_index];
				_first_index = (_first_index + 1) % _data_size;

				return item;
			}
		}

		inline T& pop_back() noexcept
		{
			if (_size > 0)
			{
				_size--;
				T& item = _data[_last_index--];
				if (_last_index < 0)
				{
					_last_index = _data_size - 1;
				}

				return item;
			}
		}

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
			int newDataSize = _data_size * 2;
			T* newData = new T[newDataSize];
			for (int i = 0; i < _size; i++)
			{
				newData[i] = _data[(_first_index + i) % _data_size];
			}

			_first_index = 0;
			_last_index = _size - 1;
			_data_size = newDataSize;
			delete[] _data;
			_data = newData;
		}

		void swap(list& that) noexcept {
			std::swap(_size, that._size);
			std::swap(_first_index, that._first_index);
			std::swap(_last_index, that._last_index);
			std::swap(_data_size, that._data_size);
			std::swap(_data, that._data);
		}

		T* _data;
		int _data_size;

		int _size;
		int _first_index;
		int _last_index;
	};
}

