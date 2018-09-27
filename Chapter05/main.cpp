#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <stdexcept>

#include "median.h"
#include "student_info.h"
#include "grade.h"

std::list<Student_info>
extractFails(
	std::list<Student_info>& students);

int
main()
{
	std::list<Student_info> students;
	Student_info record;
	std::string::size_type maxlen = 0;

	while (read(std::cin, record))
	{
		maxlen = std::max(maxlen, record.name.size());
		students.push_back(record);
	}

	students.sort(compare);

	std::list<Student_info> fails = extractFails(students);

	//for (std::vector<Student_info>::size_type i = 0; i != students.size(); ++i)
	for (std::list<Student_info>::const_iterator s = students.begin(); s != students.end(); ++s)
	{
		std::cout << s->name << std::string(maxlen + 1 - s->name.size(), ' ');

		try
		{
			double final_grade = grade(*s);
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


std::list<Student_info>
extractFails(
	std::list<Student_info>& students)
{
	std::list<Student_info> fails;
	std::list<Student_info>::iterator s = students.begin();

	while (s != students.end())
	{
		if (fgrade(*s))
		{
			fails.push_back(*s);
			s = students.erase(s);
		}
		else
		{
			++s;
		}
	}
	return fails;
}
