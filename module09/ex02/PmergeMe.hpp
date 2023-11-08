#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <sstream>
# include <vector>
# include <list>
# include <ctime>
# include <cstdlib>


# define DEFAULT "\001\033[0;39m\002"
# define YELLOW "\001\033[1;93m\002"
# define DEBUG "\001\033[1;93m\002"
# define RED "\001\033[1;91m\002"
# define GREEN "\001\033[1;92m\002"
# define BLUE "\001\033[1;94m\002"
# define CYAN "\001\033[1;96m\002"
# define MAGENTA "\001\033[1;95m\002"
# define GRAY "\001\033[1;90m\002"

# define K 5


class PmergeMe
{
	private:
		std::vector<int>	_vec;
		std::list<int>		_list;
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe &copy);
		PmergeMe &operator=(const PmergeMe &copy);
		PmergeMe(std::string input);

		bool	isDup(std::vector<int> array);

		typedef std::vector<int>::iterator itVec;
		void sortVec(itVec begin, itVec end);
		void mergeVec(itVec begin,itVec half,itVec end);
		void insertVec(itVec begin, itVec end);
	
		typedef std::list<int>::iterator itList;
		void sortList(itList begin, itList end);
		void mergeList(itList begin,itList half,itList end);
		void insertList(itList begin, itList end);
		class ErrInput: public std::exception
		{
			public:
				virtual const char* what() const throw(){ return ("Invalid input."); }
		};
		class ErrDup: public std::exception
		{
			public:
				virtual const char* what() const throw(){ return ("Input has a duplicate value."); }
		};
};

template <typename T>
void	display(T array)
{
	for (typename T::iterator it = array.begin(); it != array.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

template <typename T>
void	isSort(T array)
{
	for (typename T::iterator it = array.begin(); it != array.end(); it++)
	{
		typename T::iterator next = it;
		std::advance(next, 1);
		if (next != array.end() && *it > *next)
		{
			std::cout << RED << "not sort ;-;\n" << DEFAULT;
			return;
		}
	}
	std::cout << GREEN << "Sorted!!\n" << DEFAULT;
	return;
}

#endif


/*


Merge Insertion Sort / Ford-Johnson Algorithm
https://github.com/decidedlyso/merge-insertion-sort/blob/master/README.md
https://iq.opengenus.org/merge-insertion-sort/

merge-insert sort algorithm to sort the positive integer sequence.
at least two different containers
handle at
least 3000 different integers

avoid using a generic function.


• On the first line you must display an explicit text followed by the unsorted positive integer sequence.
• On the second line you must display an explicit text followed by the sorted positive integer sequence.
• On the third line you must display an explicit text indicating the time used by your algorithm by specifying the first container used to sort the positive integer sequence.
• On the last line you must display an explicit text indicating the time used by your algorithm by specifying the second container used to sort the positive integer sequence.


*/