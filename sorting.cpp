#include <iostream>
#include <vector>

#include "util.cpp"
#include "bubble_sort.cpp"
#include "selection_sort.cpp"
#include "insertion_sort.h"

#include "mergesort.h"
#include "quicksort.h"


int main(){
    std::vector<int> vetor ({5, 7, 1, 3, 5});
    print_sequence(vetor);
    // auto resposta = bubbleSort(vetor);

    // mergesort(vetor);
    quicksort(vetor);

    // print_sequence(resposta);
    print_sequence(vetor);

    vetor = {1, 6, 7, 0, 9, 1, -1};

    print_sequence(vetor);
    quicksort(vetor);
    print_sequence(vetor);

    vetor = {1, 1, 7, 0, 11, 17, 9, 1, -1};

    print_sequence(vetor);
    quicksort(vetor);
    print_sequence(vetor);

    vetor = {0, 10, 25, 1, 1, 1, 3, 1, 18, 1, 1, 37, -2, 28, -3};

    print_sequence(vetor);
    quicksort(vetor);
    print_sequence(vetor);

    // bubble_sort_2(vetor.begin(), vetor.end());
    // print_sequence(vetor);
    // // bubble_sort_2(vetor.begin(), vetor.end(), [] (auto a, auto b){return a>b;});
    // bubble_sort_2(vetor.begin(), vetor.end(), greater<int>());
    // print_sequence(vetor);
    
    // vector<int> a ({5, 7, 1, 3, 5});
    // print_sequence(a);
    // selection_sort(a.begin(), a.end());
    // print_sequence(a);
    // selection_sort(a.begin(), a.end(), greater<int>());
    // print_sequence(a);

    // cout << "INSERTION SORT" << endl;

    // vector<int> b ({5, 7, 1, 3, 5});
    // print_sequence(b);
    // insertion_sort(b);
    // print_sequence(b);

    // insertion_sort(b, greater<int>());
    // print_sequence(b);

}