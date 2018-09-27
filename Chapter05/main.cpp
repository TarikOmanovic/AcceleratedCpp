#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>

#include "median.h"
#include "student_info.h"
#include "grade.h"

std::vector<Student_info>
extractFails(
	std::vector<Student_info>& students);

int
main()
{
	std::vector<Student_info> students;
	Student_info record;
	std::string::size_type maxlen = 0;

	while (read(std::cin, record))
	{
		maxlen = std::max(maxlen, record.name.size());
		students.push_back(record);
	}

	std::sort(students.begin(), students.end(), compare);

	for (std::vector<Student_info>::size_type i = 0; i != students.size(); ++i)
	{
		std::cout << students[i].name
			<< std::string(maxlen + 1 - students[i].name.size(), ' ');

		try
		{
			double final_grade = grade(students[i]);
			std::cout << final_grade;
		}
		catch (std::domain_error e)
		{
			std::cout << e.what();
		}

		std::cout << std::endl;
	}

	return 0;
}


std::vector<Student_info>
extractFails(
	std::vector<Student_info>& students)
{
	std::vector<Student_info> fails;
	std::vector<Student_info>::size_type i = 0;

	while (i != students.size())
	{
		if (fgrade(students[i]))
		{
			fails.push_back(students[i]);
			students.erase(students.begin() + i);
		}
		else
		{
			++i;
		}
	}
	return fails;
}