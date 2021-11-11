#pragma once
#include <utility>
#include <vector>
#include <ostream>
#include <set>

// typedef std::pair<int, int> Edge;

#ifndef INF_CONST
#define INF_CONST
float INF = __FLT_MAX__;
#endif //INF_CONST

template <typename T>
class Edge
{
public:
    int node_from;
    int node_to;
    T weight;

    Edge(int node_from, int node_to, T weight)
    {
        this->node_from = node_from;
        this->node_to = node_to;
        this->weight = weight;
    }

    friend std::ostream &operator<<(std::ostream &os, const Edge &v)
    {
        os << "(" << v.node_from << ", " << v.node_to << ": " << v.weight << ")";
        return os;
    }

    bool operator>(const Edge &v) const
    {
        return (weight > v.weight);
    }

    bool operator<(const Edge &v) const
    {
        return (weight < v.weight);
    }
};

std::vector<Edge<float>> kruskal(std::vector<std::vector<float>> graph);

void makeset();
int find(std::vector<int>& size, std::vector<std::set<int>>& forest, int x);
void Union(std::vector<int>& size, std::vector<std::set<int>>& forest, int x, int y);
