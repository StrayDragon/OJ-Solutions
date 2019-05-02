// reference :https://www.liuchuo.net/archives/2075

#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;
bool is_good_key[256];
int main() {
  int k, cnt = 1;
  string s;
  cin >> k >> s;
  unordered_map<char, bool> appear_count_dict;
  unordered_set<char> printed;
  char pre = '$';
  s += '$';
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == pre) {
      cnt++;
    } else {
      if (cnt % k != 0) {
        is_good_key[pre] = true;
      }
      cnt = 1;
    }
    if (i != s.length() - 1)
      appear_count_dict[s[i]] = (cnt % k == 0);
    pre = s[i];
  }
  for (int i = 0; i < s.length() - 1; i++) {
    if (is_good_key[s[i]] == true)
      appear_count_dict[s[i]] = false;
  }
  for (int i = 0; i < s.length() - 1; i++) {
    if (appear_count_dict[s[i]] && printed.find(s[i]) == printed.end()) {
      cout << s[i];
      printed.insert(s[i]);
    }
  }
  cout << '\n';
  for (int i = 0; i < s.length() - 1; i++) {
    cout << s[i];

    if (appear_count_dict[s[i]])
      i = i + k - 1;
  }
  return 0;
}