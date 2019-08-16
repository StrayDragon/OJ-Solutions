// ---
// id         : 1069
// title      : The Black Hole of Numbers
// difficulty : Easy
// score      : 20
// tag        : TODO
// keyword    : TODO
// status     : AC
// from       : PAT (Advanced Level) Practice
// ---

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

void self_pad(string& s) {
  switch (s.size()) {
    case 1:
      s = "000" + s;
      break;
    case 2:
      s = "00" + s;
      break;
    case 3:
      s = "0" + s;
      break;
  }
}

string sub(const string& lhs, const string& rhs) {
  stringstream ss;
  ss << lhs << " " << rhs;

  int a, b;
  ss >> a >> b;
  string res = to_string(a - b);
  self_pad(res);
  return res;
}

#define ALL(c) (c).begin(), (c).end()

int main() {
  string n;
  for (string a, b; cin >> n;) {
    self_pad(n);
    do {
      std::sort(ALL(n), [](char lhs, char rhs) { return lhs > rhs; });
      a = n;
      std::reverse(ALL(n));
      b = n;
      n = sub(a, b);
      cout << a << " - " << b << " = " << n << '\n';
    } while (n != "0000" && n != "6174");
  }

  return 0;
}