// ---
// id         : 1101
// title      : Quick Sort
// difficulty : Medium
// score      : 25
// tag        : Primary Algorithm
// keyword    :
// status     : AC
// from       : PAT (Advanced Level) Practice
// ---

#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

#define N 100010

int nums[N], left_max_at[N], right_min_at[N];
int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) cin >> nums[i];

  left_max_at[0] = 0;
  for (int i = 1; i < n; i++)
    left_max_at[i] = std::max(left_max_at[i - 1], nums[i - 1]);

  right_min_at[n - 1] = INT_MAX;
  for (int i = n - 2; i >= 0; i--)
    right_min_at[i] = std::min(right_min_at[i + 1], nums[i + 1]);

  vector<int> pivots;
  for (int i = 0; i < n; i++) {
    if (left_max_at[i] < nums[i] && nums[i] < right_min_at[i]) {
      pivots.push_back(nums[i]);
    }
  }

  cout << pivots.size() << '\n';
  for (int i = 0; i < pivots.size(); i++) {
    cout << pivots[i];
    if (i != pivots.size() - 1) cout << ' ';
  }
  cout << '\n';

  return 0;
}