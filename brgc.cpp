#include <iostream>
#include <list>
#include "util.cpp"
#include "brgc.h"

template <typename T>
std::list<std::list<T>> subsets(std::list<T>& seq);

int main()
{
    // std::list<std::list<int>> L = brgc(10);

    // print_seq_of_seq(L);

    // std::cout << "Number of subsets: " << L.size() << std::endl;

    std::list<int> list {1,2,3,4,5};

    auto A = subsets(list);

    print_seq_of_seq(A);

    std::cout << "Number of subsets: " << A.size() << std::endl;
}

std::list<std::list<int>> brgc(int n)
{
    std::list<std::list<int>> L;

    if (n == 1)
    {
        L.push_back({0});
        L.push_back({1});
    }
    else
    {
        L = brgc(n - 1);
        std::list<std::list<int>> L2(L.rbegin(), L.rend());

        for (auto &el : L)
            el.push_front(0);
        for (auto &el : L2)
            el.push_front(1);

        L.insert(L.end(), L2.begin(), L2.end());
    }

    return L;
}

template <typename T>
std::list<std::list<T>> subsets(std::list<T>& seq)
{
    int n = seq.size();

    std::list<std::list<int>> L = brgc(n);

    std::list<std::list<T>> all_subsets;

    for (auto sub_L : L)
    {
        std::list<T> subset;
        auto pointer = seq.begin();

        for (auto el : sub_L)
        {
            if (el == 1)
            {
                subset.push_front(*pointer);
            }
            ++pointer;
        }
        all_subsets.push_front(subset);
    }

    return all_subsets;
}