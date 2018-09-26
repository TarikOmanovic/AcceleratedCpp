#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>


double
grade(
	double midterm,
	double finalGrade,
	double homework);


double
median(
	std::vector<double> vec);


double grade(
	double midterm,
	double finalGrade,
	const std::vector<double>& hw);


std::istream&
readHw(
	std::istream& in,
	std::vector<double>& hw);


int
main()
{
	std::cout << "Enter name: ";
	std::string name;
	std::cin >> name;
	std::cout << "Hello " << name << "!" << std::endl;

	std::cout << "Enter midterm and final grades: ";
	double midterm;
	double final;
	std::cin >> midterm >> final;

	std::vector<double> hw;
	readHw(std::cin, hw);
	
	try
	{
		double finalGrade = grade(midterm, final, hw);
		std::streamsize prec = std::cout.precision();
		std::cout << "your final grade is " << std::setprecision(5)
			<< finalGrade << std::setprecision(prec) << std::endl;
	}
	catch (std::domain_error)
	{
		std::cout << "enter your grades next time!" << std::endl;
		return 1;
	}
	

	return 0;
}


double
grade(
	double midterm,
	double finalGrade,
	double homework)
{
	return 0.2 * midterm + 0.4 * finalGrade + 0.4 * homework;
}

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
	std::istream& in,
	std::vector<double>& hw)
{
	std::cout << "Enter your hw grades, followed by eol: ";

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