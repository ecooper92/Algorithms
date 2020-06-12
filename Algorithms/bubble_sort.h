#pragma once
#include "list.h"

namespace Algorithms
{
	template <typename T>
	void bubble_sort(list<T>& items)
	{
		for (int i = 0; i < items.count(); i++)
		{
			for (int j = i + 1; j < items.count(); j++)
			{
				if (items[i] > items[j])
				{
					std::swap(items[i], items[j]);
				}
			}
		}
	}
}