// ---
// id         : 1035
// title      : Password
// difficulty : Easy
// score      : 20
// tag        : Simple Simulation
// keyword    : string
// status     : AC
// from       : PAT (Advanced Level) Practice
// ---

#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;
#define ALL(x) (x).begin(), (x).end()

vector<pair<char, char>> couples{{'1', '@'},
                                 {'0', '%'},
                                 {'l', 'L'},
                                 {'O', 'o'}};
vector<tuple<string, string, bool>> accounts;

void replace_confused_char(string& s, bool& modified) {
  for (auto& couple : couples) {
    auto pos = s.find(couple.first);
    while (pos != string::npos) {
      s[pos] = couple.second;
      modified = true;
      pos = s.find(couple.first, pos + 1);
    }
  }
}

int main() {
  int n;
  cin >> n;
  string name, passwd;
  bool some_modified = false;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    bool is_modified = false;
    cin >> name >> passwd;
    replace_confused_char(passwd, is_modified);
    if (!some_modified && is_modified)
      some_modified = is_modified;
    if (is_modified)
      cnt++;
    accounts.push_back(tuple<string, string, bool>(name, passwd, is_modified));
  }

  if (some_modified) {
    cout << cnt << '\n';
    for (auto& account : accounts) {
      if (get<2>(account)) {
        cout << get<0>(account) << " " << get<1>(account) << '\n';
      }
    }
  } else {
    int len = accounts.size();
    if (len == 1) {
      printf("There is 1 account and no account is modified\n");
    } else {
      printf("There are %d accounts and no account is modified\n", len);
    }
  }

  return 0;
}