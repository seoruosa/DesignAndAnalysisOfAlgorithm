#include <iostream>
#include <vector>

#include "util.cpp"
#include "lomuto_partition.cpp"
#include "quick_select.h"

int main()
{
    std::vector<int> A{4, 1, 10, 8, 7, 12, 9, 2, 15};

    print_sequence(A);
    std::cout << "-------------" << std::endl;
    // std::cout << lomutoPartition(A, 0, A.size() - 1) << std::endl;
    // std::cout << lomutoPartition(A) << std::endl;
    std::cout << median(A) << std::endl;
    // std::cout << quickSelect(A, 8) << std::endl;
}

int quickSelect(std::vector<int> &A, int l, int r, int k)
{
    int pivot = lomutoPartition(A, l, r);
    // print_sequence(A);

    if (pivot != k - 1)
    {
        if (pivot > l + k - 1)
            return quickSelect(A, l, pivot - 1, k);
        else
            return quickSelect(A, pivot + 1, r, k);
    }

    return A[pivot];
}

int quickSelect(std::vector<int> A, int k)
{
    return quickSelect(A, 0, A.size() - 1, k);
}

int median(std::vector<int> A)
{
    return quickSelect(A, (A.size() + 1) / 2);
}