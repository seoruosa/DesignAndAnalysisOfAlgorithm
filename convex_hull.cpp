#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

/*
- lidar com pontos que estão sobre uma mesma linha
para todos os pares de pontos:
    conte quantos pontos estão à direita/esquerda e armazene os pontos que são colineares
    if ((direita>0 && esquerda==0) or (esquerda>0 && direita==0)):
        ache os pontos extremos dados os colineares e armazene
*/

template <typename Iterador>
std::set<std::pair<double, double>> bruteForceConvexHull(Iterador const begin, Iterador const end){
    std::set<std::pair<double, double>> answer{};
    std::set<std::pair<double, double>> colinears;

    Iterador point1 = begin;
    Iterador point2;

    while (point1 != end)
    {
        point2 = point1;
        ++point2;

        while (point2 != end)
        {
            auto signal = [&] (auto comp) {
                double a = (*point2).second - (*point1).second;
                double b = (*point1).first - (*point2).first;
                double c = (*point1).first*(*point2).second - (*point1).second*(*point2).first;

                double c_calc = a*comp.first + b*comp.second;

                return (c > c_calc ? 1 : (c < c_calc ? -1 : 0));
            };

            // reset state 
            int right = 0;
            int left = 0;
            colinears.clear();

            for (auto x = begin; x != end ; ++x)
            {
                int x_signal = signal(*x);
                if (x_signal == -1){
                    ++left;
                } else if(x_signal == 1) {
                    ++right;
                } else {
                    colinears.insert(*x);
                }
            }

            if (right>0 xor left>0){
                if (colinears.empty())
                {
                    answer.insert(*point1);
                    answer.insert(*point2);
                } else {
                    // deal with colinears points
                    colinears.insert(*point1);
                    colinears.insert(*point2);

                    auto comp = [&] (auto lhs, auto rhs) {
                        return ((lhs.first < rhs.first) || ((lhs.first == rhs.first) && (lhs.second < rhs.second)));
                        };

                    const auto [first, last] = std::minmax_element(colinears.cbegin(), colinears.cend(), comp);
                    answer.insert(*first);
                    answer.insert(*last);
                }
            }

            ++point2;
        }
        
        ++point1;
    }


    return answer;
    
}

int main(){
    std::vector<std::pair<double, double>> points_list{
        {0, 0},
        {0, 2},
        {2, 2},
        {0, 1},
        {2, 2},
        {2, 0}, 
        {1, 1}, 
        {1, 1.5}, 
        {0.5, 1.5}
    };
    
    auto print_pair = [] (auto par) {std::cout << "(" << par.first << ", " << par.second << ")";};

    for (auto i = points_list.cbegin(); i != points_list.cend(); i++)
    {
        print_pair(*i);
        std::cout << std::endl;
    }

    std::cout << "---------- CONVEX HULL ---------------" << std::endl;

    std::set<std::pair<double, double>> convex_hull = bruteForceConvexHull(points_list.cbegin(), points_list.cend());    
    
    for (auto i = convex_hull.cbegin(); i != convex_hull.cend(); i++)
    {
        print_pair(*i);
        std::cout << std::endl;
    }

}

