// ---
// id         : 1113
// title      : Integer Set Partition
// difficulty : Medium
// score      : 25
// tag        : TODO
// keyword    : TODO
// status     : AC
// from       : PAT (Advanced Level) Practice
// ---

// reference: https://www.liuchuo.net/archives/2299

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  size_t n;
  cin >> n;

  int sum = 0;
  vector<int> nums(n);
  for (size_t i = 0; i < n; i++) {
    cin >> nums[i];
    sum += nums[i];
  }

  std::sort(nums.begin(), nums.end());

  int haftsum = 0;
  for (size_t i = 0; i < n / 2; i++) {
    haftsum += nums[i];
  }
  cout << (n % 2) << " " << sum - 2 * haftsum;

  return 0;
}