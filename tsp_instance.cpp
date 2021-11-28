// #include "tsp_instance.h"
#include <fstream>
#include <regex>
#include <string>

#include <iostream>



    // tsp_instance::tsp_instance(std::string filepath)
    // {
    //     std::string string_line;

    //     std::ifstream file(filepath);

    //     std::smatch match;
    //     std::regex two_points_reg("\\s*:\\s*");
    //     std::regex number_reg("\\d+");

    //     int i = 0;

    //     int SIZE = 58;

    //     std::vector<std::vector<int>> tsp_instance::_weights(SIZE, std::vector<int>(SIZE, 0));
    //     // std::vector<std::vector<int>> weight(SIZE, std::vector<int>(SIZE, 0));

    //     if (file.is_open())
    //     {
    //         while (file.good())
    //         {
    //             std::getline(file, string_line);

    //             if (std::regex_search(string_line, match, two_points_reg))
    //             {
    //                 std::cout << match.prefix() << " - " << match.suffix() << std::endl;
    //             }
    //             else if (string_line == "EDGE_WEIGHT_SECTION")
    //             {
    //                 std::cout << "section:" << std::endl;
    //             }
    //             else
    //             {

    //                 auto words_begin = std::sregex_iterator(string_line.begin(), string_line.end(), number_reg);
    //                 auto words_end = std::sregex_iterator();

    //                 int j = i + 1;
    //                 for (auto ind = words_begin; ind != words_end; ++ind)
    //                 {
    //                     auto match = *ind;
    //                     auto readed_number = match.str();

                        
    //                     _weights[i][j] = std::stoi(readed_number);
    //                     _weights[j][i] = std::stoi(readed_number);
                        
    //                     j++;
    //                 }
    //                 ++i;
    //             }
    //         }
    //     }

    //     file.close();
    // }

    // // tsp_instance::name()
    // // {
    // //     return _name;
    // // }

    // // tsp_instance::type()
    // // {
    // //     return _type;
    // // }

    // // tsp_instance::comment()
    // // {
    // //     return _comment;
    // // }

    // // tsp_instance::dimension()
    // // {
    // //     return _dimension;
    // // }

    // // tsp_instance::edgeWeightType()
    // // {
    // //     return _EdgeWeightType;
    // // }

    // // tsp_instance::weights()
    // // {
    // //     return _weights;
    // // }