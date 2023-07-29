#include <iostream>

char	to_upper(char c)
{
	if (c <= 'z' && c >= 'a')
		return (c + 'A' - 'a');
	return (c);
}

int main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	else
	{
		for (int i = 1; i < ac; i++)
			for (int j = 0; av[i][j]; j++)
				std::cout << to_upper(av[i][j]);
		std::cout << std::endl;
	}
	return (0);
}