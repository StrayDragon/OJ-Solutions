// ---
// id         : 1089
// title      : Insert or Merge
// difficulty : Medium
// score      : 25
// tag        : Primary Algorithm
// keyword    : two pointers
// status     : AC
// from       : PAT (Advanced Level) Practice
// ---

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

#define A2Y(x) (x).begin(), ((x).begin() + (x).size() - 1)
int main() {
  int n;
  cin >> n;
  vector<int> ori(n), tmp_ori(n), seq(n);
  for (int i = 0; i < n; i++) {
    cin >> ori[i];
    tmp_ori[i] = ori[i];
  }

  for (int i = 0; i < n; i++) {
    cin >> seq[i];
  }

  auto is_insertion_sort([&]() -> bool {
    bool flag = false;
    for (int i = 1; i < n; i++) {
      if (i != 1 && tmp_ori == seq) flag = true;
      int t = tmp_ori[i], j = i;
      while (j > 0 && tmp_ori[j - 1] > t) {
        tmp_ori[j] = tmp_ori[j - 1];
        j--;
      }
      tmp_ori[j] = t;
      if (flag) return true;
    }
    return false;
  });

  auto merge_sort([&]() {
    bool flag = false;
    for (int step = 2; step / 2 <= n; step *= 2) {
      if (step != 2 && tmp_ori == seq) flag = true;
      for (int i = 0; i < n; i += step) {
        std::sort(tmp_ori.begin() + i, tmp_ori.begin() + std::min(i + step, n));
      }
      if (flag) return;
    }
  });

  if (is_insertion_sort()) {
    cout << "Insertion Sort\n";
    std::copy(A2Y(tmp_ori), ostream_iterator<int>(cout, " "));
    cout << tmp_ori.back() << '\n';
  } else {
    cout << "Merge Sort\n";
    tmp_ori = ori;
    merge_sort();
    std::copy(A2Y(tmp_ori), ostream_iterator<int>(cout, " "));
    cout << tmp_ori.back() << '\n';
  }

  return 0;
}