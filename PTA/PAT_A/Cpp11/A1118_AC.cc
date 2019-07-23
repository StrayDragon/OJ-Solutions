/// need c++14

#include <iostream>
#include <utility>
using namespace std;

#define MAXN 10010

int ufs[MAXN], visited[MAXN], cnt[MAXN];
int ufs_find_root(int x) {
  int t = x;
  while (x != ufs[x]) x = ufs[x];
  while (t != ufs[t]) ufs[std::exchange(t, ufs[t])] = x;
  // while (t != ufs[t]) {
  //   int a = ufs[t];
  //   t = ufs[t];
  //   ufs[a] = t;
  // }
  return x;
}

void ufs_union(int a, int b) {
  int ra = ufs_find_root(a);
  int rb = ufs_find_root(b);
  if (ra != rb) ufs[ra] = rb;
}

int main() {
  for (int i = 1; i < MAXN; i++) ufs[i] = i;

  int n;
  cin >> n;
  for (int _, first; n-- && cin >> _ >> first;) {
    visited[first] = true;
    for (int t, k = _ - 1; k-- && cin >> t;) {
      ufs_union(first, t);
      visited[t] = true;
    }
  }

  for (int i = 1; i < MAXN; i++) {
    if (visited[i]) cnt[ufs_find_root(i)]++;
  }

  int trees_cnt = 0, brids_cnt = 0;
  for (int i = 1; i < MAXN; i++) {
    if (visited[i] && cnt[i] != 0) {
      trees_cnt++;
      brids_cnt += cnt[i];
    }
  }
  cout << trees_cnt << ' ' << brids_cnt << '\n';

  int m;
  cin >> m;
  for (int a, b; m--;) {
    cin >> a >> b;
    cout << (ufs_find_root(a) == ufs_find_root(b) ? "Yes\n" : "No\n");
  }

  return 0;
}