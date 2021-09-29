#include <iostream>
#include <vector>
#include "util.cpp"

enum Arrow
{
    LEFT,
    RIGHT
};

class ArrowNumber
{
public:
    int i;
    Arrow arrow;

    ArrowNumber(int _i, Arrow _arrow)
    {
        i = _i;
        arrow = _arrow;
    }

    ArrowNumber()
    {
        i = 0;
        arrow = Arrow::LEFT;
    }

    friend std::ostream &operator<<(std::ostream &os, const ArrowNumber &v)
    {
        os << "(" << v.i << ", " << (v.arrow == Arrow::LEFT ? "L" : "R") << ")";
        return os;
    }

    void invert_direction() { arrow = (arrow == Arrow::LEFT ? Arrow::RIGHT : Arrow::LEFT); }
};

auto find_mobile = [](std::vector<ArrowNumber> arrowNumber)
{
    int LAST_ELEMENT = arrowNumber.size() - 1;
    int mobile = -1;

    auto onLeft = [&](int _i)
    { return (_i != 0 && arrowNumber[_i].arrow == Arrow::LEFT && arrowNumber[_i - 1].i < arrowNumber[_i].i); };
    
    auto onRight = [&](int _i)
    { return (_i != LAST_ELEMENT && arrowNumber[_i].arrow == Arrow::RIGHT && arrowNumber[_i + 1].i < arrowNumber[_i].i); };

    for (int i = 0; i <= LAST_ELEMENT; i++)
    {
        if ((onLeft(i) || onRight(i)) && ((mobile == -1) || (arrowNumber[i].i > arrowNumber[mobile].i)))
        {
            mobile = i;
        }
    } 
   
    return mobile;
};

void johnson_trotter(int n)
{
    std::vector<ArrowNumber> arrows(n, ArrowNumber(0, Arrow::LEFT));
    // Initialize the first permutation
    int v = 1;
    for (size_t i = 0; i < arrows.size(); i++)
    {
        arrows[i].i = v;
        ++v;
    }

    std::vector<std::vector<ArrowNumber>> all_permutations{arrows};

    print_sequence(arrows); // new permutation

    int mobile = find_mobile(arrows);

    while (mobile != -1)
    {
        int mobile_value = arrows[mobile].i;

        int pointed_by_mobile = arrows[mobile].arrow == Arrow::LEFT ? mobile - 1 : mobile + 1;
        
        std::swap(arrows[mobile], arrows[pointed_by_mobile]);

        for (int k = 0; k < n; ++k)
        {
            if (arrows[k].i > mobile_value)
            {
                arrows[k].invert_direction();
            }
        }

        print_sequence(arrows); // new permutation
        all_permutations.push_back(arrows);


        mobile = find_mobile(arrows);
    }

    // print_seq_of_seq(all_permutations);
}

int main()
{
    johnson_trotter(5);
}