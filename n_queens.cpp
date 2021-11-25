#include <vector>
#include <iostream>
#include <algorithm>

#include "n_queens.h"

int main()
{
    solve_nqueen(10);
}

void print_board(std::vector<int> &a)
{
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a.size(); j++)
        {
            if (a[i] == j)
            {
                std::cout << " Q ";
            }
            else
            {
                std::cout << " . ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

// this function test if adding the new queen on column col it's possible
bool is_possible_nqueen(std::vector<int> &nqueens, int col)
{
    int row = nqueens.size();
    auto is_on_diagonal = [&](auto x1, auto y1, auto x2, auto y2)
    { return (std::abs(x1 - x2) == std::abs(y1 - y2)); };

    // test if someone else is on the column
    for (auto other_queen : nqueens)
    {
        if (other_queen == col)
        {
            return false;
        }
    }
    // test if have other queen on diagonal
    for (int i = 0; i < row; i++)
    {

        if (is_on_diagonal(col, row, nqueens[i], i))
        {
            return false;
        }
    }

    return true;
}

/*
The ith position of vector queens represent the row and value of this position, the column.
*/
bool solve_nqueen(std::vector<int> &queens, int n)
{
    if (queens.size() == n)
    {
        print_board(queens);
        // return true;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (is_possible_nqueen(queens, i))
            {
                queens.push_back(i);
                solve_nqueen(queens, n);
                queens.pop_back();
            }
        }
    }

    return false;
}

void solve_nqueen(int n)
{
    std::vector<int> queens({});

    solve_nqueen(queens, n);
}