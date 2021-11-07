#pragma once
#include <vector>
#include <map>

int knapsack_vector(std::vector<int>& weights, std::vector<int>& values, int max_n_itens, int capacity);
int knapsack_map(std::vector<int> &weights, std::vector<int> &values, int max_n_itens, int capacity);
int knapsack_FM(std::vector<int>& weights, std::vector<int>& values, std::map<std::pair<int, int>, int>& F, int max_n_itens, int capacity);
int knapsack_FM(std::vector<int>& weights, std::vector<int>& values, std::vector<std::vector<int>>& F, int max_n_itens, int capacity);