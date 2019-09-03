// ---
// id         : 1038
// title      : Recover the Smallest Number
// difficulty : Hard
// score      : 30
// tag        : Primary Algorithm
// keyword    : greedy
// status     : AC
// from       : PAT (Advanced Level) Practice
// ---

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<string> nums(10010);
  for (int i = 0; i < n; i++) cin >> nums[i];

  std::sort(nums.begin(), nums.begin() + n,
            [](string& lhs, string& rhs) { return lhs + rhs < rhs + lhs; });
  string res;
  for (auto&& num : nums) res += num;
  for (; res.size() != 0 && res[0] == '0';) res.erase(res.begin());

  cout << (res.size() == 0 ? "0" : res);
  return 0;
}