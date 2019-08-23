// ---
// id         : 1019
// title      : General Palindromic Number
// difficulty : Easy
// score      : 20
// tag        : Simple Simulation
// keyword    : conversion; binary
// status     : AC
// from       : PAT (Advanced Level) Practice
// ---

#include <iostream>

using namespace std;
int digits[100];
int main() {
  int n, b;
  cin >> n >> b;
  int idx;
  for (idx = 0; n != 0; n /= b)
    digits[idx++] = n % b;
  if (idx == 0)
    digits[idx++] = 0;

  bool is_palindromic = true;
  for (int i = 0, ri = idx - 1; i <= ri; i++, ri--)
    if (digits[i] != digits[ri])
      is_palindromic = false;

  cout << (is_palindromic ? "Yes\n" : "No\n");

  for (int ri = idx - 1; ri >= 0; ri--) {
    cout << digits[ri];
    if (ri != 0)
      cout << " ";
  }

  return 0;
}