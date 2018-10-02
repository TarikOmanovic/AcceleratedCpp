#pragma once

#include <string>
#include <vector>


struct Student_info
{
	std::string name;
	double midterm;
	double final;
	std::vector<double> hw;
};


std::istream&
readHw(
	std::istream& in,
	std::vector<double>& hw);


std::istream&
read(
	std::istream& in,
	Student_info& s);

bool
compare(
	const Student_info& x,
	const Student_info& y);

