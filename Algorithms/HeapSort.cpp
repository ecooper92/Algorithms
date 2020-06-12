#include "HeapSort.h"
#include "BinaryHeap.h"

namespace Algorithms
{
	void HeapSort::Sort(List<int>& items)
	{
		BinaryHeap bh(items);
		for (int i = 0; i < items.Count(); i++)
		{
			items[i] = bh.Remove();
		}
	}
}