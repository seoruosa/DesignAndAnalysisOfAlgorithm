#include <vector>

std::vector<int> change_making_pd(std::vector<int>& D, int n)
{
    int INF = n + 1;

    std::vector<int> number_of_coins(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        int temp = INF;
        int j = 0;

        while (j < D.size() && i >= D[j])
        {
            temp = number_of_coins[i - D[j]] < temp ? number_of_coins[i - D[j]] : temp;
            ++j;
        }
        number_of_coins[i] = temp + 1;
    }

    return number_of_coins;    
}

int main()
{
    std::vector<int> coins({1, 5, 10, 25, 50, 100});
    auto n_coins_to_value = change_making_pd(coins, 2000);

    std::cout << "coins: ";
    print_sequence(coins);

    for (int i = 0; i < n_coins_to_value.size(); i++)
    {
        std::cout << i << ": " << n_coins_to_value[i] << std::endl;
    }
    
}