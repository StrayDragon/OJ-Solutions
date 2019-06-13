#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

struct BigInt {
  static const int MAX_DIGITS = 1000;
  int d[MAX_DIGITS];
  int size;

  static BigInt from_string(std::string num_str) {
    BigInt bi;
    bi.size = num_str.size();
    for (int i = 0; i < bi.size; i++) {
      bi.d[i] = num_str[bi.size - i - 1] - '0';
    }
    return bi;
  }

  BigInt() : size(0) { std::fill(d, d + MAX_DIGITS, 0); }

  BigInt(const BigInt& other) { *this = other; }

  BigInt& operator=(const BigInt& other) {
    size = other.size;
    for (int i = 0; i < size; i++) {
      d[i] = other.d[i];
    }
    return *this;
  }

  BigInt operator+(const BigInt& other) {
    BigInt bi;
    int c = 0;
    for (int tmp, i = 0; i < size || i < other.size; i++) {
      tmp = d[i] + other.d[i] + c;
      bi.d[bi.size++] = tmp % 10;
      c = tmp / 10;
    }
    if (c) {
      bi.d[bi.size++] = c;
    }
    return bi;
  }
};

bool is_palindromic(const BigInt& bi) {
  for (int i = 0; i <= bi.size / 2; i++) {
    if (bi.d[i] != bi.d[bi.size - 1 - i])
      return false;
  }
  return true;
}

ostream& operator<<(ostream& out, const BigInt& bi) {
  for (int i = bi.size - 1; i >= 0; i--) {
    out << bi.d[i];
  }
  return out;
}

int main() {
  string s;
  int k;
  cin >> s >> k;
  auto n = BigInt::from_string(s);
  int i = 0;
  while (i < k && !is_palindromic(n)) {
    BigInt rn(n);
    std::reverse(rn.d, rn.d + rn.size);
    n = n + rn;
    i++;
  }
  cout << n << '\n';
  cout << i << '\n';

  return 0;
}
