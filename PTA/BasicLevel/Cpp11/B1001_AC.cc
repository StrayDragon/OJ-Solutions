#include <cstdio>
int main() {
  int n = 0, cnt = 0;
  scanf("%d", &n);
  for (; n != 1; ++cnt) {
    if (n % 2 == 0) {
      n /= 2;
    } else {
      n = (3 * n + 1) / 2;
    }
  }
  printf("%d\n", cnt);
  return 0;
}