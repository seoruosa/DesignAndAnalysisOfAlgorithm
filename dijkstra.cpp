#include "dijkstra.h"
#include "util.cpp"
#include <queue>

int main(){

    std::vector<std::vector<Node>> graph ({
        {{1, 3}, {3, 7}},
        {{0, 3}, {2, 4}, {3, 2}},
        {{1, 4}, {3, 5}, {4, 6}},
        {{0, 7}, {1, 2}, {2, 5}, {4, 4}},
        {{2, 6}, {3, 4}}
    });

    auto answer = dijkstra(graph, 0);

    for (int i = 0; i < answer.size(); i++)    
    {
        std::cout << "node: " << i << "-> " << answer[i] << std::endl;
    }
    
}

// https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-using-priority_queue-stl/
std::vector<NodePath> dijkstra(std::vector<std::vector<Node>> G, int source)
{
    std::vector<NodePath> answer(G.size(), {INF, EMPTY});
    std::priority_queue<NodePath, std::vector<NodePath>, std::greater<NodePath>> Q;

    answer[source] = {0, source};
    Q.push(answer[source]);

    while (!Q.empty())
    {
        auto actual_vertex = Q.top();
        Q.pop();

        for (auto adj_vertex: G[actual_vertex.index_from])
        {
            auto adj_index = adj_vertex.index;

            auto new_distance = actual_vertex.distance + adj_vertex.weight;
            auto actual_distance = answer[adj_index].distance;
            
            if (new_distance < actual_distance)
            {
                answer[adj_index] = NodePath({new_distance, actual_vertex.index_from});
                
                Q.push({new_distance, adj_index});
            }
            
        }
        
    }
    

    return answer;
}