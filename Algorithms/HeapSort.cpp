#include <algorithm>
#include "HeapSort.h"
#include "BinaryHeap.h"

namespace Algorithms::Sort
{
	void HeapSort::Sort(std::vector<int>& items)
	{
		Algorithms::DataStructures::BinaryHeap bh;
		for (auto& item : items)
		{
			bh.Insert(item);
		}

		for (int i = 0; i < items.size(); i++)
		{
			items[i] = bh.Remove();
		}
	}
}