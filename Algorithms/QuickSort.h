#pragma once
#include <vector>

namespace Algorithms::Sort
{
	class QuickSort
	{
	public:
		void Sort(std::vector<int>& items);
	private:
		void Sort(std::vector<int>& items, int startIndex, int endIndex);
	};
}