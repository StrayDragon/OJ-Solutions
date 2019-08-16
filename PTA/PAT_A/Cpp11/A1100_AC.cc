// ---
// id         : 1100
// title      : Mars Numbers
// difficulty : Easy
// score      : 20
// tag        : TODO
// keyword    : TODO
// status     : AC
// from       : PAT (Advanced Level) Practice
// ---

#include <algorithm>
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

string lower_digit_dict[13] = {
    "tret", "jan", "feb", "mar", "apr", "may", "jun",
    "jly",  "aug", "sep", "oct", "nov", "dec",
};
string higher_digit_dict[13] = {
    "",    "tam", "hel", "maa", "huh", "tou", "kes",
    "hei", "elo", "syy", "lok", "mer", "jou",
};

int main() {
  auto is_digit = [](const string& s) -> bool {
    return ('0' <= s[0] && s[0] <= '9');
  };

  auto parse_to_mars_num = [](int earth_num) -> string {
    string res;
    if (earth_num / 13)
      res += higher_digit_dict[earth_num / 13];
    if (earth_num / 13 && earth_num % 13)
      res += ' ';
    if (earth_num % 13 || earth_num == 0)
      res += lower_digit_dict[earth_num % 13];
    return res;
  };

  auto parse_to_earth_num = [&](const string& mars_num_str) -> string {
    int t1 = 0, t2 = 0;
    string s, h = mars_num_str.substr(0, 3);
    if (mars_num_str.length() > 4)
      s = mars_num_str.substr(4, 3);
    for (int i = 1; i <= 12; i++) {
      if (h == lower_digit_dict[i] || s == lower_digit_dict[i])
        t2 = i;
      if (h == higher_digit_dict[i])
        t1 = i;
    }
    string res = to_string(t1 * 13 + t2);
    return res;
  };

  int n;
  cin >> n;
  getchar();  //坑,注意和getline混用时
  for (string str; n--;) {
    std::getline(cin, str);
    if (is_digit(str)) {
      cout << parse_to_mars_num(stoi(str)) << '\n';
    } else {
      cout << parse_to_earth_num(str) << '\n';
    }
  }
  return 0;
}