// ---
// id         : 1051
// title      : Pop Sequence
// difficulty : Medium
// score      : 25
// tag        : TODO
// keyword    : TODO
// status     : AC
// from       : PAT (Advanced Level) Practice
// ---

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int m, n, k;
int main() {
  cin >> m >> n >> k;
  for (int i = 0; i < k; i++) {
    vector<int> nums;
    for (int _ = 0, e; _ < n; _++) {
      cin >> e;
      nums.push_back(e);
    }

    stack<int> stk;
    bool invalid = false;
    for (int cur = 0, j = 1; j <= n; j++) {
      stk.push(j);
      if (stk.size() > m) {
        invalid = true;
        break;
      }

      while (!stk.empty() && stk.top() == nums[cur]) {
        stk.pop();
        cur++;
      }
    }

    if (invalid || stk.size() != 0)
      cout << "NO\n";
    else
      cout << "YES\n";
  }

  return 0;
}