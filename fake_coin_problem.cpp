#include <iostream>
#include <vector>
#include <numeric>

#include "util.cpp"
#include "fake_coin_problem.h"


int main()
{
    std::vector<int> set_coins;

    int len = 10;
    for (size_t i = 0; i <= len; i++)
    {
        set_coins = set_coins_with_fake(len, i);

        std::cout << "conf: " << i << "  function: " << find_fake(set_coins) << std::endl;
    }
}

// whats the better way to validate input and return some error
std::vector<int> set_coins_with_fake(int size, int pos)
{
    std::vector<int> set_coins(size, Coin::REAL);

    if (pos >= 0 && pos < size)
    {
        set_coins[pos] = Coin::FAKE;
    }

    return set_coins;
}

int find_fake(std::vector<int> set_coins, int left, int right)
{

    // calculates the weight of a subset
    auto weight = [&](int begin, int end)
    { return (std::accumulate(&set_coins[begin], &set_coins[end + 1], 0)); };

    auto is_odd = [](int value)
    { return value % 2 == 1; };

    int half = (right + left) / 2;

    if (is_odd(right - left + 1))
    {
        int weight_l = weight(left, half - 1);
        int weight_r = weight(half + 1, right);

        if (weight_l < weight_r)
            return find_fake(set_coins, left, half - 1);
        else if (weight_l > weight_r)
            return find_fake(set_coins, half + 1, right);
        else
            return half;
    }
    else
    {
        int weight_l = weight(left, half);
        int weight_r = weight(half + 1, right);

        if (weight_l < weight_r)
            return find_fake(set_coins, left, half);
        else if (weight_l > weight_r)
            return find_fake(set_coins, half + 1, right);
        else
            return -1;
    }
}

int find_fake(std::vector<int> set_coins)
{
    return find_fake(set_coins, 0, set_coins.size() - 1);
}