#pragma once
#include <vector>
#include <set>
class Node
{
private:
    std::set<int> not_visited;
    std::vector<Node> children {};
public:
    int value;

    bool is_solution;
    int lb;
    std::vector<int> lb_values;
    std::vector<int> lb_index;
    
    std::vector<int> path;
    

    Node(int _lb, std::vector<int> _lb_values, std::vector<int> _lb_index, std::vector<int> _path);
    Node(Node &node);
    Node(Node node, int children);
    // ~Node();
    void print();
    void set_not_visited(std::set<int> _not_visited);
    void set_not_visited(std::vector<int> _not_visited);
    bool operator>(const Node &v) const;
    void add_edge(int from, int to);  
};