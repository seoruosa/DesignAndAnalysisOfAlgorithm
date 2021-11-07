#include <iostream>
#include <vector>
#include "util.cpp"
#include "prim.cpp"

int main()
{

    std::vector<std::vector<float>> graph({
        {INF, 4, 9, 5},
        {4, INF, 7, 6},
        {9, 7, INF, 8},
        {5, 6, 8, INF},
    });

    auto result = prim_n2(graph);

    print_matrix(result);

    // auto a = Node({0, 1.1});
    // auto b = Node({1, 1.5});

    // std::cout << (b > a) << std::endl;
}