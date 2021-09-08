#include <iostream>
#include <vector>
#include <string>

#include "util.cpp"

template <class Iter, typename Value, typename Predicado>
Iter sequential_search_2(Iter begin, Iter end, Value const &value, Predicado comp){
    Iter i = begin;
    
    while (i != end && !comp(*i, value))
    {
        i++;
    }
    return i;
}

template <class Iter, typename Value>
Iter sequential_search_2(Iter begin, Iter end, Value const &value){
    typedef typename std::iterator_traits<Iter>::value_type Tipo;

    return sequential_search_2(begin, end, value, std::equal_to<Tipo>());
}

template <class Iter>
Iter brute_force_string_match(Iter text_begin, Iter text_end, Iter pattern_begin, Iter pattern_end){
    int pattern_size = pattern_end - pattern_begin;
    
    Iter j;
    for (Iter i = text_begin; i != text_end - pattern_size; i++)
    {
        j = pattern_begin;
        while (j != pattern_end && *j == *(i + (j - pattern_begin)))
        {
            j++;
        }
        if (j == pattern_end){
            return i;
        }
        
    }
    
    return text_end;
    
}

int main(){
    std::vector<int> a = {1,2,3,4,5,10,8};
    int b = 4;

    print_sequence(a);

    std::cout << sequential_search_2(a.begin(), a.end(), 4) - a.begin() << std::endl;
    std::cout << sequential_search_2(a.begin(), a.end(), b) - a.begin() << std::endl;

    std::string word = "asdfghij";

    std::cout << word << std::endl;

    std::cout << sequential_search_2(word.begin(), word.end(), 'h') - word.begin() << std::endl;

    std::string pattern = "hi";

    bool answer = brute_force_string_match(word.begin(), word.end(), pattern.begin(), pattern.end()) == word.end();

    std::cout << (brute_force_string_match(word.begin(), word.end(), pattern.begin(), pattern.end()) - word.begin())  << std::endl;
    std::cout << ((brute_force_string_match(word.begin(), word.end(), pattern.begin(), pattern.end()) == word.end()) ? "not found" : "found")  << std::endl;


}