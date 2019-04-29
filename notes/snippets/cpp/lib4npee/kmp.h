#pragma once

#include <string>

namespace npee {
namespace ch4 {

void getnext(std::string substr, int next[]);
int KMP(std::string str, std::string substr, int next[]);

}  // namespace ch4
};  // namespace npee

#include "impl/kmp.cpp"