#pragma once

#include <vector>
#include <istream>


class Student_info
{
public:

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