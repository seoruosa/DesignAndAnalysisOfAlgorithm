#include "branch_bound.h"
#include <limits>
#include <set>

#include "util.cpp"
#include "read_tsp.cpp"

#include <chrono>

int main()
{
    // std::vector<std::vector<int>> graph({{0, 3, 1, 5, 8},
    //                                      {3, 0, 6, 7, 9},
    //                                      {1, 6, 0, 4, 2},
    //                                      {5, 7, 4, 0, 3},
    //                                      {8, 9, 2, 3, 0}});

    // static std::vector<std::vector<int>> visit_order = visit_order_init(graph);

    // print_matrix(visit_order);
    // std::vector<int> asdf ({0,1,2,3});
    // auto a = heuristic(graph, visit_order, asdf, 5);

    // std::cout << "heuristic: " << a << std::endl;

    std::vector<std::vector<int>> graph = get_instance("instances/brazil58.tsp");

    auto start = std::chrono::system_clock::now();

    tsp_solver_bb(graph);

    auto end = std::chrono::system_clock::now();

    std::chrono::duration<double> duration = (end - start);

    std::cout << "duration: " << duration.count() << std::endl;
}

bool tsp_solver_bb(std::vector<std::vector<int>> &graph, std::vector<int> &tour, int &best_cost,
                   std::vector<int> &best_tour, int &bound, const int &min_edge)
{
    static std::vector<std::vector<int>> visit_order = visit_order_init(graph);

    if (complete_tour(graph, tour))
    {
        int cost_this_tour = cost_tour(graph, tour);

        if (cost_this_tour < best_cost)
        {
            best_cost = cost_this_tour;
            best_tour = tour; // TODO parece errado. usando igual para colocar um vetor no lugar de outro
        }
        if (cost_this_tour < bound)
        {
            bound = cost_this_tour;
            
            print_sequence(tour);
            std::cout << "cost: " << cost_this_tour << std::endl;
            std::cout << "-----------------------------------" << std::endl;
        }

        // return true;
    }
    else
    {
        for (int i = 0; i < graph.size(); i++)
        {
            int next_city = visit_order[tour.back()][i];
            // int next_city = i;

            if (is_possible_add_city_to_tour(tour, next_city))
            {
                tour.push_back(next_city);
                if (heuristic(graph, visit_order, tour, min_edge) < bound)
                {
                    // tour.push_back(i);
                    tsp_solver_bb(graph, tour, best_cost, best_tour, bound, min_edge);
                    // tour.pop_back();
                }
                tour.pop_back();
            }
        }
        // return false;
    }
    return false;
}

void tsp_solver_bb(std::vector<std::vector<int>> &graph)
{

    std::vector<int> tour({0});
    std::vector<int> greedy_tour = initial_greedy_solution(graph);

    int best_cost = cost_tour(graph, greedy_tour);
    // int best_cost = std::numeric_limits<int>::max();
    int bound = best_cost;

    int min_edge = bound;

    for (int i = 0; i < graph.size(); i++)
    {
        for (int j = i + 1; j < graph.size(); j++)
        {
            auto weight = graph[i][j];

            if (weight < min_edge)
            {
                min_edge = weight;
            }
        }
    }

    std::vector<int> best_tour({});

    tsp_solver_bb(graph, tour, best_cost, best_tour, bound, min_edge);

    std::cout << std::endl
              << std::endl;
    std::cout << "-----------------------------------" << std::endl;
    std::cout << "-------------BEST SOLUTION---------" << std::endl;
    std::cout << "-----------------------------------" << std::endl;
    print_sequence(best_tour);
    std::cout << "cost: " << best_cost << std::endl;
    std::cout << "-----------------------------------" << std::endl;
}

int cost_tour(std::vector<std::vector<int>> &graph, std::vector<int> &tour)
{
    int acc = 0;
    for (size_t i = 0; i < tour.size() - 1; i++)
    {
        acc += graph[tour[i]][tour[i + 1]];
    }

    if (complete_tour(graph, tour))
    {
        acc += graph[tour.back()][tour.front()];
    }

    return acc;
}

