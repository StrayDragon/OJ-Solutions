// 参考: https://www.liuchuo.net/archives/2021
// 贪心?动态规划?

#include <algorithm>
#include <cstdio>

using namespace std;

const int MAXN = 100010;
int d[MAXN];

int main() {
  // int n;
  // scanf("%d", &n);
  // for (int i = 1; i <= n; i++)
  //   scanf("%d", &d[i]);
  // int m;
  // scanf("%d", &m);
  // for (int s, e, sum, rsum; m--;) {
  //   scanf("%d %d", &s, &e);
  //   int left = std::min(s, e);
  //   int right = std::max(s, e);
  //   sum = rsum = 0;
  //   for (int i = left; i != right; i++)
  //     sum += d[i];

  //   for (int i = left - 1;; i--) {
  //     if (i == 0)
  //       i = n;
  //     rsum += d[i];
  //     if (i == right)
  //       break;
  //   }
  //   printf("%d\n", std::min(sum, rsum));
  // }
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