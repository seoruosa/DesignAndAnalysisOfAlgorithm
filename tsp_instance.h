#pragma once

#include <string>
#include <vector>

enum class InstanceType
{
    TSP
};

enum class EdgeWeightType
{
    EXPLICIT
};

enum class EdgeWeightFormat
{
    UPPER_ROW
};

class tsp_instance
{
private:
    std::string _name;
    InstanceType _type;
    std::string _comment;
    std::vector<int> _dimension;
    EdgeWeightType _edgeWeightType;
    std::vector<std::vector<int>> _weights;

public:
    tsp_instance(std::string filepath);
    // ~tsp_instance();
    std::string name();
    InstanceType type();
    std::string comment();
    std::vector<int> dimension();
    EdgeWeightType edgeWeightType();
    std::vector<std::vector<int>> weights();
};
