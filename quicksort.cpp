#include "lomuto_partition.cpp"

void quicksort(std::vector<int>& vetor, int begin, int end)
{
    int s;
    if (begin < end)
    {
        s = lomutoPartition(vetor, begin, end);
        quicksort(vetor, begin, s - 1);
        quicksort(vetor, s + 1, end);
    }
}

void quicksort(std::vector<int>& vetor)
{
    quicksort(vetor, 0, vetor.size() - 1);
}