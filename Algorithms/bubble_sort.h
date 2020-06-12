#pragma once
#include "list.h"

namespace algorithms
{
	template <typename T>
	void bubble_sort(list<T>& items)
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
