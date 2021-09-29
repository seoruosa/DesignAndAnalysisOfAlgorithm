#include <iostream>
#include <vector>
#include <list>
#include "util.cpp"

bool my_is_goal(int node) {
	return (node == 9);
}

std::vector<int> get_neighbors(int node, std::vector<std::vector<int>> G) {
	return G[node];
}

struct VisitedNode {
	std::vector<int> &pointer;
	bool visited;
};

std::list<int> myDFS(
	int s,
	std::vector<std::vector<int>> G,
	bool is_goal (int)
){
	std::list<int> start({ s });
	std::list<std::list<int>> frontier({ start });

	std::vector<int> isVisited (G.size(), 0);
	++isVisited[s];

	while (!frontier.empty()){
		std::list<int> path(frontier.back());

		print_seq_of_seq(frontier);
		std::cout << "------------------------" << std::endl;

		frontier.pop_back();

		if (is_goal(path.back())){
			return path;
		} else {
			for (int e : get_neighbors(path.back(), G)){
				if (isVisited[e] == 0)
				{
					std::list<int> new_path(path);
					new_path.push_back(e);
					frontier.push_back(new_path);
					++isVisited[e];
				}
			}
		}
	}
	return start;
}

std::list<int> myBFS(
	int s,
	std::vector<std::vector<int>> G,
	bool is_goal (int)
){
	std::list<int> start({ s });
	std::list<std::list<int>> frontier({ start });

	std::vector<int> isVisited (G.size(), 0);
	++isVisited[s];

	while (!frontier.empty()){
		std::list<int> path(frontier.back());

		print_seq_of_seq(frontier);
		std::cout << "------------------------" << std::endl;
		std::cout << "isVisited: ";
		print_sequence(isVisited);

		frontier.pop_back();

		if (is_goal(path.back())){
			return path;
		} else {
			for (int e : get_neighbors(path.back(), G)){
				if (isVisited[e] == 0)
				{
					std::list<int> new_path(path);
					new_path.push_back(e);
					frontier.push_front(new_path);
					++isVisited[e];
				}
			}
		}
	}
	return start;
}


int main(){
    std::vector<std::vector<int>> G {
        {1, 4},
        {0, 2, 5},
        {2, 4, 6},
        {2, 7},
        {0, 5},
        {1, 4, 6},
        {2, 5, 7},
        {6, 3},
    };

    std::list<int> pathdfs = myDFS(0, G, my_is_goal);

    print_sequence(pathdfs);

	std::cout << "----------------------" << std::endl << "BFS" << std::endl;

	std::list<int> path_bfs = myBFS(0, G, my_is_goal);
	print_sequence(path_bfs);
	
}