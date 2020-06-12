#pragma once
#include "List.h"

namespace Algorithms
{
	class MergeSort
	{
	public:
		void Sort(List<int>& items);
	private:
		void Sort(List<int>& items, int startIndex, int endIndex);
	};
}