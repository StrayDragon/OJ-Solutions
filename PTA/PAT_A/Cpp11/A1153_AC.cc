#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

#define ALL(c) (c).begin(), (c).end()

using Testee = pair<string, int>;
using Result = Testee;

ostream& operator<<(ostream& out, const Result& t) {
  return out << t.first << " " << t.second << '\n';
}

int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<Testee> testees;
  for (Testee testee; n--;) {
    cin >> testee.first >> testee.second;
    testees.push_back(testee);
  }
  for (int type, i = 1; m--;) {
    int cnt = 0, sum = 0;
    string term;
    cin >> type >> term;
    cout << "Case " << (i++) << ": " << type << " " << term << '\n';
    vector<Result> result;
    if (type == 1) {
      for (const auto& t : testees) {
        if (t.first[0] == term[0])
          result.push_back(t);
      }
    } else if (type == 2) {
      for (const auto& t : testees) {
        if (t.first.substr(1, 3) == term) {
          cnt++;
          sum += t.second;
        }
      }
      if (cnt != 0)
        cout << cnt << " " << sum << '\n';
    } else if (type == 3) {
      unordered_map<string, int> dict;
      for (const auto& t : testees) {
        if (t.first.substr(4, 6) == term)
          dict[t.first.substr(1, 3)]++;
      }
      for (const auto& it : dict)
        result.push_back(it);
    }
    std::sort(ALL(result), [](const Result& lhs, const Result& rhs) {
      if (lhs.second == rhs.second)
        return lhs.first < rhs.first;
      return lhs.second > rhs.second;
    });
    for (const auto& res : result)
      cout << res;
    if (((type == 1 || type == 3) && result.empty()) || (type == 2 && cnt == 0))
      cout << "NA\n";
  }

  return 0;
}