#pragma once

#include <string>

namespace npee {
namespace ch4 {

void getnext(std::string substr, int next[]) {
  int i = 1, j = 0;
  next[1] = 0;
  while (i < substr.size()) {
    if (j == 0 || substr[i] == substr[j]) {
      ++i;
      ++j;
      next[i] = j;
    } else
      j = next[j];
  }
}

int KMP(std::string str, std::string substr, int next[]) {
  int i = 1, j = 0;
  while (i <= str.size() && j <= substr.size()) {
    if (j == 0 || str[i] == substr[j]) {
      ++i;
      ++j;
    } else
      j = next[j];
  }
  if (j > substr.size())
    return i - substr.size();
  else
    return 0;
}

}  // namespace ch4
}  // namespace npee
