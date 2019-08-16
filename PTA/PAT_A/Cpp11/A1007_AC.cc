// ---
// id         : 1007
// title      : Maximum Subsequence Sum
// difficulty : Medium
// score      : 25
// tag        : TODO
// keyword    : TODO
// status     : AC
// from       : PAT (Advanced Level) Practice
// ---

#include <iostream>

using namespace std;
const int MAXK = 10010;

int k, seq[MAXK];

int main() {
  cin >> k;
  bool all_negative = true;
  for (int i = 0; i < k; i++) {
    cin >> seq[i];
    if (all_negative && seq[i] >= 0)
      all_negative = false;
  }

  int maxsum = -1;
  int left = k - 1, right = k - 1;
  for (int i = 0, sum = 0, it = 0; i < k; i++) {
    sum += seq[i];
    if (maxsum < sum) {
      maxsum = sum;
      left = it;
      right = i;
    } else if (sum < 0) {
      it = i + 1;
      sum = 0;
    }
  }

  if (all_negative) {
    cout << "0 " << seq[0] << " " << seq[k - 1] << '\n';
  } else {
    cout << maxsum << " " << seq[left] << " " << seq[right] << '\n';
  }
  return 0;
}