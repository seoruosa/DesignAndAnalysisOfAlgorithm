#include "hamiltonian.h"
#include "util.cpp"

int main()
{
    std::vector<std::set<int>> graph({{1, 2, 3, 5},
                                      {0, 3, 4, 6},
                                      {0, 5},
                                      {0, 1, 5, 6},
                                      {1, 6},
                                      {0, 2, 3, 6},
                                      {1, 3, 4, 5}});

    // print_seq_of_seq(graph);

    hamiltonian(graph);                               
}

bool hamiltonian(std::vector<std::set<int>> &graph, std::vector<int> &visited_nodes, std::set<int> &not_visited)
{

    auto is_solution = [&](std::vector<int> visited_nodes)
    { return (visited_nodes.size() == graph.size() && graph[visited_nodes.back()].contains(visited_nodes.front())); };

    if (is_solution(visited_nodes))
    {
        print_sequence(visited_nodes);
    }
    else
    {
        for (int adj : graph[visited_nodes.back()])
        {
            if (not_visited.contains(adj))
            {
                visited_nodes.push_back(adj);
                not_visited.erase(adj);
                
                hamiltonian(graph, visited_nodes, not_visited);

                not_visited.insert(visited_nodes.back());
                visited_nodes.pop_back();
            }
            
        }
    }
    return false;
}

bool hamiltonian(std::vector<std::set<int>> &graph)
{
    int first_node = 0;

    std::vector<int> visited_nodes({first_node});

    std::set<int> not_visited ({});
    for (int i = 0; i < graph.size(); i++)
    {
        not_visited.insert(i);
    }
    not_visited.erase(first_node);
    

    return hamiltonian(graph, visited_nodes, not_visited);
}