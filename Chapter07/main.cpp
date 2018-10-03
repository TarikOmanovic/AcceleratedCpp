#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

std::map<std::string, std::vector<int>>
xref(
	std::istream& in,
	std::vector<std::string> find_words(const std::string&) = split);

int
main()
{
	std::string s;
	std::map<std::string, int> counters;

	while (std::cin >> s)
	{
		++counters[s];
	}

	for (std::map<std::string, int>::const_iterator i = counters.begin(); i != counters.end(); ++i)
	{
		std::cout << i->first << "\t" << i->second << std::endl;
	}

	return 0;
}


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
	std::vector<std::string> find_words(const std::string&) = split)
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