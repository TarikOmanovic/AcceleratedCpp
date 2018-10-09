#include <vector>
#include <stdexcept>
#include <algorithm>

template<class T>
T median(std::vector<T> v)
{
	typedef typename std::vector<T>::size_type vec_size;

	vec_size size = v.size();

	if (size == 0)
	{
		//throw domain_error("median of empty vector");
	}

	std::sort(v.begin(), v.end());

	vec_size mid = size / 2;

	if (size % 2 == 0)
	{
		return (v[mid] + v[mid + 1]) / 2;
	}
	else
	{
		return v[mid];
	}
}


int
main()
{
	return 0;
}