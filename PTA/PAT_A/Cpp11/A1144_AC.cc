// ---
// id         : 1144
// title      : The Missing Number
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

#define ALL(x) (x).begin(), (x).end()

static auto __ = [] {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return nullptr;
}();

using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> nums;
  unordered_map<int, bool> visited;
  for (int num; n--;) {
    cin >> num;
    if (num > 0 && visited.find(num) == visited.end()) {
      nums.push_back(num);
      visited[num] = true;
    }
  }
  sort(ALL(nums));
  int missing_num = 1;
  for (auto num : nums) {
    if (missing_num != num)
      break;
    ++missing_num;
  }
  cout << missing_num << endl;
  return 0;
}