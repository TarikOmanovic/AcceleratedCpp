#include <string>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <iostream>
#include <ostream>
#include <iterator>

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


template <class In, class X>
In find(
	In begin,
	In end,
	const X& x)
{
	while (begin != end && *begin != x)
	{
		++begin;
	}
	return begin;
}



template <class In, class Out>
Out Copy(
	In begin,
	In end,
	Out dest)
{
	while (begin != end)
	{
		*dest = *begin;
		++dest;
		++begin;
	}
	return dest;
}


template <class For, class X>
void
replace(
	For begin,
	For end,
	const X& x,
	const X& y)
{
	while (begin != end)
	{
		if (*begin == x)
		{
			*begin = y;
		}
		++begin;
	}
}


template <class Bi>
void
reverse(
	Bi begin,
	Bi end)
{
	while (begin != end)
	{
		--end;
		if (begin != end)
		{
			std::swap(*begin, *end);
			++begin;
		}
	}
}


template <class Ran, class X>
bool
binary_search(
	Ran begin,
	Ran end,
	const X& x)
{
	while (begin < end)
	{
		Ran mid = begin + ((end - begin) / 2);
		
		if (x < *mid)
		{
			end = mid;
		}
		else if (x > *mid)
		{
			begin = mid + 1;
		}
		else
		{
			return true;
		}
	}
	return false;
}

bool
space(
	char c)
{
	return isspace(c);
}

bool
not_space(
	char c)
{
	return !isspace(c);
}




template <class Out>
void
split(
	const std::string& str,
	Out os)
{
	typedef std::string::const_iterator iter;

	iter i = str.begin();

	while (i != str.end())
	{
		i = std::find_if(i, str.end(), not_space);
		iter j = std::find_if(i, str.end(), space);

		if (i != str.end())
		{
			*os = std::string(i, j);
			++os;
		}
		i = j;
	}
}








int
main()
{
	std::string s;
	while (getline(std::cin, s))
	{
		split(s, std::ostream_iterator<std::string>(std::cout, "\n"));
	}
	return 0;
}