#include <cmath>
#include <iostream>
#include <sstream>
using namespace std;

int gcd(int a, int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}

struct Fraction {
  long long up, down;

  Fraction() = default;

  Fraction(int u, int d) : up(u), down(d) {}

  Fraction(const Fraction& other) : up(other.up), down(other.down) {}

  Fraction& operator=(const Fraction& other) {
    up = other.up;
    down = other.down;
    return *this;
  }

  static Fraction reduction(Fraction result) {
    if (result.down < 0) {
      result.up = -result.up;
      result.down = -result.down;
    }
    if (result.up == 0) {
      result.down = 1;
    } else {
      int d = gcd(std::abs(result.up), std::abs(result.down));
      result.up /= d;
      result.down /= d;
    }
    return result;
  }

  Fraction operator+(const Fraction& other) const {
    Fraction result;
    result.up = up * other.down + other.up * down;
    result.down = down * other.down;
    return Fraction::reduction(result);
  }

  Fraction operator-(const Fraction& other) const {
    Fraction result;
    result.up = up * other.down - other.up * down;
    result.down = down * other.down;
    return Fraction::reduction(result);
  }

  Fraction operator*(const Fraction& other) const {
    Fraction result;
    result.up = up * other.up;
    result.down = down * other.down;
    return Fraction::reduction(result);
  }

  Fraction operator/(const Fraction& other) {
    Fraction result;
    result.up = up * other.down;
    result.down = down * other.up;
    return Fraction::reduction(result);
  }

  void display() {
    Fraction r = Fraction::reduction(*this);  // 约分
    if (r.down == 1) {                        // 整数
      if (r.up < 0)
        std::printf("(%lld)", r.up);
      else
        std::printf("%lld", r.up);

    } else if (std::abs(r.up) > r.down) {  // 假分数
      if (r.up < 0) {
        if (r.down == 0)
          std::printf("Inf");
        else
          std::printf("(%lld %lld/%lld)", r.up / r.down,
                      std::abs(r.up) % r.down, r.down);

      } else {
        if (r.down == 0)
          std::printf("Inf");
        else
          std::printf("%lld %lld/%lld", r.up / r.down, std::abs(r.up) % r.down,
                      r.down);
      }
    } else {  // 真分数
      if (r.up < 0)
        std::printf("(%lld/%lld)", r.up, r.down);
      else
        std::printf("%lld/%lld", r.up, r.down);
    }
  }
};