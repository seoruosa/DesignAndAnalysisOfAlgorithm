#include "avaliacao_1.h"
#include <vector>
#include <iostream>

#include "util.cpp"

// criar vetor de inteiros
// soma

int main()
{
    // std::vector<int> A({1, 2, 3, 4, 5});
    // std::vector<int> A({1, 2, 3, 4});
    // std::vector<int> A({});
    std::vector<int> A({-1});

    print_sequence(A);

    std::cout << "soma: " << soma_vetor(A) << std::endl;
    std::cout << "soma(diminuir): " << soma_vetor_diminuir(A) << std::endl;
    std::cout << "soma(dividir): " << soma_vetor_diminuir(A) << std::endl;
}

int soma_vetor(std::vector<int> vetor)
{
    int soma = 0;

    for (auto el : vetor)
    {
        soma += el;
    }

    return soma;
}
// T(n) = n // operacao soma

int soma_vetor_diminuir(std::vector<int> vetor)
{
    int soma = 0;
    if (vetor.size() > 0)
    {
        std::vector<int> v(vetor.begin() + 1, vetor.end());

        soma = vetor[0] + soma_vetor_diminuir(v);
    }
    return soma;
}

// T(n) = T(n-1) + 1
int soma_vetor_dividir(std::vector<int> vetor)
{
    return soma_vetor_dividir(vetor, 0, vetor.size() - 1);
}

int soma_vetor_dividir(std::vector<int> vetor, int begin, int end)
{

    if (vetor.size() > 1)
    {
        return soma_vetor_dividir(vetor, begin, (end - begin) / 2) +
               soma_vetor_dividir(vetor, ((end - begin) / 2) + 1, end);
    }
    else if (vetor.size() == 1)
    {
        return vetor[0];
    }
    return 0;
}

// T(n) = 2*T(n/2) + 1