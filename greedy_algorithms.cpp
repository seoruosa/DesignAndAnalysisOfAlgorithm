#include <iostream>
#include <vector>
#include "util.cpp"
#include "prim.cpp"
#include "kruskal.cpp"

int main()
{   
    // std::vector<std::vector<float>> graph({
    //     {INF, 4, 9, 5},
    //     {4, INF, 7, 6},
    //     {9, 7, INF, 8},
    //     {5, 6, 8, INF},
    // });
    
    
    std::vector<std::vector<float>> graph({
      // a, b, c, d, e, f
        {INF, 3  , INF  , INF, 6    , 5},
        {3  , INF, 1    , INF, INF  , 4},
        {INF, 1  , INF  , 6  , INF  , 4},
        {INF, INF, 6    , INF, 8    , 5},
        {6  , INF, INF  , 8  , INF  , 2},
        {5  , 4  , 4    , 5  , 2    , INF},
    });

    std::cout << "Problem: " << std::endl;
    print_matrix(graph);

    auto result = prim_n2(graph);

    std::cout << "prim result: " << std::endl;
    print_matrix(result);

    auto result_kruskal = kruskal(graph);

    std::cout << "kruskal result: " << std::endl;

    for (auto edge : result_kruskal)
    {
        std::cout << edge << std::endl;
    }

    // auto a = Node({0, 1.1});
    // auto b = Node({1, 1.5});

    // std::cout << (b > a) << std::endl;
}