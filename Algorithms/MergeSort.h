#pragma once
#include <vector>

namespace Algorithms::Sort
{
	class MergeSort
	{
	public:
		void Sort(std::vector<int>& items);
	private:
		void Sort(std::vector<int>& items, int startIndex, int endIndex);
	};
}