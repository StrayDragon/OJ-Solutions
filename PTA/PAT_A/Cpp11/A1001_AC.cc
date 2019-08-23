// ---
// id         : 1001
// title      : A+B Format
// difficulty : Easy
// score      : 20
// tag        : Simple Simulation
// keyword    : string; conversion
// status     : AC
// from       : PAT (Advanced Level) Practice
// ---

#include <iostream>
#include <iterator>
#include <string>

using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  string s{to_string(a + b)};
  int cnt = 0;
  for (int i = s.size(); s.size() > 3 && i >= 0; --i) {
    if ((i - 2) >= 0 && s[i - 2] == '-')
      break;
    cnt++;
    if (cnt % 3 == 0) {
      if ((i - 1) >= 0) {
        s.insert(i - 1, 1, ',');
        i--;
        cnt = 1;
      }
    }
  }
  cout << s << '\n';

  return 0;
}