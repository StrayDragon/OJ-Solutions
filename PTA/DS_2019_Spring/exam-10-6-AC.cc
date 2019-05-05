#include <cstdio>
#include <map>
using namespace std;

struct Node {
  int data;
  bool checked;
};

int main() {
  int n, j = 0, nomovecnt = 0, flag = 0, out;
  scanf("%d", &n);
  Node nodes[n];
  map<int, int> dict;
  for (int i = 0; i < n; i++) {
    scanf("%d", &nodes[i].data);
    nodes[i].checked = false;
    dict[i] = 1;
  }
  while (!dict.empty()) {
    int cnt = 0, i = dict.begin()->first;
    while (nodes[i].checked == false) {
      nodes[i].checked = true;
      i = nodes[i].data;
      dict.erase(i);
      cnt++;
    }
    j++;
    if (cnt == 1) {
      if (i == 0)
        flag = 1;
      nomovecnt++;
    }
  }
  out = n - nomovecnt + j - nomovecnt;
  if (flag == 0)
    out -= 2;
  printf("%d\n", out);
  return 0;
}