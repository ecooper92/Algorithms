#include <algorithm>
#include "MergeSort.h"

namespace Algorithms
{
	void MergeSort::Sort(List<int>& items)
	{
		this->Sort(items, 0, items.Count() - 1);
	}

	void MergeSort::Sort(List<int>& items, int startIndex, int endIndex)
	{
		// Stop of there is one or fewer items between the indices.
		if (endIndex <= startIndex)
		{
			return;
		}

		// Split the items into two equally sized parts and sort those parts.
		int center = ((startIndex + endIndex) / 2) + 1;
		this->Sort(items, startIndex, center - 1);
		this->Sort(items, center, endIndex);

		// Merge the resultant parts back together
		int leftIndex = startIndex;
		int rightIndex = center;
		for (int i = startIndex; i <= endIndex; i++)
		{
			if (items[leftIndex] > items[rightIndex])
			{
				for (int j = i; j < rightIndex; j++)
				{
					std::swap(items[j], items[rightIndex]);
				}

				if (rightIndex < endIndex)
				{
					rightIndex++;
				}
			}

			leftIndex++;
		}
	}
}