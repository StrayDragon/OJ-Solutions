#include <cctype>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  string s1, s2, s3, s4;
  cin >> s1 >> s2 >> s3 >> s4;

  vector<int> codes;

  auto collect = [&](char c, int i) {
    if (codes.empty()) {
      if ('A' <= c && c <= 'G') codes.push_back(c);
    } else if (codes.size() == 1) {
      if (('A' <= c && c <= 'N') || isdigit(c)) codes.push_back(c);
    } else if (codes.size() == 2) {
      if (isalpha(c)) codes.push_back(i);
    }
  };

  for (size_t i = 0, len = (s1.size() < s2.size()) ? s1.size() : s2.size();
       i < len; i++) {
    if (s1[i] == s2[i]) {
      collect(s1[i], i);
    }
  }

  for (size_t i = 0, len = (s3.size() < s4.size()) ? s3.size() : s4.size();
       i < len; i++) {
    if (s3[i] == s4[i]) {
      collect(s3[i], i);
    }
  }

  const char weeks[7][4] = {
      "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN",
  };

  printf("%s %02d:%02d", weeks[codes[0] - 'A'],
         ((isdigit(codes[1]) ? codes[1] - '0' : (codes[1] - 'A') + 10)),
         codes[2]);
  return 0;
}