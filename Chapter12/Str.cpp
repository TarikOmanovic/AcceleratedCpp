#include "Str.h"
#include <iostream>

std::ostream & operator<<(std::ostream& Out, const Str& s)
{
	for (Str::size_type i = 0; i < s.size(); ++i)
	{
		Out << s[i];
	}
	return Out;
}

std::istream& operator>> (std::istream& In, Str& s)
{
	//s.data.clear();

	char c;
	while (In.get(c) && isspace(c));

	if (In)
	{
		do 
		{
			s.data.push_back(c);
		}
		while(In.get(c) && !isspace(c));

		if (In)
		{
			In.unget();
		}
	}
	return In;
}

Str operator+ (const Str& s1, const Str& s2)
{
	return Str();
}
