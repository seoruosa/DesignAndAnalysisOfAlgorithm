#include <iostream>
#include <vector>

#include "util.cpp"
#include "bubble_sort.cpp"
#include "selection_sort.cpp"
#include "insertion_sort.h"

using namespace std;

int main(){
    vector<int> vetor ({5, 7, 1, 3, 5});
    
    print_sequence(vetor);
    auto resposta = bubbleSort(vetor);

    print_sequence(resposta);
    print_sequence(vetor);

    bubble_sort_2(vetor.begin(), vetor.end());
    print_sequence(vetor);
    // bubble_sort_2(vetor.begin(), vetor.end(), [] (auto a, auto b){return a>b;});
    bubble_sort_2(vetor.begin(), vetor.end(), greater<int>());
    print_sequence(vetor);
    
    vector<int> a ({5, 7, 1, 3, 5});
    print_sequence(a);
    selection_sort(a.begin(), a.end());
    print_sequence(a);
    selection_sort(a.begin(), a.end(), greater<int>());
    print_sequence(a);

    cout << "INSERTION SORT" << endl;

    vector<int> b ({5, 7, 1, 3, 5});
    print_sequence(b);
    insertion_sort(b);
    print_sequence(b);
    // insertion_sort(b, greater<int>());
    // print_sequence(b);

}