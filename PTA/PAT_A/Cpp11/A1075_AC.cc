// ---
// id         : 1075
// title      : PAT Judge
// difficulty : Medium
// score      : 25
// tag        : TODO
// keyword    : TODO
// status     : AC
// from       : PAT (Advanced Level) Practice
// ---

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct User {
  int rank, id, total = 0;
  vector<int> scores;
  int perfect_cnt = 0;
  bool at_least_pass_one = false;
};

int main() {
  int n, k, m;
  scanf("%d %d %d", &n, &k, &m);

  vector<User> v(n + 1);
  for (int i = 1; i <= n; i++)
    v[i].scores.resize(k + 1, -1);

  vector<int> fullscores(k + 1);
  for (int i = 1; i <= k; i++)
    scanf("%d", &fullscores[i]);

  for (int id, si, score, i = 0; i < m; i++) {
    scanf("%d %d %d", &id, &si, &score);
    v[id].id = id;
    v[id].scores[si] = std::max(v[id].scores[si], score);
    if (score != -1)
      v[id].at_least_pass_one = true;
    else if (v[id].scores[si] == -1)
      v[id].scores[si] = -2;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= k; j++) {
      if (v[i].scores[j] != -1 && v[i].scores[j] != -2)
        v[i].total += v[i].scores[j];
      if (v[i].scores[j] == fullscores[j])
        v[i].perfect_cnt++;
    }
  }

  std::sort(v.begin() + 1, v.end(), [](const User& lhs, const User& rhs) {
    if (lhs.total != rhs.total)
      return lhs.total > rhs.total;
    else if (lhs.perfect_cnt != rhs.perfect_cnt)
      return lhs.perfect_cnt > rhs.perfect_cnt;
    else
      return lhs.id < rhs.id;
  });

  for (int i = 1; i <= n; i++) {
    v[i].rank = i;
    if (i != 1 && v[i].total == v[i - 1].total)
      v[i].rank = v[i - 1].rank;
  }

  for (int i = 1; i <= n; i++) {
    if (v[i].at_least_pass_one) {
      printf("%d %05d %d", v[i].rank, v[i].id, v[i].total);
      for (int j = 1; j <= k; j++) {
        if (v[i].scores[j] != -1 && v[i].scores[j] != -2)
          printf(" %d", v[i].scores[j]);
        else if (v[i].scores[j] == -1)
          printf(" -");
        else
          printf(" 0");
      }
      printf("\n");
    }
  }
  return 0;
}