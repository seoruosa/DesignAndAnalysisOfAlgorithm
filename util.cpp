#ifndef _UTIL
#define _UTIL 1

#include <iostream>

template <typename T>
void print_sequence(T const &x)
{
	typename T::const_iterator pos;
	typename T::const_iterator end(x.end());

	for (pos = x.begin(); pos != end; ++pos)
	{
		std::cout << (*pos) << " ";
	}
	std::cout << std::endl;
}

template <class Iterable>
void print_seq_of_seq(Iterable &seq)
{
	for (auto s : seq)
	{
		for (auto e : s)
		{
			std::cout << e << " ";
		}
		std::cout << " , ";
	}
	std::cout << std::endl;
}

template <class Iterable>
void print_matrix(Iterable &seq)
{
	for (auto s : seq)
	{
		for (auto e : s)
		{
			std::cout << e << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

template <class Iterable>
void print_matrix_3d(Iterable &seq)
{
	for (auto s : seq)
	{
		for (auto e : s)
		{
			std::cout << "(";
			for (auto i : e)
			{
				std::cout << i << ", ";
			}
			std::cout << ")";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

template <typename T>
T max(T &a, T &b)
{
	return (a > b ? a : b);
}
#endif /*_UTIL*/