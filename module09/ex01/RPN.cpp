#include "RPN.hpp"

RPN::RPN(){}

RPN::~RPN(){}

RPN::RPN(const RPN &copy) : _stack(copy._stack){}

RPN &RPN::operator=(const RPN &copy)
{
	_stack = copy._stack;
	return (*this);
}

bool RPN::isOperand(std::string c)
{
	if (c == "+" || c == "-" || c== "*" || c == "/")
		return (true);
	return (false);
}

int RPN::calculate(int num1, int num2, std::string operand)
{
	int result = 0;
	if (operand == "+")
		result = num1 + num2;
	else if (operand == "-")
		result = num1 - num2;
	else if (operand == "*")
		result = num1 * num2;
	else if (operand == "/")
	{
		if (num2 == 0)
			throw RPN::ErrDivideZero();
		result = num1 / num2;
	}
	// debug
	// std::cout << num1 << " " << operand << " " << num2 << " = " << result << std::endl; // debug
	return (result);
}

RPN::RPN(std::string input)
{
	std::istringstream	line(input);
	std::string			token;

	while (line >> token)
	{
		if (!isOperand(token))
		{
			size_t size = 1;
			if (token[0] == '-')
				size++;
			if (token.size() > size)
				throw RPN::ErrOutOfRange();
			if (!std::isdigit(token[size - 1]))
				throw RPN::ErrExpression();
			_stack.push(std::atoi(token.c_str()));
		}
		else
		{
			if (_stack.size() < 2)
				throw RPN::ErrTooLessNum();
			int num2 = _stack.top();
			_stack.pop();
			int num1 = _stack.top();
			_stack.pop();
			int result = calculate(num1, num2, token);
			_stack.push(result);
		}
	}

	if (_stack.size() == 1)
	{
		std::cout << _stack.top() << std::endl; 
	}
	else
	{
		throw RPN::ErrExpression();
	}
}