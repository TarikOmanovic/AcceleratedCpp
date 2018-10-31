#include <iostream>
#include <fstream>
#include <string>

int
next(
	int n)
{
	return n + 1;
}

int
main(
	int argc,
	char **argv)
{
	/*int (*fp)(int);

	fp = next;
	fp = &next;*/

	int i;
	for (i = 1; i < argc; ++i)
	{
		std::cout << argv[i] << std::endl;
	}

	std::ifstream infile(argv[1]);
	std::ofstream outfile(argv[2]);

	std::string s;

	while (std::getline(infile, s))
	{
		outfile << s << std::endl;
	}

	return 0;
}