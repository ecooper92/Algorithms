#pragma once
#include "list.h"

namespace Algorithms
{
	template <typename T>
	class binary_heap
	{
	public:
		binary_heap() {}
		binary_heap(list<T> list) :
			_tree(list)
		{
			for (int i = _tree.count() - 1; i >= 0; i--)
			{
				heapify(i);
			}
		}

		void insert(T item)
		{
			_tree.add(item);

			int index = _tree.Count() - 1;
			int lastIndex = -1;
			while (index != lastIndex)
			{
				lastIndex = index;
				index = (index - 1) / 2;
				heapify(index);
			}
		}

		int remove()
		{
			if (_tree.count() == 1)
			{
				return _tree.remove();
			}
			else
			{
				int first = _tree.first();
				_tree[0] = _tree.remove();

				heapify(0);

				return first;
			}
		}
	private:
		void heapify(int index)
		{
			if (index < 0 || index >= _tree.count())
			{
				return;
			}

			int smallestIndex = index;

			int leftChildIndex = (index * 2) + 1;
			if (leftChildIndex < _tree.count() && _tree[leftChildIndex] < _tree[smallestIndex])
			{
				smallestIndex = leftChildIndex;
			}

			int rightChildIndex = leftChildIndex + 1;
			if (rightChildIndex < _tree.count() && _tree[rightChildIndex] < _tree[smallestIndex])
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
