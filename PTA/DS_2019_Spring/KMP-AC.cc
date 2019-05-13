#include <algorithm>
#include <cstdio>
#include <iostream>
#include <iterator>
#include <string>

using namespace std;

void use_std_string_find(const string& text, const string& pattern) {
  auto i = text.find(pattern);
  if (i != string::npos) {
    while (i != text.length())
      cout << text[i++];
    cout << '\n';
  } else {
    cout << "Not Found\n";
  }
}

static int kmp_next[100010];

void kmp_get_next(const string& s, int len) {
  int j = -1;
  kmp_next[0] = -1;  // init
  for (int i = 1; i < len; i++) {
    while (j != -1 && s[i] != s[j + 1])
      j = kmp_next[j];
    if (s[i] == s[j + 1])
      j++;
    kmp_next[i] = j;
  }
}

int kmp(const string& text, const string& pattern) {
  int n = text.length(), m = pattern.length();
  kmp_get_next(pattern, m);
  int j = -1;
  for (int i = 0; i < n; i++) {
    while (j != -1 && text[i] != pattern[j + 1])
      j = kmp_next[j];
    if (text[i] == pattern[j + 1])
      j++;
    if (j == m - 1) {
      return (i - j);
    }
  }
  return -1;
}

void use_kmp(const string& text, const string& pattern) {
  int i = kmp(text, pattern);
  if (i != -1) {
    std::copy(text.begin() + i, text.end(), ostream_iterator<char>(cout));
    cout << '\n';
  } else {
    cout << "Not Found\n";
  }
}
int main() {
  string text;
  cin >> text;
  std::getchar();
  int n;
  cin >> n;
  std::getchar();
  for (string pattern; n--;) {
    std::getline(cin, pattern, '\n');
    // use_std_string_find(text, pattern);
    use_kmp(text, pattern);
  }
  return 0;
}