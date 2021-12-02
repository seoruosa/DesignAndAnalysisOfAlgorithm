#include <iostream>
#include <vector>
#include "util.cpp"
#include <algorithm>

#include <queue>

std::vector<int> initialize()
{
    std::cout << "inicializa variavel" << std::endl;
    return std::vector<int>({0});
}

std::vector<int> abc()
{
    static std::vector<int> ab(initialize());

    auto next = ab.back() + 1;

    ab.push_back(next);

    return std::vector<int>(ab);
}



int next(int i)
{
    static std::vector<std::vector<int>> a ({
        {1,2,3},
        {4,5,9}
    });

    auto el = a[i].back();
    a[i].pop_back();

    return el;
}

int main()
{
    // print_sequence(abc());
    // print_sequence(abc());
    // print_sequence(abc());

    std::cout << next(0) << std::endl;
    std::cout << next(1) << std::endl;
    std::cout << next(1) << std::endl;
    std::cout << next(0) << std::endl;
    std::cout << next(0) << std::endl;
    std::cout << next(1) << std::endl;
    std::cout << next(0) << std::endl;

    auto compare = [] (int a, int b) {return a > b;};

    std::vector<int> a({1,5,3,2,9,7});
    print_sequence(a);

    std::sort(a.begin(), a.end(), compare);
    print_sequence(a);
}