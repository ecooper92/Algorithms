#pragma once
#include "list.h"
#include "binary_heap.h"

namespace Algorithms
{
	template <typename T>
	void HeapSort(list<T>& items)
	{
		binary_heap bh(items);
		for (int i = 0; i < items.count(); i++)
		{
			items[i] = bh.remove();
		}
	}
}
