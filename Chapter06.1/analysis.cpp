#include "analysis.h"
#include "grade.h"
#include "median.h"
#include <stdexcept>
#include <algorithm>
#include <numeric>

double
grade_aux(
	Student_info s)
{
	try
	{
		return grade(s);
	}
	catch (std::domain_error e)
	{
		return(grade(s.midterm, s.final, 0.0));
	}
}

void
write_analysis(
	std::ostream& out,
	const std::string& name,
	double analysis(const std::vector<Student_info>&),
	const std::vector<Student_info>& did,
	const std::vector<Student_info>& didnt)
{
	out << name << ": median(did) = " << analysis(did) << ", median(didnt) = " << analysis(didnt) << std::endl;
	return;
}


double
median_analysis(
	const std::vector<Student_info>& students)
{
	std::vector<double> grades;

	std::transform(students.begin(), students.end(), back_inserter(grades), grade_aux);

	return median(grades);
}

double
average_analysis(
	const std::vector<Student_info>& students)
{
	std::vector<double> grades;

	std::transform(students.begin(), students.end(), back_inserter(grades), grade_aux);

	return std::accumulate(grades.begin(), grades.end(), 0.0) / grades.size();
}

double
optimistic_median_analysis(
	const std::vector<Student_info>& students)
{
	std::vector<double> grades;

	std::transform(students.begin(), students.end(), back_inserter(grades), grade_aux);

	return optim_median(grades);
}



