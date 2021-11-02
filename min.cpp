#include <vector>
#include "util.cpp"

int min(std::vector<int> &vetor, int begin, int end)
{
    int left;
    int right;

    if (end > begin)
    {
        left = min(vetor, begin, (end + begin) / 2);
        right = min(vetor, (end + begin) / 2 + 1, end);

        return (vetor[left] > vetor[right] ? right : left);
    }
    else
    {
        return begin;
    }
}

int min(std::vector<int> &vetor)
{
    return min(vetor, 0, vetor.size() - 1);
}

class Stat
{
public:
    int min;
    int max;

    friend std::ostream &operator<<(std::ostream &os, const Stat &st)
    {
        os << "min: " << st.min << "  max: " << st.max;
        return os;
    }
};

Stat minmax(std::vector<int> &vetor, int begin, int end)
{
    Stat left;
    Stat right;

    if (end > begin)
    {
        left = minmax(vetor, begin, (end + begin) / 2);
        right = minmax(vetor, (end + begin) / 2 + 1, end);

        return {
            (vetor[left.min] > vetor[right.min] ? right.min : left.min),
            (vetor[left.max] < vetor[right.max] ? right.max : left.max)};
    }
    else
    {
        return {begin, begin};
    }
};

Stat minmax(std::vector<int> &vetor)
{
    return minmax(vetor, 0, vetor.size() - 1);
};

int main()
{
    std::vector<int> a({1, 2, 6, 7, 2, 9, 10});

    print_sequence(a);
    std::cout << "min: " << min(a) << std::endl;

    a = {1, 6, 7, 0, 9, 10};

    print_sequence(a);
    std::cout << "min: " << min(a) << std::endl;

    a = {1, 6, 7, 0, 9, 1, -1};

    print_sequence(a);
    std::cout << "min: " << min(a) << std::endl;

    a = {0, 10, 25, 1, 1, 1, 3, 1, 18, 1, 1, 37};

    print_sequence(a);
    std::cout << "min: " << min(a) << std::endl;

    auto b = minmax(a);
    std::cout << "size: " << a.size() << "  " << b << std::endl;
}