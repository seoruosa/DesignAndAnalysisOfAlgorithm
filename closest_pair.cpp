#include <iostream>
#include <vector>
#include <float.h>
#include <math.h>

template <typename Iterador>
double BruteForceClosestPair(Iterador const begin, Iterador const end){
    double distance = DBL_MAX;

    auto dist_1d = [] (double a, double b) {return (a-b)*(a-b);};
    auto dist_2d = [&] (auto p1, auto p2) {return (dist_1d(p1.first, p2.first) + dist_1d(p1.second, p2.second));};

    auto print_pair = [] (auto par) {std::cout << "(" << par.first << ", " << par.second << ")";};

    Iterador point1 = begin;
    Iterador point2;

    while (point1 != end)
    {
        point2 = point1;
        ++point2;

        while (point2 != end)
        {
            distance = std::min(distance, dist_2d(*point1, *point2));
            
            // print_pair(*point1); std::cout << " "; print_pair(*point2);std::cout << std::endl;

            ++point2;
        }
        
        ++point1;
    }
    
    
    return std::sqrt(distance);
}

int main(){
    std::vector<std::pair<double, double>> list_points{
        {1.1, 1.2}, 
        {1.1, 1.25},
        {2.0, 3.1},
        {3.4, 2.0},
        {1.1, 1.2}
        };

    auto print_pair = [] (auto par) {std::cout << par.first << " " << par.second << std::endl;};

    

    for (auto p : list_points){
        print_pair(p);
    }

    double resp = BruteForceClosestPair(list_points.begin(), list_points.end());
    std::cout << "Minimum distance between points: " << resp << std::endl;

}

