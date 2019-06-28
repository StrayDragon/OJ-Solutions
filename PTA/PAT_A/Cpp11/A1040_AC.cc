// reference: https://www.liuchuo.net/archives/2104

#include <iostream>
#include <string>

using namespace std;

// dp[i][j]: whether s[i] to s[j] is a palindrome string
bool dp[1010][1010];  

int main() {
  string s;
  std::getline(cin, s);

  // init dp [1, 2]
  int len = s.size(), count = 1;
  for (int i = 0; i < len; i++) {
    dp[i][i] = true;
    if (i < len - 1 && s[i] == s[i + 1]) {
      dp[i][i + 1] = true;
      count = 2;
    }
  }

  // calculate dp [3..len]
  for (int cnt = 3; cnt <= len; cnt++) {
    for (int i = 0; i + cnt - 1 < len; i++) {
      int j = i + cnt - 1;
      if (s[i] == s[j] && dp[i + 1][j - 1]) {
        dp[i][j] = true;
        count = cnt;
      }
    }
  }

  cout << count;
  return 0;
}