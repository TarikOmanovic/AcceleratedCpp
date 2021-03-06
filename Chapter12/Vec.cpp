#include "Vec.h"


template<class T>
void Vec<T>::push_back(T & val)
{
	if (avail == limit)
	{
		grow();
	}
	unchecked_append(val);
}


template <class T>
void Vec<T>::create()
{
	data = avail = limit = 0;
}


template <class T>
void Vec<T>::create(size_type n, const T& val)
{
	data = alloc.allocate(n);
	limit = avail = data + n;
	std::uninitialized_fill(data, limit, val);
}


template <class T>
void Vec<T>::create(const_iterator b, const_iterator e)
{
	data = alloc.allocate(e - b);
	limit = avail = std::uninitialized_copy(b, e, data);
}


template <class T>
void Vec<T>::uncreate()
{
	if (data)
	{
		iterator it = avail;
		while (it != data)
		{
			--avail;
			alloc.destroy(data);
		}
		alloc.deallocate(data, limit - data);
	}
	data = avail = limit = 0;
}


template <class T>
void Vec<T>::grow()
{
	size_type new_size = max(2 * (limit - data), ptrdiff_t(1));
	iterator new_data = alloc.allocate(new_size);
	iterator new_avail = std::uninitialized_copy(data, avail, new_data);

	uncreate();

	data = new_data;
	avail = new_avail;
	limit = data + new_size;
}


template<class T>
void Vec<T>::unchecked_append(const T& val)
{
	alloc.construct(avail, val);
	++avail;
}
