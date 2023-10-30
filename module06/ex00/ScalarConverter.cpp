#include "ScalarConverter.hpp"

std::string	ScalarConverter::_value = "";
int	ScalarConverter::_type = TYPE_EMPTY;
int	ScalarConverter::_prec = 0;
int	ScalarConverter::_intValue = 0;
char	ScalarConverter::_charValue = 0;
float	ScalarConverter::_floatValue = 0;
double	ScalarConverter::_doubleValue = 0;

ScalarConverter::ScalarConverter(){}

ScalarConverter::~ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	(void) copy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy)
{
	(void) copy;
	return (*this);
}

void	ScalarConverter::convert(char *value)
{
	_value = value;
	typeCheck(value);
	if (_type == TYPE_UNKNOW)
		throw ScalarConverter::UnknowTypeException();
	switch (_type)
	{
	case TYPE_UNKNOW:
		return ;
	case TYPE_CHAR:
		_charValue = static_cast<unsigned char>(_value[0]);
		_intValue = static_cast<int>(_charValue);
		_floatValue = static_cast<float>(_charValue);
		_doubleValue = static_cast<float>(_charValue);
		break;
	default:
		_doubleValue = atof(_value.c_str());
		_charValue = static_cast<unsigned char>(_doubleValue);
		_intValue = static_cast<int>(_doubleValue);
		_floatValue = static_cast<float>(_doubleValue);
		break;
	}
	displayValue();
}

void	ScalarConverter::typeCheck(const std::string &value)
{
	if (value.size() == 1 && (!std::isalnum(value[0]) || std::isalpha(value[0])))
		_type = TYPE_CHAR;
	else if (value == "nan" || value == "nanf" || value == "inf" || value == "+inf" || value == "-inf" || value == "+inff" || value == "-inff" || value == "inff")
		_type = TYPE_IMPOSIBLE;
	else
	{
		std::string::const_iterator i = value.begin();
		if (value[0] == '+' || value[0] == '-')
			i++;
		while (i != value.end() && _type != TYPE_UNKNOW)
		{
			if (_type == TYPE_DOUBLE)
				_prec++;
			if (*i < '0' || *i > '9')
			{
				if (*i == '.' && (*(i + 1) >= '0'  && *(i + 1) <= '9') && i != value.begin())
					_type = TYPE_DOUBLE;
				else if (*i == 'f' && i + 1 == value.end() && _type == TYPE_DOUBLE)
					_type = TYPE_FLOAT;
				else
					_type = TYPE_UNKNOW;
			}
			i++;
		}
		if (_type != TYPE_UNKNOW && _type == TYPE_EMPTY)
			_type = TYPE_INT;
	}
}

void	ScalarConverter::displayValue()
{
	if (_type == TYPE_IMPOSIBLE)
	{
		std::cout << "char:	" << "imposible" << std::endl;
		if (_value == "nan" || _value == "nanf")
		{
			std::cout << "int:	" << "imposible" << std::endl;
			std::cout << "float:	" << "nanf" << std::endl;
			std::cout << "double:	" << "nan" << std::endl;
		}
		else if (_value[0] == '-')
		{
			std::cout << "int:	" << "-inf" << std::endl;
			std::cout << "float:	" << "-inff" << std::endl;
			std::cout << "double:	" << "-inf" << std::endl;
		}
		else
		{
			std::cout << "int:	" << "inf" << std::endl;
			std::cout << "float:	" << "inff" << std::endl;
			std::cout << "double:	" << "inf" << std::endl;
		}
		return ;
	}
	if (std::isprint(_charValue))
		std::cout << "char:	'" << _charValue << "'" << std::endl;
	else
		std::cout << "char:	" << "Non displayable" << std::endl;
	std::cout << "int:	" << _intValue << std::endl;
	if (!_prec)
		_prec = 1;
	std::cout << "float:	" << std::fixed << std::setprecision(_prec) << _floatValue << "f" << std::endl;
	std::cout << "double:	" << std::fixed << std::setprecision(_prec) << _doubleValue << std::endl;
}

const char* ScalarConverter::UnknowTypeException::what() const throw()
{
	return ("Input is Unknow Type, can't convert this value.");
}

const char* ScalarConverter::BadInputException::what() const throw()
{
	return ("Bad input, it should be >>   ./convert <value>");
}