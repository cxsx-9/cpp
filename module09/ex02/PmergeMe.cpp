#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::~PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe &copy): _vec(copy._vec), _list(copy._list){}

PmergeMe &PmergeMe::operator=(const PmergeMe &copy)
{
	_vec = copy._vec;
	_list = copy._list;
	return (*this);
}

PmergeMe::PmergeMe(int ac, char **av)
{  
	std::string			token;
	std::vector<int>	array;
	for (int i = 1; i < ac; i++)
	{
		token = av[i];
		std::string::const_iterator it = token.begin();
		for (; it != token.end(); it++)
		{
			if (!std::isdigit(*it))
				throw PmergeMe::ErrInput();
		}
		int number = std::atoi(token.c_str());
		array.push_back(number);
		_vec.push_back(number);
		_list.push_back(number);
	}
	if (isDup(array))
		throw PmergeMe::ErrDup();

	int size = array.size();
	clock_t start_time1 = clock();
	sortVec(_vec.begin(), _vec.end());
	clock_t end_time1 = clock();

	clock_t start_time2 = clock();
	sortList(_list.begin(), _list.end());
	clock_t end_time2 = clock();


	std::cout << "Before	: ";
	display(array);

	std::cout << "after	: ";
	display(_vec);
	// isSort(_vec); // DEBUG

	// std::cout << "after	: "; // DEBUG
	// display(_list);	// DEBUG
	// isSort(_list); // DEBUG

	double time1 = static_cast<double>(end_time1 - start_time1) / CLOCKS_PER_SEC * 10000000;
	double time2 = static_cast<double>(end_time2 - start_time2) / CLOCKS_PER_SEC * 10000000;
	std::cout << "Time to process a range of " << size << " elements with std::vector : " << time1 << " us" << std::endl;
	std::cout << "Time to process a range of " << size << " elements with std::list   : " << time2 << " us" << std::endl;

}


bool	PmergeMe::isDup(std::vector<int> array)
{
	for (itVec it = array.begin(); it != array.end(); it++)
	{
		for (itVec jt = array.begin(); jt < it; jt++)
			if (*it == *jt)
				return (true);
	}
	return (false);
}

void	PmergeMe::insertVec(itVec begin, itVec end)
{
	for (itVec it = begin; it != end; it++)
	{
		itVec j = std::next(it);
		int tmp = *j;
		while (j != begin && *(j - 1) > tmp && j != end)
		{
			*j = *(j - 1);
			--j;
		}
		*j = tmp;
	}
}

void	PmergeMe::mergeVec(itVec begin, itVec half, itVec end)
{
	std::vector<int>	left(begin, half);
	std::vector<int>	right(half, end);

	itVec	Lit = left.begin();
	itVec	Rit = right.begin();

	for (itVec it = begin; it != end; it++)
	{
        if (Rit == right.end())
		{
            *it = *Lit;
            Lit++;
        }
		else if (Lit == left.end())
		{
            *it = *Rit;
            Rit++;
        }
		else if (*Rit > *Lit)
		{
            *it = *Lit;
            Lit++;
        }
		else
		{
            *it = *Rit;
            Rit++;
        }
	}
}

void	PmergeMe::sortVec(itVec begin, itVec end)
{
	if (std::distance(begin, end) > K)
	{
		itVec half = begin;
		std::advance(half, std::distance(begin, end) / 2);
		sortVec(begin, half);
		sortVec(half, end);
		mergeVec(begin, half, end);
	}
	else
		insertVec(begin, end);
}

// ------------

void	PmergeMe::insertList(itList begin, itList end)
{
	for (itList it = begin; it != end; it++)
	{
		itList j = std::next(it);
		int tmp = *j;
		while (j != begin && *(std::prev(j)) > tmp && j != end)
		{
			*j = *(std::prev(j));
			--j;
		}
		*j = tmp;
	}
}

void	PmergeMe::mergeList(itList begin, itList half, itList end)
{
	std::list<int>	left(begin, half);
	std::list<int>	right(half, end);

	itList	Lit = left.begin();
	itList	Rit = right.begin();

	for (itList it = begin; it != end; it++)
	{
        if (Rit == right.end())
		{
            *it = *Lit;
            Lit++;
        }
		else if (Lit == left.end())
		{
            *it = *Rit;
            Rit++;
        }
		else if (*Rit > *Lit)
		{
            *it = *Lit;
            Lit++;
        }
		else
		{
            *it = *Rit;
            Rit++;
        }
	}
}

void	PmergeMe::sortList(itList begin, itList end)
{
	if (std::distance(begin, end) > K)
	{
		itList half = begin;
		std::advance(half, std::distance(begin, end) / 2);
		sortList(begin, half);
		sortList(half, end);
		mergeList(begin, half, end);
	}
	else
		insertList(begin, end);
}