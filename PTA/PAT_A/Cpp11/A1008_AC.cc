// ---
// id         : 1008
// title      : Elevator
// difficulty : Easy
// score      : 20
// tag        : TODO
// keyword    : TODO
// status     : AC
// from       : PAT (Advanced Level) Practice
// ---

#include <iostream>
using namespace std;

int main() {
  int _, sum = 0;
  cin >> _;
  for (int target, now = 0; cin >> target; now = target) {
    if (target > now)
      sum += 6 * (target - now);
    else
      sum += 4 * (now - target);
    sum += 5;
  }
  cout << sum;
  return 0;
}