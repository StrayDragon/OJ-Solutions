#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main() {
  std::vector<int> v{1, 2, 3, 4, 5, 6};
  int step = 4;
  for (int i = 0; i + step <= 6; i += step) {
    auto it = std::begin(v) + i;
    auto last = std::begin(v) + step + i;
    std::cout << std::distance(std::begin(v), it) << " ";
    std::cout << std::distance(std::begin(v), last) << " ";
    std::cout << std::distance(it, last) << std::endl;
    std::reverse(it, last);
  }

  for (auto e : v) std::cout << e << " ";
}
