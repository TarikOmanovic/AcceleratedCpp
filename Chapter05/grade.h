#pragma once

#include <vector>
#include "student_info.h"


double
grade(
	double midterm,
	double finalGrade,
	const std::vector<double>& hw);

double
grade(
	const Student_info& s);


bool
fgrade(
	const Student_info& s);