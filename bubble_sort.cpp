#ifndef _BUBBLE_SORT
#define _BUBBLE_SORT 1

#include <vector>

// template <typename Iterador, typename Predicado>
// void bubble_sort_2(Iterador, Iterador, Predicado );

// template <typename Iterador>
// void bubble_sort_2(Iterador, Iterador);

// std::vector<int> bubbleSort(std::vector<int> vetor);

std::vector<int> bubbleSort(std::vector<int> vetor){
    int i, j;
    
    for (i = 0; i < vetor.size() - 1; i++)
    {
        for (j = 0; j < vetor.size() - 1 - i; j++)
        {
            if(vetor[j+1] < vetor[j]){
                std::swap(vetor[j+1], vetor[j]);            
            }
        }
    }
    return vetor;
}

/*Baseado em 29.2.1 do livro do Alan*/
template <typename Iterador, typename Predicado>
void bubble_sort_2(Iterador inicio, Iterador fim, Predicado comp){
    auto fim_intermediario = fim;
    for (auto i = inicio; next(i) != fim; ++i){
        for (auto j = inicio; next(j) != fim_intermediario; ++j){
            if(comp(*next(j), *j)){
                std::iter_swap(next(j), j);
            }
        }
    }
}

template <typename Iterador>
void bubble_sort_2(Iterador inicio, Iterador fim){
    typedef typename std::iterator_traits<Iterador>::value_type Tipo;
    bubble_sort_2(inicio, fim, std::less<Tipo>());
}


#endif /*_BUBBLE_SORT*/