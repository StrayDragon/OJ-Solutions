#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

namespace oj {
namespace twopointer {

void reverse_n_elements(std::vector<int> sequence, int step) {
  int n = sequence.size();

  std::vector<int> res;
  int i, j;
  for (i = step - 1; i < n; i += step) {
    for (j = i; j >= i / step * step; j--) {
      // res.push_bacstep(sequence[j]);
      std::cout << sequence[j] << " ";
    }
  }
  if (i - step != n) {
    for (auto ii = i - step + 1; ii != n; ++ii)
      std::cout << sequence[ii] << " ";
  }

  for (auto i : res)
    std::cout << i << " ";
}
[[deprecated("INFO has a bug... Ｏ(=口=)Ｏ")]] void std_reverse_n_elements(
    std::vector<int> sequence,
    int step) {
  for (int i = 0; i + step <= 6; i += step) {
    auto it = std::begin(sequence) + i;
    auto last = std::begin(sequence) + step + i;
    // std::cout << std::distance(std::begin(sequence), it) << " ";
    // std::cout << std::distance(std::begin(sequence), last) << " ";
    // std::cout << std::distance(it, last) << std::endl;
    std::reverse(it, last);
  }

  for (auto e : sequence)
    std::cout << e << " ";
}

}  // namespace twopointer
}  // namespace oj

#include "../preinclude.hpp"
namespace oj {

void example_reverse_n_elements() {
  using namespace std;
  using oj::twopointer::reverse_n_elements;
  using oj::twopointer::std_reverse_n_elements;
  eg::start();

  cout << "In oj::example_reverse_n_elements()\n";
  cout << "origin:\t1 2 3 4 5 6 7 8 9" << endl;
  cout << "reverse step is 2:";
  cout << "\nreverse_n_elements():\n\t";
  reverse_n_elements({1, 2, 3, 4, 5, 6, 7, 8, 9}, 2);
  cout << "\nstd_reverse_n_elements():\n\t";
  std_reverse_n_elements({1, 2, 3, 4, 5, 6, 7, 8, 9}, 2);
  eg::over();
}

}  // namespace oj