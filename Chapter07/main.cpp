#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include "grammar.h"


#if 0
std::vector<std::string>
split(
	const std::string& str);

std::map<std::string, std::vector<int>>
xref(
	std::istream& in,
	std::vector<std::string> find_words(const std::string&) = split);

//int
//main()
//{
//	std::string s;
//	std::map<std::string, int> counters;
//
//	while (std::cin >> s)
//	{
//		++counters[s];
//	}
//
//	for (std::map<std::string, int>::const_iterator i = counters.begin(); i != counters.end(); ++i)
//	{
//		std::cout << i->first << "\t" << i->second << std::endl;
//	}
//
//	return 0;
//}


int
main()
{
	std::map<std::string, std::vector<int>> ret = xref(std::cin);

	for (std::map<std::string, std::vector<int>>::const_iterator it; it != ret.end(); ++it)
	{
		std::cout << it->first << "occurs in line: ";

		std::vector<int>::const_iterator line_it = it->second.begin();
		std::cout << *line_it;

		++line_it;

		while (line_it != it->second.end())
		{
			std::cout << ", " << *line_it;
		}
		std::cout << std::endl;
	}
	return 0;
}

#endif

int
main()
{
	test_grammar();
	return 0;
}


#if 0
bool
space(
	char c)
{
	return isspace(c);
}


bool
not_space(
	char c)
{
	return !isspace(c);
}


std::vector<std::string>
split(
	const std::string& str)
{
	typedef std::string::const_iterator iter;

	std::vector<std::string> ret;

	iter i = str.begin();

	while (i != str.end())
	{
		i = find_if(i, str.end(), not_space);

		iter j = find_if(i, str.end(), space);

		if (i != str.end())
		{
			ret.push_back(std::string(i, j));
		}
		i = j;
	}

	return ret;
}


std::map<std::string, std::vector<int>>
xref(
	std::istream& in,
	std::vector<std::string> find_words(const std::string&))
{
	std::string line;
	int line_number = 0;
	std::map<std::string, std::vector<int>> ret;

	while (std::getline(in, line))
	{
		++line_number;

		std::vector<std::string> words = find_words(line);

		for (std::vector<std::string>::const_iterator it = words.begin(); it != words.end(); ++it)
		{
			ret[*it].push_back(line_number);
		}
	}
	return ret;
}

#endif
