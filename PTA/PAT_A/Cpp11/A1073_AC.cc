// ---
// id         : 1073
// title      : Scientific Notation
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

#define ALL(x) (x).begin(), (x).end()
int main() {
  string num;
  cin >> num;

  if (num[0] == '-') cout << '-';

  int e = 0, e_i = num.find('E');
  for (int i = e_i + 2; i < num.size(); i++) {
    e = e * 10 + (num[i] - '0');
  }

  if (e == 0)
    for (int i = 1; i < e_i; i++) cout << num[i];

  if (num[e_i + 1] == '-') {
    cout << "0.";
    for (int i = 0; i < e - 1; i++) {
      cout << "0";
    }
    cout << num[1];
    for (int i = 3; i < e_i; i++) {
      cout << num[i];
    }
  } else {
    for (int i = 1; i < e_i; i++) {
      if (num[i] == '.') continue;
      cout << num[i];
      if (i == e + 2 && e_i - 3 != e) cout << '.';
    }
    for (int i = 0; i < e - (e_i - 3); i++) cout << "0";
  }
  return 0;
}