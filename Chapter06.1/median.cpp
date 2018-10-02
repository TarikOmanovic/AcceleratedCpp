#include <algorithm>

#include "median.h"

double
median(
	std::vector<double> vec)
{
	typedef std::vector<double>::size_type vec_sz;
	vec_sz size = vec.size();

	std::sort(vec.begin(), vec.end());

	vec_sz mid = size / 2;
	double median;
	if (size % 2 == 0)
	{
		median = (vec[mid] + vec[mid - 1]) / 2;
	}
	else
	{
		median = vec[mid];
	}
	return median;
}