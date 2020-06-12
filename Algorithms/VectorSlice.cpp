#include "VectorSlice.h"
#include <stdexcept>

namespace Algorithms
{
	VectorSlice::VectorSlice(const std::vector<int>& vector, int start, int end) :
		_vector(vector),
		_start(start),
		_end(end)
	{
		if (_vector.size() <= 0)
		{
			throw std::out_of_range("Vector must contain greater than zero items");
		}
		else if (start < 0 || start > _vector.size())
		{
			throw std::out_of_range("Start must be between 0 and " + _vector.size());
		}
		else if (end < 0 || end > _vector.size())
		{
			throw std::out_of_range("End must be between 0 and " + _vector.size());
		}
		else if (end < start)
		{
			throw std::out_of_range("End must not be less than start");
		}
	}

	const int VectorSlice::operator[](int index)
	{
		int max = _end - _start;
		if (index < 0 || index > max)
		{
			throw std::out_of_range("Index must be between 0 and " + max);
		}

		return _vector[_start + index];
	}
}