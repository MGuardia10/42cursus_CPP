#include <iostream>

int main(int argc, char **argv)
{
	std::string str;

	if (argc == 1)
		str = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int i = 1; argv[i]; i++) {
			for (int j = 0; argv[i][j]; j++) {
				str.push_back(toupper(argv[i][j]));
			}
		}
	}
	std::cout << str << std::endl;
	return 0;
}
