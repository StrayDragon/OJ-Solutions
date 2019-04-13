#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

inline bool is_odd(int n) {
  return n % 2 == 0;
};

int main() {
  int N, case_cnt = 1;
  vector<int> cakes;
  while (cin >> N) {
    cakes.push_back(0);
    cout << "Case #" << case_cnt++ << ":\n";
    for (long long cake, _ = 0; _ < N; _++) {
      cin >> cake;
      cakes.push_back(cake);
    }
    std::sort(cakes.begin(), cakes.end());
    if (is_odd(N)) {
      int lhand = N / 2, rhand = lhand + 1;
      printf("%.2lf\n", double(cakes[lhand]) / 2 + double(cakes[rhand]) / 2);
    } else {
      printf("%.2lf\n", double(cakes[(N + 1) / 2]));
    }

    cakes.clear();
  }

  return 0;
}