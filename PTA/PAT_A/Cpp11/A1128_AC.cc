// ---
// id         : 1128
// title      : N Queens Puzzle
// difficulty : Easy
// score      : 20
// tag        : TODO
// keyword    : TODO
// status     : AC
// from       : PAT (Advanced Level) Practice
// ---

#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int k;
  cin >> k;
  for (int n, i = 0; i < k; i++) {
    cin >> n;
    vector<int> records(n);
    bool is_solution = true;
    for (int j = 0; j < n; j++) {
      cin >> records[j];
      for (int t = 0; t < j; t++) {
        if (/* 同一行 */ records[j] == records[t] ||
            /* 斜对角线 */ abs(records[j] - records[t]) == abs(j - t)) {
          is_solution = false;
          break;
        }
      }
    }
    cout << (is_solution == true ? "YES\n" : "NO\n");
  }
  return 0;
}