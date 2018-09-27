#include "student_info.h"

#include <iostream>

std::istream&
readHw(
	std::istream&        in,
	std::vector<double>& hw)
{
	if (in)
	{
		hw.clear();

		double temp;
		while (in >> temp)
		{
			hw.push_back(temp);
		}
		in.clear();
	}
	return in;
}

std::istream&
read(
	std::istream& in,
	Student_info& s)
{
	in >> s.name >> s.midterm >> s.final;
	readHw(in, s.hw);

	return in;
}


bool
compare(
	const Student_info& x,
	const Student_info& y)
{
	return x.name < y.name;
}