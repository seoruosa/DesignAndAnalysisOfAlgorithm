#include <algorithm>

// template <typename Iterador, typename Predicado>
// void insertion_sort(Iterador, Iterador, Predicado);

// template <typename Iterador>
// void insertion_sort(Iterador, Iterador);

// template <typename Iterador, typename Predicado>
// void insertion_sort(Iterador begin, Iterador end, Predicado comp){
//     for (Iterador i = next(begin); i != end; ++i){
//         Iterador v = i;
//         Iterador j = --i;

//         while (j != begin && comp(*j, *v)){
//             std::iter_swap(j, next(j));
//             --j;
//         }
//         std::iter_swap(j, v);
//     }
// }

// template <typename Iterador>
// void insertion_sort(Iterador begin, Iterador end){
//     typedef typename std::iterator_traits<Iterador>::value_type Tipo;
//     insertion_sort(begin, end, std::less<Tipo>());
// }

void insertion_sort(std::vector<int>& A){
    for (int i = 1; i < A.size(); i++)
    {
        int v = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > v)
        {
            std::swap(A[j + 1], A[j]);
            --j;
        }
        A[j + 1] = v;
    }
    
}