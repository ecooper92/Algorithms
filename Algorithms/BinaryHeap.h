#pragma once
#include "List.h"

namespace Algorithms
{
	class BinaryHeap
	{
	public:
		BinaryHeap();
		BinaryHeap(List<int> list);
		void Insert(int item);
		int Remove();
	private:
		void Heapify(int index);
		List<int> _tree;
	};
}

