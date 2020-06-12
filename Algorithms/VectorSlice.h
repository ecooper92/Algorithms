#pragma once

#include <vector>

namespace Algorithms
{
	class VectorSlice
	{
	public:
		VectorSlice(std::vector<int>& vector, int start, int end);
		const int operator[](int index);
	private:
		const int _start;
		const int _end;
		std::vector<int>& _vector;
	};
}

