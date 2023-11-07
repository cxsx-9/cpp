#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <sstream>

class RPN
{
    private:
        std::stack<int> _stack;
    public:
        RPN();
        ~RPN();
        RPN(const RPN &copy);
        RPN &operator=(const RPN &copy);

        RPN(std::string input);
		int calculate(int num1, int num2, std::string operand);
		bool isOperand(std::string c);
        class ErrExpression: public std::exception
		{
			public:
				virtual const char* what() const throw(){ return ("Invalid RPN expression."); }
		};
        class ErrTooLessNum: public std::exception
		{
			public:
				virtual const char* what() const throw(){ return ("Not enough operands for operator."); }
		};
        class ErrOutOfRange: public std::exception
		{
			public:
				virtual const char* what() const throw(){ return ("Number is out of range."); }
		};
        class ErrDivideZero: public std::exception
		{
			public:
				virtual const char* what() const throw(){ return ("Cannot devide by Zero."); }
		};
        class ErrBadInput: public std::exception
		{
			public:
				virtual const char* what() const throw(){ return ("Bad input."); }
		};
};

#endif

/*

RPN Calculator https://paodayag.dev/reverse-polish-notation-js-parser/converter.html

Example from subject.

$>./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
42
$> ./RPN "7 7 * 7 -"
42
$> ./RPN "1 2 * 2 / 2 * 2 4 - +"
0
$> ./RPN "(1 + 1)"
Error


*/