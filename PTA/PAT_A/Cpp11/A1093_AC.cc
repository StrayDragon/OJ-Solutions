#include <iostream>
#include <string>
using namespace std;

#define MAXN 100010
#define M 1000000007

int left_p_cnt[MAXN] = {0};
int main() {
  string s;
  cin >> s;

  for (int i = 0; i < s.length(); ++i) {
    if (i) left_p_cnt[i] = left_p_cnt[i - 1];
    if (s[i] == 'P') left_p_cnt[i]++;
  }

  int cnt = 0, right_t_cnt = 0;
  for (int i = s.length() - 1; i >= 0; --i) {
    if (s[i] == 'T')
      right_t_cnt++;
    else if (s[i] == 'A')
      cnt = (cnt + left_p_cnt[i] * right_t_cnt) % M;
  }

  cout << cnt;
  return 0;
}