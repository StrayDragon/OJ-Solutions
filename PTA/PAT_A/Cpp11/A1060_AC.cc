// ---
// id         : 1060
// title      : Are They Equal
// difficulty : Medium
// score      : 25
// tag        : TODO
// keyword    : TODO
// status     : AC
// from       : PAT (Advanced Level) Practice
// ---

#include <iostream>
#include <string>

using namespace std;

string get_sci_body_and_e(string s, const int& n, int& e) {
  int k = 0;
  while (s.length() > 0 and s[0] == '0')
    s.erase(s.begin());
  if (s[0] == '.') {
    s.erase(s.begin());
    while (s.length() > 0 and s[0] == '0') {
      s.erase(s.begin());
      e--;
    }
  } else {
    while (k < s.length() and s[k] != '.') {
      k++;
      e++;
    }
    if (k < s.length()) {
      s.erase(s.begin() + k);
    }
  }
  if (s.length() == 0) {
    e = 0;
  }
  int num = 0;
  k = 0;
  string res;
  for (; num < n; num++) {
    if (k < s.length())
      res += s[k++];
    else
      res += '0';
  }
  return res;
}

int main() {
  int n, ea = 0, eb = 0;
  string a, b;
  cin >> n >> a >> b;

  string result_a = get_sci_body_and_e(a, n, ea),
         result_b = get_sci_body_and_e(b, n, eb);
  if (result_a == result_b and ea == eb)
    printf("YES 0.%s*10^%d", result_a.c_str(), ea);
  else
    printf("NO 0.%s*10^%d 0.%s*10^%d", result_a.c_str(), ea, result_b.c_str(),
           eb);
  return 0;
}