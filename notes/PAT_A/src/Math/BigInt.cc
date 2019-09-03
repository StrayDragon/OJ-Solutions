#pragma once

#include <cstdio>
#include <cstring>
namespace math {
/**
 * @brief Functions about big integer
 *
 * reference: https://oi-wiki.org/math/bignum/
 */
namespace BigIntFn {

const int MAX_LEN = 1010;

void clear(int a[MAX_LEN]) {
  for (int i = 0; i < MAX_LEN; ++i) a[i] = 0;
}

void read(int a[MAX_LEN]) {
  static char s[MAX_LEN + 1];
  scanf("%s", s);
  clear(a);
  int len = strlen(s);
  for (int i = 0; i < len; ++i) a[len - i - 1] = s[i] - '0';
}

void print(int a[MAX_LEN], char end = '\n') {
  int i;
  for (i = MAX_LEN - 1; i >= 1; --i)
    if (a[i] != 0) break;
  for (; i >= 0; --i) putchar(a[i] + '0');
  putchar(end);
}

/**
 * @brief Addition of two integers (A+B)
 *
 * @param a A
 * @param b B
 * @param c A+B
 */
void add(int a[MAX_LEN], int b[MAX_LEN], int c[MAX_LEN]) {
  clear(c);
  for (int i = 0; i < MAX_LEN - 1; ++i) {
    c[i] += a[i] + b[i];
    if (c[i] >= 10) {
      c[i + 1] += 1;
      c[i] -= 10;
    }
  }
}

/**
 * @brief Subtraction of two integers (A-B) FIXME:A > B needed
 *
 * @param a A
 * @param b B
 * @param c A-B
 */
void sub(int a[MAX_LEN], int b[MAX_LEN], int c[MAX_LEN]) {
  clear(c);
  for (int i = 0; i < MAX_LEN - 1; ++i) {
    c[i] += a[i] - b[i];
    if (c[i] < 0) {
      c[i + 1] -= 1;
      c[i] += 10;
    }
  }
#ifdef OJ_SINGLE_FILE_TEST
  op_log("sub", a, '-', b, c);
#endif
}

void mul(int a[MAX_LEN], int b, int c[MAX_LEN]) {
  clear(c);
  for (int i = 0; i < MAX_LEN - 1; ++i) {
    c[i] += a[i] * b;
    if (c[i] >= 10) {
      c[i + 1] += c[i] / 10;
      c[i] %= 10;
    }
  }
}

void mul(int a[MAX_LEN], int b[MAX_LEN], int c[MAX_LEN]) {
  clear(c);
  for (int i = 0; i < MAX_LEN - 1; ++i) {
    for (int j = 0; j <= i; ++j) c[i] += a[j] * b[i - j];
    if (c[i] >= 10) {
      c[i + 1] += c[i] / 10;
      c[i] %= 10;
    }
  }
}

inline bool greater_eq(int a[MAX_LEN], int b[MAX_LEN], int last_dg, int len) {
  if (a[last_dg + len] != 0) return true;
  for (int i = len - 1; i >= 0; --i) {
    if (a[last_dg + i] > b[i]) return true;
    if (a[last_dg + i] < b[i]) return false;
  }
  return true;
}

void div(int a[MAX_LEN], int b[MAX_LEN], int c[MAX_LEN], int d[MAX_LEN]) {
  clear(c);
  clear(d);

  int la, lb;
  for (la = MAX_LEN - 1; la > 0; --la)
    if (a[la - 1] != 0) break;
  for (lb = MAX_LEN - 1; lb > 0; --lb)
    if (b[lb - 1] != 0) break;
  if (lb == 0) {
    puts("Divisor cannot be zero");
    return;
  }
  for (int i = 0; i < la; ++i) d[i] = a[i];
  for (int i = la - lb; i >= 0; --i) {
    while (greater_eq(d, b, i, lb)) {
      for (int j = 0; j < lb; ++j) {
        d[i + j] -= b[j];
        if (d[i + j] < 0) {
          d[i + j + 1] -= 1;
          d[i + j] += 10;
        }
      }
      c[i] += 1;
    }
  }
}

}  // namespace BigIntFn
}  // namespace math
