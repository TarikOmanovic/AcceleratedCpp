#include "Vec.h"


template <class T> void Vec<T>::create()
{
	data = avail = limit = 0;
}

template <class T> void Vec<T>::create(size_type n, const T& val)
{
	data = alloc.allocate(n);
	limit = avail = data + n;
	std::uninitialized_fill(data, limit, val);
}

template <class T> void Vec<T>::create(const_iterator b, const_iterator e)
{
	data = alloc.allocate(e - b);
	limit = avail = std::uninitialized_copy(b, e, data);
}

template <class T> void void Vec<T>::uncreate()
{

}