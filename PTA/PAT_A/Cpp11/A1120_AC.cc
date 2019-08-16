// ---
// id         : 1120
// title      : Friend Numbers
// difficulty : Easy
// score      : 20
// tag        : TODO
// keyword    : TODO
// status     : AC
// from       : PAT (Advanced Level) Practice
// ---

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  vector<int> friend_ids;
  int n;
  cin >> n;
  for (string digits; n--;) {
    cin >> digits;
    int tmp_sum = 0;
    for (auto& digit : digits)
      tmp_sum += digit - '0';
    friend_ids.push_back(tmp_sum);
  }
  std::sort(friend_ids.begin(), friend_ids.end());
  auto last = std::unique(friend_ids.begin(), friend_ids.end());
  cout << std::distance(friend_ids.begin(), last) << '\n';
  cout << *friend_ids.begin();
  std::for_each(friend_ids.begin() + 1, last,
                [](int id) { cout << " " << id; });

  return 0;
}