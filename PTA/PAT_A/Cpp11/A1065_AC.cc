// ---
// id         : 1065
// title      : A+B and C (64bit)
// difficulty : Easy
// score      : 20
// tag        : Simple Simulation
// keyword    : number accuracy
// status     : AC
// from       : PAT (Advanced Level) Practice
// ---

#include <iostream>

using namespace std;
int main() {
  int n;
  cin >> n;
  long long a, b, c;

  for (int case_cnt = 1; case_cnt <= n; case_cnt++) {
    cin >> a >> b >> c;
    bool flag;  // true 为正溢出 ,false 为负溢出,
    long long sum = a + b;
    if (a > 0 && b > 0 && sum < 0)
      flag = true;
    else if (a < 0 && b < 0 && sum >= 0)
      flag = false;
    else if (sum > c)
      flag = true;
    else
      flag = false;

    cout << "Case #" << case_cnt << ": " << boolalpha << flag << '\n';
  }

  return 0;
}