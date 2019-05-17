// refer : https://www.liuchuo.net/archives/1906

#include <cmath>
#include <iostream>
using namespace std;
long long a, b, c, d;
long long gcd(long long t1, long long t2) {
  return t2 == 0 ? t1 : gcd(t2, t1 % t2);
}
void reduce_and_print(long long m, long long n) {
  if (m * n == 0) {
    printf("%s", n == 0 ? "Inf" : "0");
    return;
  }
  bool flag = ((m < 0 && n > 0) || (m > 0 && n < 0));
  m = abs(m);
  n = abs(n);
  long long x = m / n;
  printf("%s", flag ? "(-" : "");
  if (x != 0)
    printf("%lld", x);
  if (m % n == 0) {
    if (flag)
      printf(")");
    return;
  }
  if (x != 0)
    printf(" ");
  m = m - x * n;
  long long t = gcd(m, n);
  m = m / t;
  n = n / t;
  printf("%lld/%lld%s", m, n, flag ? ")" : "");
}
int main() {
  scanf("%lld/%lld %lld/%lld", &a, &b, &c, &d);
  reduce_and_print(a, b);
  printf(" + ");
  reduce_and_print(c, d);
  printf(" = ");
  reduce_and_print(a * d + b * c, b * d);
  printf("\n");
  reduce_and_print(a, b);
  printf(" - ");
  reduce_and_print(c, d);
  printf(" = ");
  reduce_and_print(a * d - b * c, b * d);
  printf("\n");
  reduce_and_print(a, b);
  printf(" * ");
  reduce_and_print(c, d);
  printf(" = ");
  reduce_and_print(a * c, b * d);
  printf("\n");
  reduce_and_print(a, b);
  printf(" / ");
  reduce_and_print(c, d);
  printf(" = ");
  reduce_and_print(a * d, b * c);
  return 0;
}