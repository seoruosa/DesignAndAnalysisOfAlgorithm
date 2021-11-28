#include "read_tsp.cpp"

#include "util.cpp"
#include "branch_bound.h"

int main()
{
    // std::string filepath = "instances/brazil58.tsp";

    // auto weights = get_instance(filepath);

    // print_matrix(weights);

    auto node = Node(2, {1,2,3,4}, {1,2,3,4}, {1});

    node.print();

    auto node2 (node);

    node.path.push_back(13);
    node.lb_index[1] = 7;

    std::cout << "node modified" << std::endl;
    node.print();

    std::cout << "node2 equal initial node" << std::endl;
    std::vector<int> a({1,32});

    node2.set_not_visited(a);
    node2.print();
    


}

Node::Node(int _lb, std::vector<int> _lb_values, std::vector<int> _lb_index, std::vector<int> _path)
{
    lb = _lb;
    lb_values = std::vector<int> (_lb_values);
    lb_index = std::vector<int> (_lb_index);
    path = std::vector<int> (_path);
}

Node::Node(Node &node)
{
    lb = node.lb;
    lb_values = std::vector<int> (node.lb_values);
    lb_index = std::vector<int> (node.lb_index);
    path = std::vector<int> (node.path);
}

void Node::add_edge(int from, int to)
{
    for (int i : {from, to})
    {
        int first_idx = lb_index[2*i];
        int second_idx = lb_index[2*i + 1];

        if (i != first_idx and i != second_idx)
        {
            /* code */
        }
        
    }
    
}

Node::Node(Node node, int children)
{
    lb = node.lb;
    lb_values = std::vector<int> (node.lb_values);
    lb_index = std::vector<int> (node.lb_index);
    
    path = std::vector<int> (node.path);
    not_visited = std::set<int> (node.not_visited);

    int parent = node.path.back();
    // update lower bounds

    not_visited.erase(children);
    path.push_back(children);
}

bool Node::operator>(const Node &v) const
    {
        return (lb > v.lb);
    }

void Node::set_not_visited(std::set<int> _not_visited)
{
    not_visited = std::set<int> (_not_visited);
}

void Node::set_not_visited(std::vector<int> _not_visited)
{
    not_visited = std::set<int> (_not_visited.begin(), _not_visited.end());
}

void Node::print()
{
    std::cout << "lb_index:  ";
    print_sequence(lb_index);

    std::cout << "lb_values: ";
    print_sequence(lb_values);

    std::cout << "path:      ";
    print_sequence(path);

    std::cout << "lb:        " << lb << std::endl;

    std::cout << "not_visited: ";
    print_sequence(not_visited);
    std::cout << std::endl;

}

