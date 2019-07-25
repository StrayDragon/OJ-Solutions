#include <algorithm>
#include <cstdio>

using namespace std;

#define MAXN 1010

struct Member {
  int id, fid, mid, cids[6], estate, area;
} members[MAXN];

#define MAXID 10010

struct Family {
  int id, cnt;
  double estate, area;
  bool exist = false;
} families[MAXID];

int ufs[MAXID];
int _find_root(int x) {
  while (x != ufs[x]) {
    x = ufs[x];
  }
  return x;
}
void _union(int a, int b) {
  int ra = _find_root(a);
  int rb = _find_root(b);
  if (ra > rb) {
    ufs[ra] = ufs[rb];
  } else if (ra < rb) {
    ufs[rb] = ufs[ra];
  }
}

bool visited[MAXID];

int main() {
  for (int i = 0; i < MAXID; ++i) ufs[i] = i;

  int n;
  scanf("%d", &n);
  for (int k, i = 0; i < n; i++) {
    scanf("%d %d %d %d", &members[i].id, &members[i].fid, &members[i].mid, &k);
    visited[members[i].id] = true;
    if (members[i].fid != -1) {
      visited[members[i].fid] = true;
      _union(members[i].fid, members[i].id);
    }
    if (members[i].mid != -1) {
      visited[members[i].mid] = true;
      _union(members[i].mid, members[i].id);
    }
    for (int j = 0; j < k; j++) {
      scanf("%d", &members[i].cids[j]);
      visited[members[i].cids[j]] = true;
      _union(members[i].cids[j], members[i].id);
    }
    scanf("%d %d", &members[i].estate, &members[i].area);
  }

  for (int i = 0; i < n; i++) {
    int id = _find_root(members[i].id);
    families[id].id = id;
    families[id].exist = true;
    families[id].estate += members[i].estate;
    families[id].area += members[i].area;
  }

  int cnt = 0;
  for (int i = 0; i < MAXID; i++) {
    if (visited[i]) families[_find_root(i)].cnt++;
    if (families[i].exist) cnt++;
  }

  for (int i = 0; i < MAXID; i++) {
    if (families[i].exist) {
      families[i].estate = double(families[i].estate * 1.0 / families[i].cnt);
      families[i].area = double(families[i].area * 1.0 / families[i].cnt);
    }
  }

  std::sort(families, families + MAXID, [](Family& a, Family& b) {
    if (a.area != b.area)
      return a.area > b.area;
    else
      return a.id < b.id;
  });

  printf("%d\n", cnt);
  for (int i = 0; i < cnt; i++)
    printf("%04d %d %.3f %.3f\n", families[i].id, families[i].cnt,
           families[i].estate, families[i].area);

  return 0;
}