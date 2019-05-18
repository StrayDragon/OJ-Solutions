#include <iostream>

using namespace std;
int bits[100];
int main() {
  int n, b;
  cin >> n >> b;
  int idx;
  for (idx = 0; n != 0; n /= b)
    bits[idx++] = n % b;
  if (idx == 0)
    bits[idx++] = 0;

  bool is_palindromic = true;
  for (int i = 0, ri = idx - 1; i <= ri; i++, ri--)
    if (bits[i] != bits[ri])
      is_palindromic = false;

  cout << (is_palindromic ? "Yes\n" : "No\n");

  for (int ri = idx - 1; ri >= 0; ri--) {
    cout << bits[ri];
    if (ri != 0)
      cout << " ";
  }

  return 0;
}