// ---
// id         : 1002
// title      : A+B for Polynomials
// difficulty : Medium
// score      : 25
// tag        : TODO
// keyword    : TODO
// status     : AC
// from       : PAT (Advanced Level) Practice
// ---

#include <cstdio>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <utility>

using namespace std;
int main() {
  using polynomial_t = map<int, double, std::greater<int>>;
  polynomial_t result;

  /*读取数据并计算数据*/
  int count, expo;
  double coef;
  while (cin >> count) {
    for (; count != 0 && (cin >> expo >> coef); --count) {
      if (result.find(expo) == result.end()) {
        result[expo] = coef;
      } else {
        result[expo] += coef;
      }
      if (result[expo] == 0)
        result.erase(expo);
    }
  }

  /*下面处理输出*/
  int len = result.size();
  if (len == 0)
    cout << len;
  else
    cout << len << " ";
  for (auto itr = result.begin(); itr != result.end(); ++itr) {
    if (next(itr) == end(result))
      printf("%d %.1lf", itr->first, itr->second);
    else
      printf("%d %.1lf ", itr->first, itr->second);
  }
  return 0;
}