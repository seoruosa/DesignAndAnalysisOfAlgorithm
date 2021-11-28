#include "read_tsp.h"

#include <iostream>
#include <fstream>
#include <regex>


std::vector<std::vector<int>> get_instance(std::string filepath)
{
    std::string string_line;

    std::ifstream file(filepath);

    std::smatch match;
    std::regex two_points_reg("\\s*:\\s*");
    std::regex number_reg("\\d+");

    int i = 0;

    int SIZE;

    std::vector<std::vector<int>> weights;

    if (file.is_open())
    {
        while (file.good())
        {
            std::getline(file, string_line);

            if (std::regex_search(string_line, match, two_points_reg))
            {
                if (match.prefix() == "DIMENSION")
                {
                    auto dim_str = match.suffix().str();
                    SIZE = std::stoi(dim_str);
                    weights = std::vector<std::vector<int>> (SIZE, std::vector<int>(SIZE, 0));
                }
                
                // std::cout << match.prefix() << " - " << match.suffix() << std::endl;
            }
            else if (string_line == "EDGE_WEIGHT_SECTION")
            {
                // std::cout << "section:" << std::endl;
                
            }
            else
            {

                auto words_begin = std::sregex_iterator(string_line.begin(), string_line.end(), number_reg);
                auto words_end = std::sregex_iterator();

                int j = i + 1;
                for (auto ind = words_begin; ind != words_end; ++ind)
                {
                    auto match = *ind;
                    auto readed_number = match.str();

                    
                    weights[i][j] = std::stoi(readed_number);
                    weights[j][i] = std::stoi(readed_number);
                    
                    j++;
                }
                ++i;
            }
        }
    }

    file.close();
    return weights;
}