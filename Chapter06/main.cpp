#include <iostream>
#include <algorithm>
#include <vector>

int
main()
{
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

bool
is_palindrome(
	const std::string& str)
{
	return(std::equal(str.begin(), str.end(), str.rbegin()));
}

std::string::const_iterator
url_beg(
	std::string::const_iterator b,
	std::string::const_iterator e);

std::string::const_iterator
url_end(
	std::string::const_iterator b,
	std::string::const_iterator e);


std::vector<std::string>
find_urls(
	const std::string& str)
{
	std::vector<std::string> ret;
	typedef std::string::const_iterator iter;

	iter b = str.begin();
	iter e = str.end();

	while (b != e)
	{
		b = url_beg(b, e);

		if (b != e)
		{
			iter after = url_end(b, e);
			
			ret.push_back(std::string(b, after));
			b = after;
		}
	}

	return ret;
}


bool
not_url_char(
	const char c)
{
	static const std::string url_ch = " ~;";
	return !(isalnum(c) || (std::find(url_ch.begin(), url_ch.end(), c) != url_ch.end()));
}



std::string::const_iterator
url_beg(
	std::string::const_iterator b,
	std::string::const_iterator e)
{
	static const std::string sep = "://";
	typedef std::string::const_iterator iter;

	iter i = b;

	while ((i = std::search(i, e, sep.begin(), sep.end())) != e)
	{
		if ((i != b) && (i + sep.size() != e))
		{
			iter beg = i;

			while (beg != b && isalpha(beg[-1]))
			{
				--beg;
			}
			if (beg != i && !not_url_char(i[sep.size()]))
			{
				return beg;
			}
		}
		i += sep.size();
	}
	return e;
}




std::string::const_iterator
url_end(
	std::string::const_iterator b,
	std::string::const_iterator e)
{
	return( std::find_if(b, e, not_url_char));
}