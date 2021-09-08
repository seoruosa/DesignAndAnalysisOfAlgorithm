#ifndef _SELECTION_SORT
#define _SELECTION_SORT 1

#include <algorithm>

// template <typename Iterador, typename Predicado>
// void selection_sort(Iterador, Iterador, Predicado);

// template <typename Iterador>
// void selection_sort(Iterador, Iterador);

template <typename Iterador, typename Predicado>
void selection_sort(Iterador begin, Iterador end, Predicado comp){
    for (auto i = begin; i != end; ++i){
        auto min = std::min_element(i, end, comp);

        if (comp(*min, *i)){
            std::iter_swap(min, i);
        }
    }
}

template <typename Iterador>
void selection_sort(Iterador begin, Iterador end){
    typedef typename std::iterator_traits<Iterador>::value_type Tipo;
    selection_sort(begin, end, std::less<Tipo>());
}

#endif /*_SELECTION_SORT*/