#pragma once

#include <vector>
#include <istream>


class Student_info
{
public:

	Student_info();
	Student_info(std::istream& in);


	bool valid() const;
	std::istream& read(std::istream&);
	double grade() const;
	std::string getName() const;

private:

	std::string name;
	double midterm;
	double final;
	std::vector<double> homework;

};

bool
compare(
	const Student_info& x,
	const Student_info& y);