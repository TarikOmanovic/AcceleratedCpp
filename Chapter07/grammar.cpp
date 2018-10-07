#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <stdexcept>
#include "grammar.h"




typedef std::vector<std::string> Rule;
typedef std::vector<Rule> Rule_collection;
typedef std::map<std::string, Rule_collection> Grammar;

std::vector<std::string>
split(
	const std::string& str);

void
gen_aux(
	Grammar& gram,
	std::string key,
	std::vector<std::string>& words);


Grammar
read_grammar(
	std::istream& in)
{
	Grammar ret;
	std::string line;

	while (std::getline(in, line))
	{
		std::vector<std::string> entry = split(line);

		if (!entry.empty())
		{
			ret[entry[0]].push_back(Rule(entry.begin() + 1, entry.end()));
		}
	}
	return ret;
}

std::vector<std::string>
gen_sentence(
	Grammar& g)
{
	std::vector<std::string> sentence;

	gen_aux(g, "<sentence>", sentence);

	return sentence;
}

int
nrand(
	int n)
{
	const int bucket_size = RAND_MAX / n;
	int r;
	do
	{
		r = rand() / bucket_size;
	}
	while (r >= n);
	return r;
}

void
gen_aux(
	Grammar& gram,
	std::string key,
	std::vector<std::string>& words)
{
	int randNum = nrand((gram[key]).size());

	Rule rule = (gram[key])[randNum];

	for (auto r : rule)
	{
		if ((*r.begin() == '<') && (*(r.end()-1) == '>'))
		{
			gen_aux(gram, std::string(r.begin(), r.end()), words);
		}
		else
		{
			words.push_back(r);
		}
	}
}


void
test_grammar()
{
	Grammar grammar = read_grammar(std::cin);

	std::vector<std::string> sentence = gen_sentence(grammar);

	for (auto i : sentence)
		std::cout << i << " ";

	return;
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