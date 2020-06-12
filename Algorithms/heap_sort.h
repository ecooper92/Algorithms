#pragma once
#include "list.h"
#include "binary_heap.h"

namespace algorithms
{
	template <typename T>
	void heap_sort(list<T>& items)
	{
		binary_heap bh(items);
		for (int i = 0; i < items.count(); i++)
		{
			items[i] = bh.remove();
		}
	}
}
