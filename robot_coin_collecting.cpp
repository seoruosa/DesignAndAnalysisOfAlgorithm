#include "robot_coin_collecting.h"
#include "util.cpp"

int main()
{
    std::vector<std::vector<int>> board({{0, 0, 0, 0, 1, 0},
                                         {0, 1, 0, 1, 0, 0},
                                         {0, 0, 0, 1, 0, 1},
                                         {0, 0, 1, 0, 0, 1},
                                         {1, 0, 0, 0, 1, 0}});
    
    print_matrix(board);

    // auto collected_coins = robot_coin_collecting_pd(board);
    // std::cout << "collected coins: " << collected_coins << std::endl;

    auto collected_coins = robot_coin_collecting(board);
    std::cout << "collected coins: " << collected_coins << std::endl;
}

int robot_coin_collecting_pd(std::vector<std::vector<int>> &C)
{
    std::vector<std::vector<int>> acc_board(C.size(), std::vector<int>(C[0].size(), 0));
    auto max = [](auto a, auto b)
    { return (a > b ? a : b); };

    acc_board[0][0] = C[0][0];

    // fill first row
    for (int j = 1; j < C[0].size(); j++)
    {
        acc_board[0][j] = acc_board[0][j - 1] + C[0][j];
    }

    for (int i = 1; i < C.size(); i++)
    {
        acc_board[i][0] = acc_board[i - 1][0] + C[i][0]; //first el of row
        for (int j = 1; j < C[0].size(); j++)
        {
            acc_board[i][j] = max(acc_board[i - 1][j], acc_board[i][j - 1]) + C[i][j];
        }
    }

    print_matrix(acc_board);

    return acc_board[acc_board.size() - 1][acc_board[0].size() - 1];
}

int robot_coin_collecting(std::vector<std::vector<int>> &C)
{
    auto result = robot_coin_collecting(C, C.size() - 1, C[0].size() - 1);

    return result;
}


int robot_coin_collecting(std::vector<std::vector<int>> &C, int i, int j)
{
    
    auto max = [](auto a, auto b)
    { return (a > b ? a : b); };

    if (i == 0 && j == 0)
    {
        return C[i][j];
    }
    if (i == 0)
    {
        return robot_coin_collecting(C, i, j - 1) + C[i][j];
    }
    if (j == 0)
    {
        return robot_coin_collecting(C, i - 1, j) + C[i][j];
    }
    return max(robot_coin_collecting(C, i, j - 1), robot_coin_collecting(C, i - 1, j)) + C[i][j];
}