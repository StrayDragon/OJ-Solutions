// ---
// id         : 1057
// title      : Stack
// difficulty : Hard
// score      : 30
// tag        : TODO
// keyword    : TODO
// status     : AC
// from       : PAT (Advanced Level) Practice
// ---

#include <cmath>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

#define LOWBIT(x) ((x) & -(x))
#define N 100010

int treearr[N];
stack<int> stk;

void update(int x, int v) {
  for (int i = x; i < N; i += LOWBIT(i)) treearr[i] += v;
}

int get_sum(int x) {
  int sum = 0;
  for (int i = x; i > 0; i -= LOWBIT(i)) sum += treearr[i];
  return sum;
}

void _push(int x) {
  stk.push(x);
  update(x, 1);
}

void _pop() {
  cout << stk.top() << '\n';
  update(stk.top(), -1);
  stk.pop();
}

void _peek_median() {
  int l = 1, r = N, mid, k = (stk.size() + 1) / 2;
  while (l < r) {
    mid = (l + r) / 2;
    if (get_sum(mid) >= k)
      r = mid;
    else
      l = mid + 1;
  }
  cout << l << '\n';
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
        _peek_median();
    }
  }

  return 0;
}