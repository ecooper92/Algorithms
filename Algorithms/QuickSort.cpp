#include <algorithm>
#include "QuickSort.h"

namespace Algorithms
{
	void QuickSort::Sort(List<int>& items)
	{
		this->Sort(items, 0, items.Count() - 1);
	}

	void QuickSort::Sort(List<int>& items, int startIndex, int endIndex)
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
		this->Sort(items, startIndex, pivotIndex - 1);
		this->Sort(items, pivotIndex, endIndex);
	}
}