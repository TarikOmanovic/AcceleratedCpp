#include <iostream>
#include "student_info.h"
#include <vector>
#include <algorithm>
#include <string>
#include <stdexcept>

int
main()
{
	std::vector<Student_info> students;
	Student_info record;
	std::string::size_type maxlen = 0;

	while (record.read(std::cin))
	{
		maxlen = std::max(maxlen, record.getName().size());
		students.push_back(record);
	}

	std::sort(students.begin(), students.end(), compare);

	for (std::vector<Student_info>::size_type i = 0; i != students.size(); ++i)
	{
		std::cout << students[i].getName() << std::string(maxlen + 1 - students[i].getName().size(), ' ');

		try
		{
			double final_grade = students[i].grade();
			std::cout << final_grade << std::endl;
		}
		catch (std::domain_error e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	return 0;
}