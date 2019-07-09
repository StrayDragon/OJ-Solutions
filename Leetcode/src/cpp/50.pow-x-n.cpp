/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */
class Solution {
 public:
  double fastPow(double x, long long n) {
    if (n == 0) return 1.0;
    double half = fastPow(x, n / 2);
    if (n % 2 == 0)
      return half * half;
    else
      return half * half * x;
  }

  double myPow(double x, int n) {
    long long n_ = n;
    if (n_ < 0) {
      x = 1 / x;
      n_ = -n_;
    }
    return fastPow(x, n_);
  }
};

