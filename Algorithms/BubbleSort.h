#pragma once
#include "list.h"

namespace Algorithms
{
	template <typename T>
	void BubbleSort(list<T>& items)
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
