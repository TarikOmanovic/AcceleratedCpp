#include "grade.h"
#include "median.h"


double
grade(
	double midterm,
	double finalGrade,
	double homework);



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


double grade(
	const Student_info& s)
{
	return grade(s.midterm, s.midterm, s.hw);
}
