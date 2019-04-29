#include <cassert>
#include <cstring>

namespace oj {
namespace strings {

const int MAX_NEXT_ARRAY_CAPACITY = 10;

static int next[MAX_NEXT_ARRAY_CAPACITY];

void kmp_get_next(char s[], int len) {
  assert(len < MAX_NEXT_ARRAY_CAPACITY);
  int j = -1;
  next[0] = -1;  // init
  for (int i = 1; i < len; i++) {
    while (j != -1 && s[i] != s[j + 1])
      j = next[j];
    if (s[i] == s[j + 1])
      j++;
    next[i] = j;
  }
}

bool kmp(char text[], char pattern[]) {
  int n = strlen(text), m = strlen(pattern);
  kmp_get_next(pattern, m);
  int j = -1;
  for (int i = 0; i < n; i++) {
    while (j != -1 && text[i] != pattern[j + 1])
      j = next[j];
    if (text[i] == pattern[j + 1])
      j++;
    if (j == m - 1)
      return true;
  }
  return false;
}

}  // namespace strings
}  // namespace oj

#include "../preinclude.hpp"
namespace oj {
void example_pattern_match_kmp() {
  using namespace std;
  using oj::strings::kmp;
  using oj::strings::kmp_get_next;

  eg::start();
  cout << "In oj::example_pattern_match_kmp():\n";
  char text[] = "abababaabc";
  char pattern[] = "ababaab";
  int len = strlen(pattern);
  cout << "text:\t\t";
  for_each(ALLN(text, strlen(text)), [](char e) { cout << e << " "; });
  cout << '\n';
  cout << "pattern:\t";
  for_each(ALLN(pattern, strlen(pattern)), [](char e) { cout << e << " "; });

  kmp_get_next(pattern, len);
  cout << "\n| nextarr:\t";
  for_each(ALLN(oj::strings::next, len), [](int e) { cout << e << " "; });
  cout << "\nKMP result:\t" << std::boolalpha << kmp(text, pattern);
  eg::over();
}
}  // namespace oj