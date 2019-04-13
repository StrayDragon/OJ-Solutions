#include <cmath>
#include <iostream>
using namespace std;

int main() {
  int T, n, that_men = 0, case_cnt = 1;
  cin >> T;
  while (T--) {
    cin >> n;
    cout << "Case #" << case_cnt++ << ":\n";
    for (int men, _ = 0; _ < n * 2 - 1; _++) {
      cin >> men;
      that_men ^= men;
    }
    cout << that_men << '\n';
    that_men = 0;
  }
  return 0;
}