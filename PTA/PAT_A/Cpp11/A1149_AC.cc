// ---
// id         : 1149
// title      : Dangerous Goods Packaging
// difficulty : Medium
// score      : 25
// tag        : TODO
// keyword    : TODO
// status     : AC
// from       : PAT (Advanced Level) Practice
// ---

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
int main() {
  int n, m;
  cin >> n >> m;

  unordered_map<int, vector<int>> dict;
  for (int a, b; n-- && cin >> a >> b;) {
    dict[a].push_back(b);
    dict[b].push_back(a);
  }

  for (; m-- && cin >> n;) {
    bool is_incompatible = false, visited[100000] = {false};
    vector<int> goods;
    for (int good; n-- && cin >> good;) {
      goods.push_back(good);
      visited[good] = true;
    }
    for (int i = 0; i < goods.size(); i++) {
      for (int j = 0; j < dict[goods[i]].size(); j++) {
        if (visited[dict[goods[i]][j]] == true) {
          is_incompatible = true;
        }
      }
    }
    cout << (is_incompatible ? "No\n" : "Yes\n");
  }
  return 0;
}