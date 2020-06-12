#include <algorithm>
#include <stdexcept>
#include "BinaryHeap.h"

namespace Algorithms::DataStructures
{
	BinaryHeap::BinaryHeap()
	{

	}

	int BinaryHeap::Remove()
	{
		if (_tree.size() == 0)
		{
			throw std::out_of_range("No items to remove.");
		}
		else if (_tree.size() == 1)
		{
			int last = _tree.back();
			_tree.pop_back();
			return last;
		}
		else
		{
			int first = _tree.front();
			int last = _tree.back();
			_tree.pop_back();
			_tree[0] = last;

			Heapify(0);

			return first;
		}
	}

	void BinaryHeap::Insert(int item)
	{
		_tree.push_back(item);

		int index = _tree.size() - 1;
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
			this->Heapify(smallestIndex);
		}
	}
}