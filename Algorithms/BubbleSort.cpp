#include <algorithm>
#include "BubbleSort.h"

namespace Algorithms::Sort
{
	void BubbleSort::Sort(std::vector<int>& items)
	{
		for (int i = 0; i < items.size(); i++)
		{
			for (int j = i + 1; j < items.size(); j++)
			{
				if (items[i] > items[j])
				{
					std::swap(items[i], items[j]);
				}
			}
		}
	}
}