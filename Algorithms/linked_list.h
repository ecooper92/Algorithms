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

		inline int size()
		{
			if (!_first)
			{
				return 0;
			}

			int count = 0;
			std::shared_ptr<node>& next_node = _first;
			do
			{
				count++;
				next_node = next_node->next;
			} while (next_node != _first);

			return count;
		}

		inline bool empty()
		{
			return !_first;
		}

		inline void push_back(const T& value)
		{
			if (_last)
			{
				// Point the last pointer to the new node.
				std::shared_ptr<node> previous = _last;
				_last = std::make_shared<node>();
				_last->value = value;
				_last->previous = previous;
				_last->next = _first;
				previous->next = _last;
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
