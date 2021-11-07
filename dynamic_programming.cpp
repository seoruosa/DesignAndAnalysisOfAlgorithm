#include <iostream>
#include <chrono>
#include <vector>

#include "fibo.cpp"
#include "change_making.cpp"
#include "util.cpp"

int main()
{
    // std::cout << "fibo" << std::endl;

    // for (int i = 0; i < 95; ++i)
    // {
    //     auto start = std::chrono::system_clock::now();
    //     // auto result = fibo_pd(i);
    //     auto result = fibo_pd(i);
    //     auto end = std::chrono::system_clock::now();

    //     std::chrono::duration<double> duration = (end - start);

    //     std::cout << i << " : " << result << " : " << duration.count() << std::endl;

    //     if (duration.count() > 15)
    //         break;
    // }

    std::vector<int> coins({1, 5, 10, 25, 50, 100});
    auto n_coins_to_value = change_making_pd(coins, 2000);

    std::cout << "coins: ";
    print_sequence(coins);

    for (int i = 0; i < n_coins_to_value.size(); i++)
    {
        std::cout << i << ": " << n_coins_to_value[i] << std::endl;
    }
    

}