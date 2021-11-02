#pragma once

#include <vector>

int inversion(std::vector<int> &A);
int inversion(std::vector<int> &A, int left, int right);
int inversion_merge(std::vector<int> &A, int left, int pivot, int right);