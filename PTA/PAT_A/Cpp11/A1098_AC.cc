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

  auto heap_sort([&]() {
    auto down_adjust([&](int low, int high) {
      for (int i = low, j = i * 2 + 1; j <= high;) {
        if (j + 1 <= high && tmp_ori[j + 1] > tmp_ori[j]) j++;
        if (tmp_ori[j] > tmp_ori[i]) {
          std::swap(tmp_ori[j], tmp_ori[i]);
          i = j;
          j = i * 2 + 1;
        } else {
          break;
        }
      }
    });

    for (int i = n / 2; i >= 0; i--) {
      down_adjust(i, n - 1);
    }

    bool flag = false;
    for (int i = n - 1; i > 0; i--) {
      if (i != n - 1 && tmp_ori == seq) flag = true;
      std::swap(tmp_ori[i], tmp_ori[0]);
      down_adjust(0, i - 1);
      if (flag) return;
    }
  });

  if (is_insertion_sort()) {
    cout << "Insertion Sort\n";
    std::copy(A2Y(tmp_ori), ostream_iterator<int>(cout, " "));
    cout << tmp_ori.back() << '\n';
  } else {
    cout << "Heap Sort\n";
    tmp_ori = ori;
    heap_sort();
    std::copy(A2Y(tmp_ori), ostream_iterator<int>(cout, " "));
    cout << tmp_ori.back() << '\n';
  }

  return 0;
}