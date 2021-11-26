#include "m_coloring.h"
#include "util.cpp"
#include <string>

int main()
{
    std::vector<std::set<int>> graph({
        {1, 2, 4},          //0
        {0, 2, 3},          //1
        {0, 1, 2, 3, 4, 5}, //2
        {1, 2, 5},          //3
        {0, 2, 5},          //4
        {2, 3, 4},          //5
    });

    auto answer = m_coloring(graph, 4);

    std::cout << (answer ? "Found" : "Not Found") << std::endl;
}

void log(std::string text) { std::cout << "LOG:     " << text << std::endl; }

bool m_coloring(std::vector<std::set<int>> &graph, int m, std::vector<int> &node_colors, bool &has_answer)
{
    if (node_colors.size() == graph.size())
    {
        // log("encontrou solucao");
        print_sequence(node_colors);
        has_answer = true;
    }
    else
    {
        // log("ainda nao encontrou solucao");
        for (int color = 0; color < m; color++)
        {
            // log("testando nova cor");
            if (is_possible_color(graph, node_colors, color))
            {
                node_colors.push_back(color);
                m_coloring(graph, m, node_colors, has_answer);
                node_colors.pop_back();
                // return has_answer;
            }
        }
    }
    return has_answer;
}

bool m_coloring(std::vector<std::set<int>> &graph, int m)
{
    std::vector<int> node_colors({0});
    bool has_answer = false;

    return m_coloring(graph, m, node_colors, has_answer);
}

bool is_possible_color(std::vector<std::set<int>> &graph, std::vector<int> &node_colors, int color)
{
    int next_node = node_colors.size();

    for (auto adj_node : graph[next_node])
    {
        if (adj_node < next_node && node_colors[adj_node] == color)
        {
            return false;
        }
    }
    return true;
}