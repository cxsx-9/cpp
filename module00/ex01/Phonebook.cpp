
#include "Phonebook.hpp"

Phonebook::Phonebook(void)
{
	std::cout << "--- welcome ! ---\n";
	this->index = 0;
}

Phonebook::~Phonebook(void)
{
	std::cout << "--- goodbye ~ ---\n";
}

static std::string add_space(int size)
{
	std::string str;

	while (size--)
		str.append(" ");
	return (str);
}

static std::string	get_str(std::string str)
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

static bool is_num(std::string &str)
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

void	Phonebook::add(void)
{
	std::string	str;

	if (this->index >= 8)
		std::cout << "Warning!! Overwrite the contact of " << this->contacts[this->index % 8].get_fname() << "'s\n";
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Enter a first name	:> ";
		std::getline(std::cin, str);
		this->contacts[this->index % 8].set_fname(str);
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Enter a last name	:> ";
		std::getline(std::cin, str);
		this->contacts[this->index % 8].set_lname(str);
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Enter a nickname	:> ";
		std::getline(std::cin, str);
		this->contacts[this->index % 8].set_nname(str);
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Enter a phone number	:> ";
		std::getline(std::cin, str);
		if (is_num(str))
			this->contacts[this->index % 8].set_pnum(str);
		else
			str = "";
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Enter a darkest secret	:> ";
		std::getline(std::cin, str);
		this->contacts[this->index % 8].set_secret(str);
	}
	this->index += 1;
}

void	Phonebook::print(Contact contacts)
{
	if (contacts.get_fname().empty())
	{
		std::cout << "Nothing here.\n";
		return ;
	}
	std::cout << "\n[ "<< contacts.get_fname() << "'s Informatoin. ]\n";
	std::cout << "First name	: " << contacts.get_fname() << std::endl;
	std::cout << "Last name	: " << contacts.get_lname() << std::endl;
	std::cout << "Nickname	: " << contacts.get_nname() << std::endl;
	std::cout << "Phone number	: " << contacts.get_pnum() << std::endl;
	std::cout << "Darkest secret	: " << contacts.get_secret() << std::endl;
}

void	Phonebook::show_contact(Contact contacts[8])
{
	int i = 0;
	std::string	str;

	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;

	while (i < 8)
	{
		if (!contacts[i].get_fname().empty())
		{
			std::cout << "|";
			std::cout << add_space(10 - 1) << i + 1;
			std::cout << "|";
			std::cout << get_str(contacts[i].get_fname());
			std::cout << "|";
			std::cout << get_str(contacts[i].get_lname());
			std::cout << "|";
			std::cout << get_str(contacts[i].get_nname());
			std::cout << "|";
			std::cout << std::endl;
		}
		i++;
	}
	std::cout << "---------------------------------------------" << std::endl;
}

void	Phonebook::search(void)
{
	int i = 0;
	std::string input;

	if (contacts[i].get_fname().empty())
	{
		std::cout << "	:Phonebook is empty.\n";
		return ;
	}
	show_contact(this->contacts);
	std::cout << "Select your index > ";
	std::getline(std::cin, input);
	if (!std::cin.eof())
	{
		if (input.size() == 1 && (input[0] >= '1' && input[0] <= this->index + '0'))
			print(this->contacts[input[0] - '0' - 1]);
		else
			std::cout << "	:Invalid index";
		std::cout << std::endl;
	}
}
