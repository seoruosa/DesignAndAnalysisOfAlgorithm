#include <iostream>
#include <vector>

#include "inversion.h"
#include "util.cpp"

int main()
{
    // std::vector<int> A{6, 2, 4, 3, 5, 1}; //10
    // std::vector<int> A{2, 6, 4}; //1
    // std::vector<int> A{2, 4, 6, 8, 9, 10}; // 0
    // std::vector<int> A{20, 2, 4, 6, 8, 9, 10}; //6
    std::vector<int> A{5, 4, 3, 2, 1};

    print_sequence(A);

    std::cout << "Number of inversions: " << inversion(A) << std::endl;

    print_sequence(A);
}

int inversion(std::vector<int> &A, int left, int right)
{
    if (right > left)
    {
        int left_inv = inversion(A, left, (right + left) / 2);
        int right_inv = inversion(A, (right + left) / 2 + 1, right);
        int merge_inv = inversion_merge(A, left, (right + left) / 2, right);
        return merge_inv + left_inv + right_inv;
    }
    else
    {
        return 0;
    }
}

int inversion(std::vector<int> &A)
{
    return inversion(A, 0, A.size() - 1);
}

int inversion_merge(std::vector<int> &A, int left, int pivot, int right)
{
    std::vector<int> LEFT(&A[left], &A[pivot + 1]);
    std::vector<int> RIGHT(&A[pivot + 1], &A[right + 1]);

    int i_left = 0;
    int i_right = 0;
    int number_inversions = 0;

    int i = left;

    while (i_left < LEFT.size() && i_right < RIGHT.size())
    {
        if (LEFT[i_left] > RIGHT[i_right])
        {
            A[i] = RIGHT[i_right];
            ++i_right;
            number_inversions += (LEFT.size() - i_left);
        }
        else
        {
            A[i] = LEFT[i_left];
            ++i_left;
        }
        ++i;
    }

    // unnecessary steps
    if (i_left == LEFT.size())
    {
        std::copy(RIGHT.begin() + i_right, RIGHT.end(), A.begin() + i);
    }
    else
    {
        std::copy(LEFT.begin() + i_left, LEFT.end(), A.begin() + i);
    }

    return number_inversions;
}