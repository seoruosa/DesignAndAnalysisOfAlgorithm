#include "kruskal.h"
#include <queue>
#include <iostream>
#include <map>

#include <memory>
#include <set>
#include "util.cpp"


std::vector<Edge<float>> kruskal(std::vector<std::vector<float>> graph)
{
    // initialization for the disjoint_set structure
    std::vector<int> size(graph.size(), 1);
    std::vector<std::set<int>> forest(graph.size(), std::set<int>({}));

    for (int i = 0; i < forest.size(); i++)
    {
        (forest[i]).insert(i);
    }
    
    int edge_counter = 0;
    std::vector<Edge<float>> tree_edges;

    // sort edges by weight (assumes that (i, j) have the weight of (j, i) and have no edge (i,i) for all i,j)
    std::priority_queue<Edge<float>, std::vector<Edge<float>>, std::greater<Edge<float>>> PQ;
    for (int i = 0; i < graph[0].size(); i++)
    {
        for (int j = i + 1; j < graph.size(); j++)
        {
            Edge<float> edge({i, j, graph[i][j]});

            PQ.push(edge);
        }
    }

    while (edge_counter < graph.size() - 1)
    {
        Edge<float> edge = PQ.top();
        PQ.pop();

        int index_from = find(size, forest, edge.node_from);

        if (!forest[index_from].contains(edge.node_to))
        {
            int index_to = find(size, forest, edge.node_to);
            Union(size, forest, index_from, index_to);

            tree_edges.push_back(edge);
            ++edge_counter;
        }        
        
    }
    
    return tree_edges;
}

int find(std::vector<int>& size, std::vector<std::set<int>>& forest, int x)
{
    for (int i = 0; i < size.size(); i++)
    {
        if (size[i] > 0 && forest[i].contains(x))
        {
            return i;
        }
        
    }
    return -1;
}

void Union(std::vector<int>& size, std::vector<std::set<int>>& forest, int x, int y)
{
    if (size[x] > 0 && size[y] > 0)
    {
        forest[x].merge(forest[y]);
        size[x] = size[x] + size[y];
        size[y] = 0;
    }
    
    
} 