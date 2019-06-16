#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  int cnt = 0;
  for (int now, left, right, divisor = 1; n / divisor != 0; divisor *= 10) {
    left = n / (divisor * 10);
    now = n / divisor % 10;
    right = n % divisor;
    if (now == 0)
      cnt += left * divisor;
    else if (now == 1)
      cnt += left * divisor + right + 1;
    else
      cnt += (left + 1) * divisor;
  }
  cout << cnt;
  return 0;
}