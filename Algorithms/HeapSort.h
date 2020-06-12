#pragma once
#include "List.h"
#include "BinaryHeap.h"

namespace Algorithms
{
	template <typename T>
	void HeapSort(List<T>& items)
	{
		BinaryHeap bh(items);
		for (int i = 0; i < items.Count(); i++)
		{
			items[i] = bh.Remove();
		}
	}
}
