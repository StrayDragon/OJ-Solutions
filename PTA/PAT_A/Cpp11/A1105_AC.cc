// ---
// id         : 1105
// title      : Spiral Matrix
// difficulty : Medium
// score      : 25
// tag        : TODO
// keyword    : TODO
// status     : AC
// from       : PAT (Advanced Level) Practice
// ---

// reference: https://www.liuchuo.net/archives/2073

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, n, m;
  cin >> N;
  for (n = std::sqrt((double)N); n >= 1; n--) {
    if (N % n == 0) {
      m = N / n;
      break;
    }
  }

  vector<int> nums;

  for (int num; cin >> num;)
    nums.push_back(num);

  std::sort(nums.begin(), nums.end(), std::greater<int>());

  vector<vector<int>> board(m, vector<int>(n));
  int level = m / 2 + m % 2, idx = 0;
  for (int i = 0; i < level; i++) {
    for (int j = i; j <= n - 1 - i && idx <= N - 1; j++)
      board[i][j] = nums[idx++];
    for (int j = i + 1; j <= m - 2 - i && idx <= N - 1; j++)
      board[j][n - 1 - i] = nums[idx++];
    for (int j = n - i - 1; j >= i && idx <= N - 1; j--)
      board[m - 1 - i][j] = nums[idx++];
    for (int j = m - 2 - i; j >= i + 1 && idx <= N - 1; j--)
      board[j][i] = nums[idx++];
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cout << board[i][j];
      if (j != n - 1)
        cout << ' ';
    }
    cout << '\n';
  }
  return 0;
}