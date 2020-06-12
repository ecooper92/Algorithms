#pragma once
#include <vector>
#include <compare>
#include <algorithm>
#include <functional>

namespace Algorithms::DataStructures
{
	class BinaryHeap
	{
	public:
		BinaryHeap();
		void Insert(int item);
		int Remove();
	private:
		void Heapify(int index);
		std::vector<int> _tree;
	};
}

