#include "Phonebook_util.hpp"

std::string add_space(int size)
{
	std::string str;

	while (size--)
		str.append(" ");
	return (str);
}

std::string	get_str(std::string str)
{
	int size = str.size();
	if (size > 10)
	{
		str.resize(9);
		str.append(".");
	}
	else
		str.insert(0, add_space(10 - size));
	return(str);
}

bool is_num(std::string &str)
{
	int i = 0;

	if (!str[i])
		return(false);
	while (str[i])
	{
		if (str[i] > '9' || str[i] < '0')
		{
			std::cout << "	:the phone number should be digit." << std::endl;
			return (false);
		}
		i++;
	}
	return (true);
}
