#include <algorithm>
#include <cstdio>
using namespace std;

const int MAXN = 100010;
struct Node {
  int address, key, next;
  bool is_valid;
} node[MAXN];

int main() {
  int n, cnt = 0, s, addr, key, next;
  scanf("%d%d", &n, &s);
  for (int i = 0; i < n; i++) {
    scanf("%d%d%d", &addr, &key, &next);
    node[addr] = {addr, key, next, false};
  }
  for (int i = s; i != -1; i = node[i].next) {
    node[i].is_valid = true;
    cnt++;
  }
  if (cnt == 0) {
    printf("0 -1");
  } else {
    sort(node, node + MAXN, [](Node& addr, Node& key) {
      return !addr.is_valid || !key.is_valid ? addr.is_valid > key.is_valid
                                           : addr.key < key.key;
    });
    printf("%d %05d\n", cnt, node[0].address);
    for (int i = 0; i < cnt; i++) {
      printf("%05d %d ", node[i].address, node[i].key);
      if (i != cnt - 1)
        printf("%05d\n", node[i + 1].address);
      else
        printf("-1\n");
    }
  }
  return 0;
}
