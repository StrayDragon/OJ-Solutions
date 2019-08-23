// ---
// id         : 1046
// title      : Shortest Distance
// difficulty : Easy
// score      : 20
// tag        : Simple Simulation
// keyword    : symmetry problem
// status     : AC
// from       : PAT (Advanced Level) Practice
// reference  : https://www.liuchuo.net/archives/2021
// ---

#include <algorithm>
#include <cstdio>

using namespace std;

const int MAXN = 100010;
int d[MAXN];

int main() {
  int n;
  scanf("%d", &n);
  int sum = 0;
  for (int tmp, i = 1; i <= n; i++) {
    scanf("%d", &tmp);
    sum += tmp;
    d[i] = sum;
  }

  int m;
  scanf("%d", &m);
  for (int left, right, i = 0; i < m; i++) {
    scanf("%d %d", &left, &right);
    if (left > right)
      std::swap(left, right);
    int tmp = d[right - 1] - d[left - 1];
    printf("%d\n", std::min(tmp, sum - tmp));
  }
  return 0;
}