#pragma once
#include <vector>

std::vector<std::vector<float>> prim(std::vector<std::vector<float>>& graph);
std::vector<std::vector<float>> prim_n2(std::vector<std::vector<float>>& graph);

float INF = __FLT_MAX__;