// ---
// id         : 1032
// title      : Sharing
// difficulty : Medium
// score      : 25
// tag        : TODO
// keyword    : TODO
// status     : AC
// from       : PAT (Advanced Level) Practice
// ---

#include <cstdio>
using namespace std;

struct Node {
  char key;
  int next;
  bool visited;
} nodes[100010];

int main() {
  int s1, s2, n;
  scanf("%d%d%d", &s1, &s2, &n);
  char data;
  for (int addr, next, i = 0; i < n; i++) {
    scanf("%d %c %d", &addr, &data, &next);
    nodes[addr] = {data, next, false};
  }
  for (int i = s1; i != -1; i = nodes[i].next)
    nodes[i].visited = true;
  for (int i = s2; i != -1; i = nodes[i].next) {
    if (nodes[i].visited == true) {
      printf("%05d", i);
      return 0;
    }
  }
  printf("-1");
  return 0;
}