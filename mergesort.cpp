#include <vector>
#include <algorithm>
// #include "util.cpp"

// void merge(std::vector<int> &B, std::vector<int> &C, std::vector<int> &A);

void mergesort(std::vector<int> &A)
{
    int size = A.size();

    std::vector<int> B;
    std::vector<int> C;

    if (size > 1)
    {   
        B.insert(B.begin(), A.begin(), A.begin() + (size / 2));
        C.insert(C.begin(), A.begin() + (size / 2), A.end());
        mergesort(B);
        mergesort(C);
        merge(B, C, A);
    }
}

void merge(std::vector<int> &B, std::vector<int> &C, std::vector<int> &A)
{
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < B.size() && j < C.size())
    {
        if (B[i] <= C[j])
        {
            A[k] = B[i];
            ++i;
        }
        else
        {
            A[k] = C[j];
            ++j;
        }
        ++k;
    }
    if (i == B.size())
    {
        std::copy(C.begin() + j, C.end(), A.begin() + k);

    }
    else
    {
        std::copy(B.begin() + i, B.end(), A.begin() + k);
    }
}