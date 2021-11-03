#include "prim.h"
#include "util.cpp"
#include <set>


std::vector<std::vector<float>> prim(std::vector<std::vector<float>>& graph)
{
    std::set<int> used_nodes;
    std::set<int> not_used_nodes;

    used_nodes.insert(0);
    for (int i = 1; i < graph.size(); i++)
    {
        not_used_nodes.insert(i);
    }
    
    std::vector<std::vector<float>> result (graph.size(), std::vector<float>(graph.size()));

    for (int i = 1; i < graph.size(); ++i)
    {
        float min = __FLT_MAX__;
        int new_node_to;
        int new_node_from;

        for (int node_from : used_nodes)
        {
            for (int node_to : not_used_nodes)
            {
                // std::cout << "graph[" << node_from << "][" << node_to << "] = " << graph[node_from][node_to] << " min: " << min  << std::endl; 
                if (graph[node_from][node_to] < min)
                {
                    new_node_to = node_to;
                    new_node_from = node_from;
                    min = graph[node_from][node_to];
                }
                
            }
            
        }
        // std::cout << "add new node: " << new_node_to << std::endl;

        not_used_nodes.erase(new_node_to);
        used_nodes.insert(new_node_to);
        
        result[new_node_from][new_node_to] = graph[new_node_from][new_node_to];
        result[new_node_to][new_node_from] = graph[new_node_to][new_node_from];
    }
    

    return result;
}