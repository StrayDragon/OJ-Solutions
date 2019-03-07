#include <iostream>
#include <map>
using namespace std;
int main() {
  int n, p = 0, t = 0;
  string s;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s;
    map<char, int> m;
    for (int j = 0; j < s.size(); j++) {
      m[s[j]]++;
      if (s[j] == 'P')
        p = j;
      if (s[j] == 'T')
        t = j;
    }
    if (m['P'] == 1 &&  // P 只能出现一次
        m['A'] != 0 &&  // A 至少出现一次或多次,出现多次的规则由条件2,3推论得出
        m['T'] == 1 &&    // T 只能出现一次
        m.size() == 3 &&  //不能出现除了 P,A,T 之外的字符
        t - p != 1 &&     // 限定次序?
        p * (t - p - 1) == s.length() - t - 1  //这是什么鬼 ?_?
    )
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}