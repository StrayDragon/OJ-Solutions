// ---
// id         : 1078
// title      : Hashing
// difficulty : Medium
// score      : 25
// tag        : TODO
// keyword    : TODO
// status     : AC
// from       : PAT (Advanced Level) Practice
// ---

#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

auto is_prime([](int n) {
  if (n <= 1) return false;
  int sqr = std::sqrt(n);
  for (int i = 2; i <= sqr; i++) {
    if (n % i == 0) return false;
  }
  return true;
});

bool table[12345] = {false};

int main() {
  int n, tsize;
  cin >> tsize >> n;
  while (!is_prime(tsize)) tsize++;
  for (int key, i = 0; i < n; i++) {
    cin >> key;
    int m = key % tsize;
    if (!table[m]) {
      table[m] = true;
      if (i == 0)
        cout << m;
      else
        cout << " " << m;
    } else {
      int step;
      for (step = 1; step < tsize; step++) {
        m = (key + step * step) % tsize;
        if (!table[m]) {
          table[m] = true;
          if (i == 0)
            cout << m;
          else
            cout << " " << m;
          break;
        }
      }
      if (step >= tsize) {
        if (i > 0) cout << ' ';
        cout << '-';
      }
    }
  }

  return 0;
}