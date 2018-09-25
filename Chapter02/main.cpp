#include <iostream>
#include <string>

int
main()
{
	std::cout << "Enter your first name: ";

	std::string name;
	std::cin >> name;
	const std::string greeting = "Hello, " + name + "!";
	std::cout << std::endl;

	const int pad = 5;
	const int rows = 3 + 2 * pad;

	for (int r = 0; r < rows; ++r)
	{
		const std::string::size_type cols = greeting.size() + pad * 2 + 2;
		std::string::size_type c = 0;

		while (c != cols)
		{
			if (r == pad + 1 && c == pad + 1)
			{
				std::cout << greeting;
				c += greeting.size();
			}
			else if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1)
			{
				std::cout << '*';
				++c;
			}
			else
			{
				std::cout << " ";
				++c;
			}
		}
		std::cout << std::endl;

	}

	return 0;
}