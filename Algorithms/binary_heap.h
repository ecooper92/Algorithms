#pragma once
#include "list.h"

namespace algorithms
{
	template <typename T>
	class binary_heap
	{
	public:
		binary_heap() {}
		binary_heap(const list<T>& list) :
			_tree(list)
		{
			for (int i = _tree.size() - 1; i >= 0; i--)
			{
				heapify(i);
			}
		}

		void insert(const T& item)
		{
			_tree.push_back(item);

			int index = _tree.size() - 1;
			int lastIndex = -1;
			while (index != lastIndex)
			{
				lastIndex = index;
				index = (index - 1) / 2;
				heapify(index);
			}
		}

		T& remove()
		{
			if (_tree.size() == 1)
			{
				return _tree.pop_back();
			}
			else
			{
				int first = _tree.first();
				_tree[0] = _tree.pop_back();

				heapify(0);

				return first;
			}
		}
	private:
		void heapify(int index)
		{
			if (index < 0 || index >= _tree.size())
			{
				return;
			}

			int smallestIndex = index;

			int leftChildIndex = (index * 2) + 1;
			if (leftChildIndex < _tree.size() && _tree[leftChildIndex] < _tree[smallestIndex])
			{
				smallestIndex = leftChildIndex;
			}

			int rightChildIndex = leftChildIndex + 1;
			if (rightChildIndex < _tree.size() && _tree[rightChildIndex] < _tree[smallestIndex])
			{
				smallestIndex = rightChildIndex;
			}

			if (smallestIndex != index)
			{
				std::swap(_tree[smallestIndex], _tree[index]);
				this->heapify(smallestIndex);
			}
		}

		list<T> _tree;
	};
}

