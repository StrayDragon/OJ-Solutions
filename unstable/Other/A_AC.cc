#include <cmath>
#include <iostream>
using namespace std;

void calculate_maximum_proper_fraction(int n) {
  double average = (double)n / 2;

  if (n % 2 != 0) {  // n 为奇数
    cout << floor(average) << " " << ceil(average) << '\n';
  } else {
    if ((int)average % 2 == 0) {  // n 为偶数 [average] 为偶数
      cout << floor(average) - 1 << " " << ceil(average) + 1 << '\n';
    } else {  // n 为偶数 [average] 为奇数
      cout << floor(average) - 2 << " " << ceil(average) + 2 << '\n';
    }
  }
}

int main() {
  int T;
  while (cin >> T) {
    for (int n, case_cnt = 1; T--;) {
      cout << "Case #" << case_cnt++ << ":\n";
      cin >> n;
      calculate_maximum_proper_fraction(n);
    }
  }
  return 0;
}