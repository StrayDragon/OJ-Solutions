#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>

using namespace std;

struct BigInt {
  int d[1010];
  size_t len;
  BigInt() {
    std::fill(begin(d), end(d), 0);
    len = 0;
  }

  BigInt(const string& s) {
    len = s.length();
    for (size_t i = 0; i < len; i++) {
      d[i] = s[len - i - 1] - '0';
    }
  }

  string to_str() const {
    string res;
    for (int i = len - 1; i >= 0; i--) res += char('0' + d[i]);
    return res;
  }
};

BigInt add(const BigInt& lhs, const BigInt& rhs) {
  BigInt res;
  int carry = 0;
  for (size_t i = 0; i < lhs.len || i < rhs.len; i++) {
    int t = lhs.d[i] + rhs.d[i] + carry;
    res.d[res.len++] = t % 10;
    carry = t / 10;
  }
  if (carry != 0) res.d[res.len++] = carry;
  return res;
}

ostream& operator<<(ostream& out, const BigInt& bi) {
  for (size_t i = bi.len - 1; i >= 0; i--) out << bi.d[i];
  return out;
}

bool is_palindromic(const string& s) {
  for (size_t i = 0, len = s.length(); i < len; i++) {
    if (s[i] != s[len - 1 - i]) return false;
  }
  return true;
}

int main() {
  string src;
  cin >> src;

  int cnt = 0;
  for (string rsrc, res; cnt < 10; src = res, cnt++) {
    rsrc = src;
    std::reverse(rsrc.begin(), rsrc.end());
    res = add(BigInt(src), BigInt(rsrc)).to_str();
    if (is_palindromic(src)) {
      cout << src << " is a palindromic number.";
      break;
    }
    cout << src << " + " << rsrc << " = " << res << '\n';
  }

  if (cnt == 10) {
    cout << "Not found in 10 iterations.";
  }

  return 0;
}