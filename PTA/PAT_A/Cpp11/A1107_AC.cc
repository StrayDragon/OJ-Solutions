// ---
// id         : 1107
// title      : Social Clusters
// difficulty : Hard
// score      : 30
// tag        : TODO
// keyword    : TODO
// status     : AC
// from       : PAT (Advanced Level) Practice
// ---

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define N 1010

int ufs[N], hoppies[N], is_root[N];

void _init(int n) {
  for (int i = 1; i <= n; i++) ufs[i] = i;
}

int _find_root(int x) {
  int t = x;
  while (x != ufs[x]) x = ufs[x];
  while (t != ufs[t]) ufs[std::exchange(t, ufs[t])] = x;
  return x;
}

void _union(int a, int b) {
  int ra = _find_root(a);
  int rb = _find_root(b);
  if (ra != rb) ufs[ra] = rb;
}

int main() {
  int n;
  cin >> n;
  _init(n);
  for (int k, i = 1; i <= n && scanf("%d:", &k) == 1; i++) {
    for (int h, j = 0; j < k && cin >> h; j++) {
      if (hoppies[h] == 0) hoppies[h] = i;
      _union(i, _find_root(hoppies[h]));
    }
  }

  for (int i = 1; i <= n; i++) is_root[_find_root(i)]++;

  int cnt = 0;
  for (int i = 1; i <= n; i++)
    if (is_root[i]) cnt++;

  std::sort(is_root + 1, is_root + n + 1, greater<int>());

  cout << cnt << '\n';
  for (int i = 1; i <= cnt; i++) {
    cout << is_root[i];
    if (i < cnt) cout << ' ';
  }

  return 0;
}