#pragma once
#include "List.h"

namespace Algorithms
{
	template <typename T>
	void QuickSort(List<T>& items)
	{
		QuickSort(items, 0, items.Count() - 1);
	}

	template <typename T>
	void QuickSort(List<T>& items, int startIndex, int endIndex)
	{
		// Stop of there is one or fewer items between the indices.
		if (endIndex <= startIndex)
		{
			return;
		}

		// Starting with the first element as the pivot, arrange all items so the fall on the proper side of the pivot.
		int pivotIndex = startIndex + 1;
		int& pivot = items[startIndex];
		for (int i = startIndex + 1; i <= endIndex; i++)
		{
			if (items[i] < pivot)
			{
				std::swap(items[i], items[pivotIndex]);
				pivotIndex++;
			}
		}

		std::swap(pivot, items[pivotIndex - 1]);

		// Sort recusively sort both halves.
		QuickSort(items, startIndex, pivotIndex - 1);
		QuickSort(items, pivotIndex, endIndex);
	}
}