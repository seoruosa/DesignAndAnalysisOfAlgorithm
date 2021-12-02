#pragma once
#include <vector>

bool tsp_solver_bb(std::vector<std::vector<int>> &graph, std::vector<int> &tour, int &best_solution, std::vector<int> &best_tour,
                   int &bound, const int &min_edge);

void tsp_solver_bb(std::vector<std::vector<int>> &graph);

int cost_tour(std::vector<std::vector<int>> &graph, std::vector<int> &tour);

bool complete_tour(std::vector<std::vector<int>> &graph, std::vector<int> &tour);

int heuristic(std::vector<std::vector<int>> &graph, std::vector<std::vector<int>> visit_order, std::vector<int> &tour, const int &min_edge);

bool is_possible_add_city_to_tour(std::vector<int> &tour, int &new_city);

int initial_solution_cost(std::vector<std::vector<int>> &graph);

std::vector<int> initial_greedy_solution(std::vector<std::vector<int>> &graph);

std::vector<std::vector<int>> visit_order_init(std::vector<std::vector<int>> &graph);