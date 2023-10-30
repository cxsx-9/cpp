#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::~ScalarConverter(){}

ScalarConverter::ScalarConverter(char *value) : _value(value), _type(TYPE_EMPTY), _prec(0), _intValue(0), _charValue(0), _floatValue(0), _doubleValue(0)
{
	typeCheck(value);
	if (_type == TYPE_UNKNOW)
		throw ScalarConverter::UnknowTypeException();
	convertType();
	displayValue();
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	this->_value = copy._value;
	this->_type = copy._type;
	this->_prec = copy._prec;
	this->_intValue = copy._intValue;
	this->_charValue = copy._charValue;
	this->_floatValue = copy._floatValue;
	this->_doubleValue = copy._doubleValue;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy)
{
	this->_value = copy._value;
	this->_type = copy._type;
	this->_prec = copy._prec;
	this->_intValue = copy._intValue;
	this->_charValue = copy._charValue;
	this->_floatValue = copy._floatValue;
	this->_doubleValue = copy._doubleValue;
	return (*this);
}

void	ScalarConverter::displayValue()
{
	if (_type == TYPE_IMPOSIBLE)
	{
		std::cout << "char:	" << "imposible" << std::endl;
		std::cout << "int:	" << "imposible" << std::endl;
		if (_value == "nan" || _value == "nanf")
		{
			std::cout << "float:	" << "nanf" << std::endl;
			std::cout << "double:	" << "nan" << std::endl;
		}
		else if (_value[0] == '-')
		{
			std::cout << "float:	" << "-inff" << std::endl;
			std::cout << "double:	" << "-inf" << std::endl;
		}
		else
		{
			std::cout << "float:	" << "inff" << std::endl;
			std::cout << "double:	" << "inf" << std::endl;
		}
		return ;
	}
	
	// char
	if (std::isprint(_charValue))
		std::cout << "char:	'" << _charValue << "'" << std::endl;
	else
		std::cout << "char:	" << "Non displayable" << std::endl;
	
	// int
	std::cout << "int:	" << _intValue << std::endl;

	// float
	std::cout << "float:	" << _floatValue;
	if (!_prec)
		std::cout << ".0";
	std::cout  << "f" << std::endl;

	// double
	std::cout << "double:	" << _doubleValue;
	if (!_prec)
		std::cout << ".0";
	std::cout << std::endl;
}

void	ScalarConverter::convertType()
{
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
		_floatValue = atof(_value.c_str());
		_charValue = static_cast<unsigned char>(_floatValue);
		_intValue = static_cast<int>(_floatValue);
		_doubleValue = static_cast<float>(_floatValue);
		break;
	}
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
				{
					_type = TYPE_UNKNOW;
					break;
				}
			}
			i++;
		}
		if (_type != TYPE_UNKNOW && _type == TYPE_EMPTY)
			_type = TYPE_INT;
	}
}

const char* ScalarConverter::UnknowTypeException::what() const throw()
{
	return ("Input is Unknow Type, can't convert this value.");
}

const char* ScalarConverter::BadInputException::what() const throw()
{
	return ("Bad input, it should be >>   ./convert <value>");
}