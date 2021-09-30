#include <vector>
// #include "lomuto_partition.h"

int lomutoPartition(std::vector<int>& A, int l, int r){
    int pivot = A[l];
    int pivot_pos = l;

    for (size_t i = l + 1; i <= r; i++)
    {
        if(A[i] < pivot){
            pivot_pos += 1;
            std::swap(A[pivot_pos], A[i]);
        }
    }
    std::swap(A[l], A[pivot_pos]);
    
    return pivot_pos;
}

int lomutoPartition(std::vector<int>& A)
{
    return lomutoPartition(A, 0, A.size() - 1);
}
