// ---
// id         : 1140
// title      : Look-and-say Sequence
// difficulty : Easy
// score      : 20
// tag        : TODO
// keyword    : TODO
// status     : AC
// from       : PAT (Advanced Level) Practice
// ---

#include <iostream>
#include <string>

using namespace std;

int main() {
  int n, j;
  string d;
  cin >> d >> n;
  for (int cnt = 1; cnt < n; cnt++) {
    string t;
    for (int i = 0; i < d.size(); i = j) {
      for (j = i; j < d.size() && d[j] == d[i]; j++)
        ;
      t += d[i] + to_string(j - i);
    }
    d = t;
  }
  cout << d;
  return 0;
}