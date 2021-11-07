#include "prim.h"
#include "util.cpp"
#include <set>
#include <queue>

std::vector<std::vector<float>> prim(std::vector<std::vector<float>> &graph)
{
    std::set<int> used_nodes;
    std::set<int> not_used_nodes;

    // initialize both sets
    used_nodes.insert(0);
    for (int i = 1; i < graph.size(); i++)
    {
        not_used_nodes.insert(i);
    }

    // initialize result tree
    std::vector<std::vector<float>> result(graph.size(), std::vector<float>(graph.size()));

    for (int i = 1; i < graph.size(); ++i)
    {
        float min = INF;
        int new_node_to;
        int new_node_from;

        for (int node_from : used_nodes)
        {
            for (int node_to : not_used_nodes)
            {
                if (graph[node_from][node_to] < min)
                {
                    new_node_to = node_to;
                    new_node_from = node_from;
                    min = graph[node_from][node_to];
                }
            }
        }

        not_used_nodes.erase(new_node_to);
        used_nodes.insert(new_node_to);

        result[new_node_from][new_node_to] = graph[new_node_from][new_node_to];
        result[new_node_to][new_node_from] = graph[new_node_to][new_node_from];
    }

    return result;
}

// template <typename T>
// class Edge
// {
//     private:
//         int node_from;
//         int node_to;
//         T weight;

//     public:
//         Edge::Edge(int node_from, int node_to, T weight){
//             this->node_from = node_from;
//             this->node_to = node_to;
//             this->weight = weight;
//         }
// };

class Node
{
public:
    int parent;
    float weight;

    Node(int parent, float weight)
    {
        this->parent = parent;
        this->weight = weight;
    }

    Node(float weight)
    {
        this->parent = -1;
        this->weight = weight;
    }

    friend std::ostream &operator<<(std::ostream &os, const Node &v)
    {
        os << "(" << v.parent << ", " << v.weight << ")";
        return os;
    }

    bool operator>(const Node &v) const
    {
        return (weight > v.weight);
    }

    bool operator<(const Node &v) const
    {
        return (weight < v.weight);
    }
};

std::vector<std::vector<float>> prim_n2(std::vector<std::vector<float>> &graph)
{
    std::vector<std::vector<float>> tree(graph.size(), std::vector<float>(graph.size(), 0.0));

    std::vector<Node> nodes(graph.size(), {INF});
    nodes[0] = Node({0});

    std::set<int> nodes_out_of_tree;
    for (int i = 1; i < graph.size(); i++)
    {
        nodes_out_of_tree.insert(i);
    }

    std::priority_queue<Node, std::vector<Node>, std::greater<Node>> priority_queue;

    for (int t = 0; t < graph.size() - 1; t++)
    {
        float min = INF;
        int u = 0;

        for (int i : nodes_out_of_tree)
        {
            if (nodes[i].weight < min)
            {
                min = nodes[i].weight;
                u = i;
            }
            priority_queue.push(Node({i, graph[t][i]}));
        }

        // while (!priority_queue.empty())
        // {
        //     std::cout <<  priority_queue.top() << ", ";
        //     priority_queue.pop();
        // }
        // std::cout << std::endl;

        nodes_out_of_tree.erase(u);

        for (int v : nodes_out_of_tree)
        {
            if (graph[u][v] < nodes[v].weight)
            {
                nodes[v] = Node({u, graph[u][v]});
            }
        }
    }

    // build tree
    for (size_t i = 1; i < nodes.size(); i++)
    {
        tree[nodes[i].parent][i] = graph[nodes[i].parent][i];
        tree[i][nodes[i].parent] = graph[nodes[i].parent][i];
    }

    return tree;
}

// https://www.codegrepper.com/code-examples/cpp/prim+implementation+c%2B%2B