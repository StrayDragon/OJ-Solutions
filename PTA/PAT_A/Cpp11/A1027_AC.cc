// ---
// id         : 1027
// title      : Colors in Mars
// difficulty : Easy
// score      : 20
// tag        : Simple Simulation
// keyword    : conversion
// status     : AC
// from       : PAT (Advanced Level) Practice
// ---

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

string redix_convert(int n) {
  const int BASE = 13;
  string converted;
  do {
    int remain = n % BASE;
    if (remain == 10)
      converted += 'A';
    else if (remain == 11)
      converted += 'B';
    else if (remain == 12)
      converted += 'C';
    else
      converted += '0' + remain;
    n /= BASE;
  } while (n != 0);
  std::reverse(converted.begin(), converted.end());
  return converted;
}

int main() {
  int r, g, b;
  cin >> r >> g >> b;

  cout << "#";
  string R = redix_convert(r), G = redix_convert(g), B = redix_convert(b);
  if (R.size() < 2)
    cout << '0';
  cout << R;

  if (G.size() < 2)
    cout << '0';
  cout << G;
  if (B.size() < 2)
    cout << '0';
  cout << B;

  return 0;
}