#include <iostream>
#include <vector>
#include "util.cpp"

template <typename T>
int binary_search(std::vector<T> A, T value);

int main()
{
    std::vector<int> A{10, 20, 30, 40, 50, 60};

    print_sequence(A);

    for (int search : {40, 30, 0, 70})
    {
        std::cout << search << ": " << binary_search(A, search) << std::endl;
    }
}

template <typename T>
int binary_search(std::vector<T> A, T value)
{
    int left = 0;
    int right = A.size() - 1;

    int m;

    while (left <= right)
    {
        m = (right + left) / 2;

        if (A[m] == value)
        {
            return m;
        }
        else if (value < A[m])
        {
            right = m - 1;
        }
        else
        {
            left = m + 1;
        }
    }
    return -1;
}