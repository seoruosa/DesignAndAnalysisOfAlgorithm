#ifndef _UTIL
#define _UTIL 1

#include <iostream>

template <typename T>
void print_sequence(T const& x){
    typename T::const_iterator pos;
    typename T::const_iterator end(x.end());

    for (pos = x.begin(); pos != end; ++pos)
    {
        std::cout << (*pos) << " ";
    }
    std::cout << std::endl;
}

template<class Iterable>
void print_seq_of_seq(Iterable& seq) {
	for (auto s : seq) {
		for (auto e : s) {
			std::cout << e << " ";
		}
		std::cout << " , ";
	}
	std::cout << std::endl;
}

#endif /*_UTIL*/