#include "student_info.h"
#include <string>
#include <algorithm>



/*************************************************************/
template<class T>
T median(std::vector<T> v)
{
	typedef typename std::vector<T>::size_type vec_size;

	vec_size size = v.size();

	if (size == 0)
	{
		//throw domain_error("median of empty vector");
	}

	sort(v.begin(), v.end());

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

double
grade(
	double midterm,
	double finalGrade,
	double homework)
{
	return 0.2 * midterm + 0.4 * finalGrade + 0.4 * homework;
}

double grade(
	double midterm,
	double finalGrade,
	const std::vector<double>& hw)
{
	if (hw.size() == 0)
	{
		throw std::domain_error("null hw vector");
	}
	return grade(midterm, finalGrade, median(hw));
}

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

bool
compare(
	const Student_info& x,
	const Student_info& y)
{
	return x.getName() < y.getName();
}
/*************************************************************/


std::string Student_info::getName() const { return name; }




std::istream&
Student_info::read(
	std::istream& in)
{
	in >> name >> midterm >> final;
	readHw(in, homework);
	return in;
}

double
Student_info::grade() const
{
	return ::grade(midterm, final, homework);
}

Student_info::Student_info() : midterm(0.0), final(0.0) {}


Student_info::Student_info(std::istream & in)
{
	read(in);
}

bool
Student_info::valid() const
{
	return !homework.empty();
}
