#pragma once

#include <climits>
#include <cmath>
#include <iostream>

namespace math {
namespace algebra {

using i64 = long long;

/**
 * @brief 快速幂 (二分幂) 迭代实现
 *
 * @param a 底数
 * @param b 指数
 * @param m 模长, 默认为 INT_MAX
 * @return i64 $a^b%m$
 */
i64 binpow(i64 a, i64 b, i64 m = INT_MAX) {
  auto ans = 1LL;
  for (; b > 0; b >>= 1) { /* b /= 2 */
    if (b & 1)             /* b 为偶数, 等价于 b % 2 */
      ans = ans * a % m;
    a = a * a % m;
  }
  return ans;
}

/**
 * @brief 快速幂 (二分幂) 递归实现
 *
 * @param a 底数
 * @param b 指数
 * @param m 模长, 默认为 INT_MAX
 * @return i64 $a^b%m$
 */
i64 binpow_rec(i64 a, i64 b, i64 m = INT_MAX) {
  if (b == 0) return 1;
  if (b & 1) {
    return a * binpow_rec(a, b - 1, m) % m;
  } else {
    auto mul = binpow_rec(a, b / 2, m);
    return mul * mul % m;
  }
}

/**
 * @brief TODO:最大公约数
 *
 * @param a
 * @param b
 * @return int
 */
int gcd(int a, int b) { return !b ? a : gcd(b, a % b); }

/**
 * @brief TODO:最小公倍数
 *
 * @param a
 * @param b
 * @return int
 */
int lcm(int a, int b) {
  // return a * b / gcd(a, b);
  return a / gcd(a, b) * b;
}

/**
 * @brief TODO:分数运算
 *
 */
namespace CFraction {

/// 代表 x / y
struct Fraction {
  int x, y;
};

Fraction reduction(Fraction a) {
  if (a.y < 0) {
    a.x = -a.x;
    a.y = -a.y;
  }
  if (a.x == 0) {
    a.y = 1;
  } else {
    int d = gcd(abs(a.x), abs(a.y));
    a.x /= d;
    a.y /= d;
  }
  return a;
}

void print(Fraction a) {
  using std::abs;
  using std::cout;
  a = reduction(a);
  if (a.y == 1)  // 整数
    cout << a.x;
  else if (abs(a.x) > a.y)  // 假分数
    cout << (a.x / a.y) << " " << (abs(a.x) % a.y) << "/" << a.y;
  else  // 真分数
    cout << a.x << "/" << a.y;
}

Fraction add(Fraction a, Fraction b) {
  Fraction t;
  t.x = a.x * b.y + b.x * a.y;
  t.y = a.y + b.y;
  return t;
}

Fraction minus(Fraction a, Fraction b) {
  Fraction t;
  t.x = a.x * b.y - b.x * a.y;
  t.y = a.y + b.y;
  return t;
}

Fraction mul(Fraction a, Fraction b) {
  Fraction t;
  t.x = a.x * b.x;
  t.y = a.y * b.y;
  return t;
}

Fraction div(Fraction a, Fraction b) {
  Fraction t;
  t.x = a.x * b.y;
  t.y = a.y * b.x;
  return t;
}

}  // namespace CFraction

/**
 * @brief TODO:判断质数
 *
 * @param n
 * @return true
 * @return false
 */
bool is_prime(int n) {
  if (n <= 1) return false;
  int sqr = (int)std::sqrt(1.0 * n);
  for (int i = 2; i <= sqr; i++) {
    if (n % i == 0) return false;
  }
  return true;
}

/**
 * @brief TODO:素数筛
 *
 */
namespace CPrimeSieve {

const int MAX_PRIME_SIZE = 10010;
int primes_[MAX_PRIME_SIZE];
bool vis_[MAX_PRIME_SIZE];

void fill_primes() {
  for (int now = 0, i = 2; i < MAX_PRIME_SIZE; i++) {
    if (!vis_[i]) {
      primes_[now++] = i;
      for (int j = 0; j < MAX_PRIME_SIZE; j += i) {
        vis_[j] = true;
      }
    }
  }
}

namespace CFactor {}

}  // namespace CPrimeSieve

}  // namespace algebra
}  // namespace math
