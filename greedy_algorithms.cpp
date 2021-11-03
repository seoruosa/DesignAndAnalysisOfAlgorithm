#include <iostream>
#include <vector>
#include "util.cpp"
#include "prim.cpp"

int main()
{

    std::vector<std::vector<float>> graph({
        {0, 4, 9, 5},
        {4, 0, 7, 6},
        {9, 7, 0, 8},
        {5, 6, 8, 0},
    });

    auto result = prim(graph);

    print_matrix(result);

}