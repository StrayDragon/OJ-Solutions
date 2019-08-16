// ---
// id         : 1054
// title      : The Dominant Color
// difficulty : Easy
// score      : 20
// tag        : TODO
// keyword    : TODO
// status     : AC
// from       : PAT (Advanced Level) Practice
// ---

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

static auto __ = [] {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return nullptr;
}();

using namespace std;

int main() {
  int m, n;
  cin >> m >> n;

  unordered_map<int, int> colorcnt_dict;
  for (int digital_color, _ = 0; _ < m * n; _++) {
    cin >> digital_color;
    if (colorcnt_dict.find(digital_color) != colorcnt_dict.end())
      colorcnt_dict[digital_color] += 1;
    else
      colorcnt_dict[digital_color] = 1;
  }

  vector<int> result;
  for (auto& kv : colorcnt_dict)
    if (kv.second > (m * n / 2))
      result.push_back(kv.first);

  cout << result[0];
  for (int i = 1; i < result.size(); i++)
    cout << " " << result[i];
  return 0;
}