bool complete_tour(std::vector<std::vector<int>> &graph, std::vector<int> &tour)
{
    return tour.size() == graph.size();
}

int heuristic(std::vector<std::vector<int>> &graph, std::vector<std::vector<int>> visit_order, std::vector<int> &tour, const int &min_edge)
{
    auto initialize_heuristic = [&](std::vector<std::vector<int>> visit_order, std::vector<std::vector<int>> graph)
    {
        std::vector<int> temp(2 * visit_order.size());

        for (int i = 0; i < graph.size(); i++)
        {
            temp[2 * i] = visit_order[i][1];
            temp[2 * i + 1] = visit_order[i][2];
        }
        return temp;
    };

    // TODO need to create some test
    auto cost_tour_with_subtour = [&](std::vector<int> tour_with_subtour, std::vector<std::vector<int>> graph)
    {
        int acc = 0;
        for (int i = 0; i < tour_with_subtour.size(); i++)
        {
            int from = i / 2;
            int to = tour_with_subtour[i];
            acc += graph[from][to];
        }
        return (acc + 1) / 2;
    };

    static std::vector<int> tour_with_subtour(initialize_heuristic(visit_order, graph));

    std::vector<int> current_tour_with_subtour(tour_with_subtour);

    if (tour.size() > 1)
    {
        for (int i = 0; i < tour.size() - 1; i++)
        {
            int from = tour[i];
            int to = tour[i + 1];

            int first_city = current_tour_with_subtour[2 * from + 1];
            int second_city = current_tour_with_subtour[2 * to + 1];

            if (graph[from][first_city] < graph[from][to])
            {
                current_tour_with_subtour[2 * from + 1] = to;
            }

            if (graph[to][second_city] < graph[from][to])
            {
                current_tour_with_subtour[2 * to + 1] = from;
            }
        }
    }
    // print_sequence(tour_with_subtour);
    // print_sequence(current_tour_with_subtour);

    // for (int i = 0; i < current_tour_with_subtour.size(); i++)
    // {
    //     std::cout << graph[i/2][current_tour_with_subtour[i]] << " ";
    // }
    // std::cout << std::endl;

    return cost_tour_with_subtour(current_tour_with_subtour, graph);
    // return cost_tour(graph, tour) + (graph.size() - tour.size() + 1) * min_edge;
}

bool is_possible_add_city_to_tour(std::vector<int> &tour, int &new_city)
{
    for (auto city : tour)
    {
        if (city == new_city)
        {
            return false;
        }
    }
    return true;
}

int initial_solution_cost(std::vector<std::vector<int>> &graph)
{
    std::vector<int> tour{};

    for (int i = 0; i < graph.size(); i++)
    {
        tour.push_back(i);
    }

    return cost_tour(graph, tour);
}

std::vector<int> initial_greedy_solution(std::vector<std::vector<int>> &graph)
{
    std::vector<int> tour({0});

    std::set<int> not_visited({});
    for (int i = 1; i < graph.size(); i++)
    {
        not_visited.insert(i);
    }

    while (tour.size() < graph.size())
    {
        auto last_city = tour.back();

        int min_distance = std::numeric_limits<int>::max();
        int next_city;
        for (auto city : not_visited)
        {
            auto distance = graph[last_city][city];

            if (distance < min_distance)
            {
                min_distance = distance;
                next_city = city;
            }
        }
        tour.push_back(next_city);
        not_visited.erase(next_city);
    }
    return tour;
}

std::vector<std::vector<int>> visit_order_init(std::vector<std::vector<int>> &graph)
{
    std::vector<int> temp({});

    for (int i = 0; i < graph.size(); i++)
    {
        temp.push_back(i);
    }

    std::vector<std::vector<int>> visit_order(graph.size(), temp);

    for (int i = 0; i < graph.size(); i++)
    {
        auto compare = [&](int a, int b)
        { return graph[i][a] < graph[i][b]; };
        std::sort(visit_order[i].begin(), visit_order[i].end(), compare);
    }

    return visit_order;
}