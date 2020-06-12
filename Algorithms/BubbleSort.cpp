#include <algorithm>
#include "BubbleSort.h"

namespace Algorithms
{
	void BubbleSort::Sort(List<int>& items)
	{
		for (int i = 0; i < items.Count(); i++)
		{
			for (int j = i + 1; j < items.Count(); j++)
			{
				if (items[i] > items[j])
				{
					std::swap(items[i], items[j]);
				}
			}
		}
	}
}