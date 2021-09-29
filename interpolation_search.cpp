#include <iostream>
#include <vector>
#include "util.cpp"

template <typename T>
int interpolation_search(std::vector<T> A, T value);

int main()
{
    std::vector<int> A{10, 20, 30, 40, 50, 60};

    print_sequence(A);

    for (int search : {40, 30, 0, 35, 70, 60})
    {
        std::cout << search << ": " << interpolation_search(A, search) << std::endl;
    }
}

template <typename T>
int interpolation_search(std::vector<T> A, T value)
{
    int left = 0;
    int right = A.size() - 1;

    int m;

    if (value >= A[left] && value <= A[right])
    {
        while (left <= right)
        {
            m = left + (((value - A[left]) * (right - left)) / (A[right] - A[left]));

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
    }
    return -1;
}