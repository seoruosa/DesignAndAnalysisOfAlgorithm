#pragma once

#include <vector>
#include <set>

bool m_coloring(std::vector<std::set<int>> &graph, int m);
bool is_possible_color(std::vector<std::set<int>> &graph, std::vector<int> &node_colors, int color);