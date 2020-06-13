#pragma once
#include <memory>

namespace algorithms
{
	template <typename T>
	class linked_list
	{
	public:
		linked_list() {}

		/*inline void enqueue(T& item)
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
		}*/

		inline void push_back(const T& value)
		{
			if (_last)
			{
				// Point the last pointer to the new node.
				_last->next = std::make_shared<node>();
				_last->next->value = value;
				_last->next->previous = _last;
				_last = _last->next;
			}
			else
			{
				push_empty(value);
			}
		}

		inline void push_front(const T& value)
		{
			if (_first)
			{
				// Point the last pointer to the new node.
				_first->previous = std::make_shared<node>();
				_first->previous->value = value;
				_first->previous->previous = _first;
				_first = _first->previous;
			}
			else
			{
				push_empty(value);
			}
		}

		struct node
		{
			T value;
			std::shared_ptr<node> next;
			std::shared_ptr<node> previous;
		};

	private:
		inline void push_empty(const T& value)
		{
			// Handle the case that no nodes yet exist.
			_last = std::make_shared<node>();
			_first = _last;

			// Point the first and last pointers to themselves.
			_last->value = value;
			_last->next = _first;
			_last->previous = _first;
		}

		std::shared_ptr<node> _first;
		std::shared_ptr<node> _last;
	};
}
