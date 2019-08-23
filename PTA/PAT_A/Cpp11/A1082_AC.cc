// ---
// id         : 1082
// title      : Read Number in Chinese
// difficulty : Medium
// score      : 25
// tag        : Simple Simulation
// keyword    : string; lexical analysis; two pointer
// status     : AC
// from       : PAT (Advanced Level) Practice
// ---

#include <iostream>
#include <string>

using namespace std;

const string d2hans[] = {
    "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu",
};

const string unit[] = {
    "Shi", "Bai", "Qian", "Wan", "Yi",
};

int main() {
  string digits;
  cin >> digits;
  int it = 0, rit = digits.length() - 1, len = digits.length();
  if (digits[it] == '-') {
    cout << "Fu";
    it++;
  }

  for (; it + 4 <= rit; rit -= 4) {
  }

  for (; it < len; rit += 4) {
    bool zeroes = false, printed = false;
    for (; it <= rit; it++) {
      if (it > 0 && digits[it] == '0') {
        zeroes = true;
      } else {
        if (zeroes) {
          cout << " ling";
          zeroes = false;
        }
        if (it > 0) cout << " ";
        cout << d2hans[digits[it] - '0'];
        printed = true;
        if (it != rit) cout << " " << unit[rit - it - 1];
      }
    }
    if (printed && rit != len - 1) cout << " " << unit[(len - 1 - rit) / 4 + 2];
  }

  return 0;
}