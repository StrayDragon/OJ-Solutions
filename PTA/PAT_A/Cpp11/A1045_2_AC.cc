// ---
// id         : A1045_2
// title      : Favorite Color Stripe
// difficulty : Hard
// score      : 30
// tag        : TODO
// keyword    : TODO
// status     : AC
// from       : PAT (Advanced Level) Practice
// ---

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define ALL(x) begin(x), end(x)
#define UNLIKE -1

int target[10010], pattern[10010];

template <typename T>
int LCS(T& target, T& pattern, int t_size, int p_size) {
  static int dp[10010][10010];
  for (int i = 0; i <= t_size; i++) dp[i][0] = 0;
  for (int i = 0; i <= p_size; i++) dp[0][i] = 0;

  for (int i = 1; i <= t_size; i++) {
    for (int j = 1; j <= p_size; j++) {
      int m = std::max(dp[i - 1][j], dp[i][j - 1]);
      if (target[i] == pattern[j]) {
        dp[i][j] = m + 1;
      } else {
        dp[i][j] = m;
      }
    }
  }

  return dp[t_size][p_size];
}
int main() {
  int _, m;
  cin >> _ >> m;
  for (int e, i = 1; i <= m && cin >> e; i++) target[i] = e;

  int l;
  cin >> l;
  for (int e, i = 1; i <= l && cin >> e; i++) pattern[i] = e;

  cout << LCS(target, pattern, m, l);
  return 0;
}