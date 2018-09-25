#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

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

	std::cout << "Enter your hw grades, followed by eol: ";

	std::vector<double> hw;
	double temp;

	while (std::cin >> temp)
	{
		hw.push_back(temp);
	}

	typedef std::vector<double>::size_type vec_sz;
	vec_sz size = hw.size();

	if (size == 0)
	{
		std::cout << "0 hw";
		return 1;
	}
	std::sort(hw.begin(), hw.end());

	vec_sz mid = size / 2;
	double median;
	if (size % 2 == 0)
	{
		median = (hw[mid] + hw[mid - 1]) / 2;
	}
	else
	{
		median = hw[mid];
	}
	std::streamsize prec = std::cout.precision();

	std::cout << "your final grade is " << std::setprecision(5)
		<< 0.2 * midterm + 0.4 * final + 0.4 * median
		<< std::setprecision(prec) << std::endl;

	return 0;
}