#include <iostream>
#include <vector>
#include <string>



std::vector<std::string>
split(
	const std::string& str);


int
main()
{
	std::string s;

	while (std::getline(std::cin, s))
	{
		std::vector<std::string> words = split(s);

		for (std::string str : words)
		{
			std::cout << str << std::endl;
		}
	}
}
	


std::vector<std::string>
split(
	const std::string& str)
{
	std::vector<std::string> words;
	typedef std::string::size_type str_size;

	str_size i = 0;

	while (i != str.size())
	{
		while (i != str.size() && isspace(str[i]))
		{
			++i;
		}

		str_size j = i;

		while (j != str.size() && !isspace(str[j]))
		{

			++j;
		}

		if (i != j)
		{
			words.push_back(str.substr(i, j - i));
			i = j;
		}
	}
	return words;
}