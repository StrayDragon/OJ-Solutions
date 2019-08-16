// ---
// id         : 1056
// title      : Mice and Rice
// difficulty : Medium
// score      : 25
// tag        : TODO
// keyword    : TODO
// status     : AC
// from       : PAT (Advanced Level) Practice
// ---

#include <algorithm>
#include <iostream>
#include <iterator>
#include <queue>

using namespace std;

struct Mouse {
  int w, rank;
} mice[1010];

int main() {
  int np, ng;
  cin >> np >> ng;
  for (int i = 0; i < np; i++) {
    cin >> mice[i].w;
  }
  queue<int> que;
  for (int order, i = 0; i < np; i++) {
    cin >> order;
    que.push(order);
  }

  int tmp = np, group;
  while (que.size() != 1) {
    if (tmp % ng == 0)
      group = tmp / ng;
    else
      group = tmp / ng + 1;
    for (int k, i = 0; i < group; i++) {
      k = que.front();
      for (int j = 0; j < ng; j++) {
        if (i * ng + j >= tmp) break;
        int f = que.front();
        if (mice[f].w > mice[k].w) k = f;
        mice[f].rank = group + 1;
        que.pop();
      }
      que.push(k);
    }
    tmp = group;
  }

  mice[que.front()].rank = 1;
  for (int i = 0; i < np; i++) {
    cout << mice[i].rank;
    if (i < np - 1) cout << " ";
  }
  return 0;
}