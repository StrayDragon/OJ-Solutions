#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
using namespace std;

#define IS_N1 1
#define IS_N2 2

using ll = long long;

static ll dict[256];
static auto init_dict = []() {
  for (char c = '0'; c <= '9'; ++c)
    dict[c] = c - '0';
  for (char c = 'a'; c <= 'z'; ++c)
    dict[c] = c - 'a' + 10;
  return nullptr;
}();

ll to_decimal(string& n, ll radix, ll high_bound) {
  ll result = 0;
  for (int i = 0; i < n.length(); i++) {
    result = result * radix + dict[n[i]];
    if (result < 0 || result > high_bound)
      return -1;
  }
  return result;
}

ll find_largest_digit(string& n) {
  ll result = -1;
  for (int i = 0; i < n.length(); i++) {
    if (dict[n[i]] > result)
      result = dict[n[i]];
  }
  return result + 1;
}

ll bs(string& n, ll left, ll right, ll t) {
  static auto cmp = [&](int radix) -> int {
    ll num = to_decimal(n, radix, t);
    if (num < 0)  // 溢出 此时 n > t
      return 1;
    if (t > num)  // t 较大
      return -1;
    else if (t == num)
      return 0;
    else
      return 1;  // n 较大
  };

  ll mid;
  while (left <= right) {
    mid = (left + right) / 2;
    int flag = cmp(mid);
    if (flag == 0)
      return mid;  // 获得结果
    else if (flag == -1)
      left = mid + 1;
    else
      right = mid - 1;
  }
  return -1;  // 没有结果
}

int main() {
  string n1, n2;
  int tag, radix;
  cin >> n1 >> n2 >> tag >> radix;
  if (tag == IS_N2)
    std::swap(n1, n2);

  ll t = to_decimal(n1, radix, LONG_MAX);
  ll low = find_largest_digit(n2);
  ll high = std::max(low, t) + 1;
  ll result = bs(n2, low, high, t);

  if (result == -1)
    cout << "Impossible";
  else
    cout << result;
  return 0;
}