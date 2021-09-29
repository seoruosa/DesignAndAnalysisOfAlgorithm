#include <iostream>
#include <vector>
#include "util.cpp"
#include <list>
// #include <algorithm>
// #include <numeric>

template <typename Iterador>
std::vector<int> tspBruteForce(Iterador&& distances){
    std::vector<int> best_route(std::size(distances));
    // int min_distance = INT64_MAX;


    return best_route;
}

std::list<int> todo(std::list<int>& l, std::list<int> to_do) {

	for (auto e : l) {
		to_do.remove(e);
	}

	return to_do;
}


void permutations(int n) {

	std::list<int> start({ });
	std::list<std::list<int>> frontier({ start });

	std::list<int> elements({});
	for (int i = 0; i < n; i++) {
		elements.push_back(i);
	}

	while (!frontier.empty()) {

		std::list<int> path(frontier.front());

		frontier.pop_front();

		if (path.size() == n) {
			print_sequence(path);
		}
		else {

			for (auto e : todo(path, elements)) {
				std::list<int> new_path(path);
				new_path.push_back(e);
				frontier.push_back(new_path);
			}

		}
	}
}

int main(){
    std::vector<std::vector<int>> distances {
        {0, 2, 5, 7},
        {2, 0, 8, 3},
        {5, 8, 0, 1},
        {7, 3, 1, 0}
    };

    auto print_matriz = [&] (auto dist) {
        for (auto i: dist)
        {
            for (auto j : i) std::cout << j << ", ";
            std::cout << std::endl;
        } 
        std::cout << std::endl; 
        };

    print_matriz(distances);

    std::vector<int> a = tspBruteForce(distances);

    print_sequence(a);

    permutations(5);
}