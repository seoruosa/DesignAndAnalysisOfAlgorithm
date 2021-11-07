#include <iostream>

#include "knapsack.h"
#include "util.cpp"

int knapsack_map(std::vector<int> &weights, std::vector<int> &values, int max_n_itens, int capacity)
{
    std::map<std::pair<int, int>, int> F;

    for (int i = 0; i <= max_n_itens; i++)
    {
        F[{i, 0}] = 0;
    }

    for (int j = 0; j <= capacity; j++)
    {
        F[{0, j}] = 0;
    }

    return knapsack_FM(weights, values, F, max_n_itens, capacity);
}

int knapsack_FM(std::vector<int> &weights, std::vector<int> &values, std::map<std::pair<int, int>, int> &F, int max_n_itens, int capacity)
{
    auto max = [](int a, int b)
    { return (a > b ? a : b); };

    int n = max_n_itens;
    int W = capacity;

    if (!F.contains({n, W}))
    {
        int value = 0;
        if (W < weights[n])
        {
            value = knapsack_FM(weights, values, F, n - 1, W);
        }
        else
        {
            value = max(knapsack_FM(weights, values, F, n - 1, W),
                        (values[n - 1] + knapsack_FM(weights, values, F, n - 1, W - weights[n - 1])));
        }
        F[{n, W}] = value;
    }
    return F[{n, W}];
}

int knapsack_vector(std::vector<int> &weights, std::vector<int> &values, int max_n_itens, int capacity)
{
    std::vector<std::vector<int>> F(max_n_itens + 1, std::vector<int>(capacity + 1, -1));

    for (int i = 0; i < F[0].size(); i++)
    {
        F[0][i] = 0;
    }

    for (int i = 0; i < F.size(); i++)
    {
        F[i][0] = 0;
    }

    return knapsack_FM(weights, values, F, max_n_itens, capacity);
}

int knapsack_FM(std::vector<int> &weights, std::vector<int> &values, std::vector<std::vector<int>> &F, int max_n_itens, int capacity)
{
    auto max = [=](int a, int b)
    { return (a > b ? a : b); };

    int n = max_n_itens;
    int W = capacity;

    if (F[n][W] < 0)
    {
        int value = 0;
        if (W < weights[n])
        {
            value = knapsack_FM(weights, values, F, n - 1, W);
        }
        else
        {
            value = max(knapsack_FM(weights, values, F, n - 1, W),
                        (values[n - 1] + knapsack_FM(weights, values, F, n - 1, W - weights[n - 1])));
        }
        F[n][W] = value;
    }
    return F[n][W];
}

int main()
{

    std::vector<int> weights({2, 1, 3, 2});
    std::vector<int> values({12, 10, 20, 15});

    auto result = knapsack_map(weights, values, 4, 5);
    std::cout << "max return map: " << result << std::endl;

    result = knapsack_vector(weights, values, 4, 5);
    std::cout << "max return vector: " << result << std::endl;
}