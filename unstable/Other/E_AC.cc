#include <cmath>
#include <iostream>
using namespace std;

int main() {
  int T, n, that_man = 0, case_cnt = 1;
  cin >> T;
  while (T--) {
    cin >> n;
    cout << "Case #" << case_cnt++ << ":\n";
    for (int man, _ = 0; _ < n * 2 - 1; _++) {
      cin >> man;
      that_man ^= man;
    }
    cout << that_man << '\n';
    that_man = 0;
  }
  return 0;
}