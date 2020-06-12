#include <algorithm>
#include "BinaryHeap.h"

namespace Algorithms
{
	BinaryHeap::BinaryHeap()
	{

	}

	BinaryHeap::BinaryHeap(List<int> list) :
		_tree(list)
	{
		for (int i = _tree.Count() - 1; i >= 0; i--)
		{
			Heapify(i);
		}
	}

	int BinaryHeap::Remove()
	{
		if (_tree.Count() == 1)
		{
			return _tree.Remove();
		}
		else
		{
			int first = _tree.First();
			_tree[0] = _tree.Remove();

			Heapify(0);

			return first;
		}
	}

	void BinaryHeap::Insert(int item)
	{
		_tree.Add(item);

		int index = _tree.Count() - 1;
		int lastIndex = -1;
		while (index != lastIndex)
		{
			lastIndex = index;
			index = (index - 1) / 2;
			Heapify(index);
		}
	}

	void BinaryHeap::Heapify(int index)
	{
		if (index < 0 || index >= _tree.Count())
		{
			return;
		}

		int smallestIndex = index;

		int leftChildIndex = (index * 2) + 1;
		if (leftChildIndex < _tree.Count() && _tree[leftChildIndex] < _tree[smallestIndex])
		{
			smallestIndex = leftChildIndex;
		}

		int rightChildIndex = leftChildIndex + 1;
		if (rightChildIndex < _tree.Count() && _tree[rightChildIndex] < _tree[smallestIndex])
		{
			smallestIndex = rightChildIndex;
		}

		if (smallestIndex != index)
		{
			std::swap(_tree[smallestIndex], _tree[index]);
			this->Heapify(smallestIndex);
		}
	}
}