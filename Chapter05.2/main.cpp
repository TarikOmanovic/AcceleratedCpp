#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::vector<std::string>
frame(
	const std::vector<std::string>& input);

std::string::size_type
width(
	const std::vector<std::string>& vec);

std::vector<std::string>
split(
	const std::string& str);

std::vector<std::string>
vcat(
	const std::vector<std::string>& top,
	const std::vector<std::string>& bot);

std::vector<std::string>
hcat(
	const std::vector<std::string>& left,
	const std::vector<std::string>& right);


int
main()
{
	std::string s, ss;
	std::getline(std::cin, s);
	std::getline(std::cin, ss);

	std::vector<std::string> out;
	std::vector<std::string> out1 = frame(split(s));
	std::vector<std::string> out2 = frame(split(ss));

	out = hcat(out1, out2);

	for (auto s : out)
	{
		std::cout << s << std::endl;
	}

	return 0;
}


std::string::size_type
width(
	const std::vector<std::string>& vec)
{
	std::string::size_type size = 0;
	for (std::string s : vec)
	{
		size = std::max(s.size(), size);
	}

	return size;
}

std::vector<std::string>
frame(
	const std::vector<std::string>& input)
{
	std::vector<std::string> ret;
	std::string::size_type maxlen = width(input);

	std::string border(maxlen + 4, '*');
	ret.push_back(border);

	for (std::string s : input)
	{
		ret.push_back("* " + s + std::string((maxlen - s.size()), ' ') + " *");
	}
	ret.push_back(border);

	return ret;
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


std::vector<std::string>
vcat(
	const std::vector<std::string>& top,
	const std::vector<std::string>& bot)
{
	std::vector<std::string> ret = top;

	ret.insert(ret.end(), bot.begin(), bot.end());
	return ret;
}


std::vector<std::string>
hcat(
	const std::vector<std::string>& left,
	const std::vector<std::string>& right)
{
	std::vector<std::string> out;

	std::string::size_type widthL = width(left);

	std::vector<std::string>::size_type i = 0;
	std::vector<std::string>::size_type j = 0;

	while (i != left.size() || j != right.size())
	{
		std::string s;

		if (i != left.size())
		{
			s = left[i];
			++i;
		}
		s += std::string(widthL - s.size(), ' ');
		
		if (j != right.size())
		{
			s += right[j];
			++j;
		}

		out.push_back(s);
	}
	return out;
}