#pragma once
#include "list.h"
#include "BinaryHeap.h"

namespace Algorithms
{
	template <typename T>
	void HeapSort(list<T>& items)
	{
		BinaryHeap bh(items);
		for (int i = 0; i < items.Count(); i++)
		{
			items[i] = bh.Remove();
		}
	}
}
