// ---
// id         : 1044
// title      : Shopping in Mars
// difficulty : Medium
// score      : 25
// tag        : Primary Algorithm
// keyword    : dichotomy
// status     : AC
// from       : PAT (Advanced Level) Practice
// ---

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int subsum[100010];  // subsum[i] is sum of seqence[1,i], start [1]

int find_right(int l, int r, int target) {
  int mid, lft = l, rgt = r;

  while (lft < rgt) {
    mid = (lft + rgt) / 2;
    if (subsum[mid] > target)
      rgt = mid;
    else
      lft = mid + 1;
  }
  return lft;
}

int main() {
  std::ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    cin >> subsum[i];
    subsum[i] += subsum[i - 1];
  }

  int target = 0xFFFFFFFF / 4;
  for (int lft = 1; lft <= n; lft++) {
    int rgt = find_right(lft, n + 1, subsum[lft - 1] + m);
    if (subsum[rgt - 1] - subsum[lft - 1] == m) {
      target = m;
      break;
    } else if (rgt <= n && subsum[rgt] - subsum[lft - 1] < target) {
      target = subsum[rgt] - subsum[lft - 1];
    }
  }

  for (int i = 1; i <= n; i++) {
    int j = find_right(i, n + 1, subsum[i - 1] + target);
    if (subsum[j - 1] - subsum[i - 1] == target) {
      cout << i << '-' << (j - 1) << '\n';
    }
  }

  return 0;
}