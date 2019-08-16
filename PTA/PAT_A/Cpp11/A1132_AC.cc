// ---
// id         : 1132
// title      : Cut Integer
// difficulty : Easy
// score      : 20
// tag        : TODO
// keyword    : TODO
// status     : AC
// from       : PAT (Advanced Level) Practice
// ---

#include <cmath>
#include <iostream>

using namespace std;

int main() {
  std::ios::sync_with_stdio(false);
  int n;
  cin >> n;
  for (string num; n-- && cin >> num;) {
    string a(num.begin(), num.begin() + num.size() / 2),
        b(num.begin() + num.size() / 2, num.end());
    double res = (stod(num) / (stod(a) * stod(b)));
    cout << (res - floor(res) < 10e-8 ? "Yes\n" : "No\n");
  }
  return 0;
}