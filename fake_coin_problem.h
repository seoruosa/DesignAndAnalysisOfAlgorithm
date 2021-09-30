#pragma once

#include <vector>

enum Coin
{
    FAKE,
    REAL
};

std::vector<int> set_coins_with_fake(int size, int pos);
int find_fake(std::vector<int> set_coins, int begin, int end);
int find_fake(std::vector<int> set_coins);