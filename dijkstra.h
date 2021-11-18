#pragma once

#include <vector>
#include <iostream>

class NodePath
{
public:
    float distance;
    int index_from;
    
    NodePath(float d, int i);

    friend std::ostream &operator<<(std::ostream &os, const NodePath &v)
    {
        os << "{from: " << v.index_from << ", dist: " << v.distance << "}";
        return os;
    }

    bool operator>(const NodePath &v) const
    {
        return (distance > v.distance);
    }
};

NodePath::NodePath(float d, int i)
{
    distance = d;
    index_from = i;
}

class Node
{
public:
    int index;
    float weight;
    Node(int i, int w);
};

Node::Node(int i, int w)
{
    index = i;
    weight = w;
}

// TODO pensar em outra estrutura para representar grafos com pesos

std::vector<NodePath> dijkstra(std::vector<std::vector<Node>> G, int source);

float INF = __FLT_MAX__;
int EMPTY = -1;