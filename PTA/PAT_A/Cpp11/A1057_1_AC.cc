// ---
// id         : 1057_1
// title      : Stack
// difficulty : Hard
// score      : 30
// tag        : TODO
// keyword    : TODO
// status     : AC
// from       : PAT (Advanced Level) Practice
// ---

#include <iostream>
#include <stack>
#include <string>

using namespace std;

#define MEDIAN(x) ((x % 2) ? ((x + 1) / 2) : (x / 2))
#define N 100010
#define SQRT_N 316
#define HASH(x) (x / SQRT_N)

stack<int> stk;
int block[SQRT_N], table[N];

void _push(int x) {
  stk.push(x);
  block[HASH(x)]++;
  table[x]++;
}

void _pop() {
  int t = stk.top();
  stk.pop();
  block[HASH(t)]--;
  table[t]--;
  cout << t << '\n';
}

void _peek_median(int k) {
  int cnt = 0, block_i = 0;
  while (cnt + block[block_i] < k) cnt += block[block_i++];
  int i = block_i * SQRT_N;
  while (cnt + table[i] < k) cnt += table[i++];
  cout << i << '\n';
}

int main() {
  int n;
  cin >> n;

  for (string cmd; n-- && cin >> cmd;) {
    if (cmd == "Push") {
      int key;
      cin >> key;
      _push(key);
    } else if (cmd == "Pop") {
      if (stk.empty())
        cout << "Invalid\n";
      else
        _pop();
    } else if (cmd == "PeekMedian") {
      if (stk.empty())
        cout << "Invalid\n";
      else
        _peek_median(MEDIAN(stk.size()));
    }
  }

  return 0;
}