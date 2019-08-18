#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename T>
int LIS(T& seq) {
  static int dp[100];
  int res = -1, size = std::distance(begin(seq), end(seq)) - 1;
  for (int i = 1; i <= size; i++) {
    dp[i] = 1;
    for (int j = 1; j < i; j++) {
      if (seq[i] >= seq[j] && dp[j] + 1 > dp[i]) {
        dp[i] = dp[j] + 1;
      }
    }
    res = std::max(res, dp[i]);
  }
  return res;
}

template <typename T>
int LCS(T& target, T& pattern) {
  static int dp[100][100];
  int t_size = std::distance(begin(target), end(target)) - 1;
  int p_size = std::distance(begin(pattern), end(pattern)) - 1;
  for (int i = 0; i <= t_size; i++) dp[i][0] = 0;
  for (int i = 0; i <= p_size; i++) dp[0][i] = 0;

  for (int i = 1; i <= t_size; i++) {
    for (int j = 1; j <= p_size; j++) {
      if (target[i] == pattern[j]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }

  return dp[t_size][p_size];
}

int main() {
  vector<int> seq{0xcafe, 1, 2, 3, -9, 3, 9, 0, 11};
  cout << "LIS: seq\t" << LIS(seq) << '\n';
  int seq2[] = {0xcafe, 1, 5, -1, 3};
  cout << "LIS: seq2\t" << LIS(seq2) << '\n';
  LCS(seq, seq);

  string target{" sadstory"};
  string pattern{" adminsorry"};
  cout << "LCS:\n"
       << "\ttarget:\t\t" << target << "\n\tpattern:\t" << pattern << '\n'
       << "result: " << LCS(target, pattern) << '\n';

  return 0;
}