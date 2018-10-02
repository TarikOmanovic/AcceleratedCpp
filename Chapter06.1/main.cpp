#include <iostream>
#include <vector>
#include <algorithm>
#include "student_info.h"
#include "analysis.h"


bool
did_all_hw(
	const Student_info& s);


int
main()
{
	std::vector<Student_info> did, didnt;
	Student_info record;
	std::string::size_type maxlen = 0;

	while (read(std::cin, record))
	{
		if (did_all_hw(record))
		{
			did.push_back(record);
		}
		else
		{
			didnt.push_back(record);
		}
	}

	if (did.empty())
	{
		std::cout << "no student did hw" << std::endl;
		return 1;
	}
	if (didnt.empty())
	{
		std::cout << "every student did hw" << std::endl;
		return 1;
	}
	write_analysis(std::cout, "median", median_analysis, did, didnt);
	write_analysis(std::cout, "average", average_analysis, did, didnt);
	write_analysis(std::cout, "median HTI", optimistic_median_analysis, did, didnt);

	return 0;
}


bool
did_all_hw(
	const Student_info& s)
{
	return((std::find(s.hw.begin(), s.hw.end(), 0)) == (s.hw.end()));
}
