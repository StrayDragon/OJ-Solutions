#pragma once
#include <vector>

namespace oj {
namespace twopointer {

void reverse_n_elements(std::vector<int> sequence, int step);

void std_reverse_n_elements(std::vector<int> sequence, int step);

}  // namespace twopointer

void example_reverse_n_elements();

}  // namespace oj

#include "impl/reverse_n_elements.cpp"