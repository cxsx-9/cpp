#include "Array.hpp"

template <typename T>
Array<T>::Array()
{
    _array = NULL;
    _size = 0;
    std::cout << GRAY << "Create by default" << DEFAULT << std::endl;
}

template <typename T>
Array<T>::~Array()
{
    delete[] _array;
    std::cout << GRAY << "Delete" << DEFAULT << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
    _array = new T[n];
    _size = n;
    std::cout << GRAY << "Create" << DEFAULT << std::endl;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> & copy)
{
    _size = copy._size;
    if (_array)
        delete[] _array; 
    _array = new T[_size];

    if (copy._array)
        for (unsigned int i = 0; i < _size; i++)
            _array[i] = copy._array[i];
    else
        _array = NULL;
    std::cout << GRAY << "Create a copy" << DEFAULT << std::endl;
    return (*this);
}
    // std::cout << DEBUG << "GO 2" << DEFAULT << std::endl;

template <typename T>
Array<T>::Array(const Array<T> & copy)
{
    *this = copy;
}

template <typename T>
T &Array<T>::operator[](const unsigned int index) const
{
    if (_array == NULL)
        throw Array::NullArrayException();
    if (index >= _size || index < 0)
        throw Array::OutofBoundsException();
    return (_array[index]);
}

template <typename T>
unsigned int Array<T>::size() const
{
    return (_size);
}

template <typename T>
std::ostream	&operator<<(std::ostream &out, Array<T> const &array)
{
    for (unsigned int i = 0; i < array.size(); i++)
	    out << i << " : " << array[i] << std::endl;
	return (out);
}

