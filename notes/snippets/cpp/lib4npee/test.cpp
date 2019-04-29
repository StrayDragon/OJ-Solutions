#include <bits/stdc++.h>

#include "kmp.h"

#define ALL(x, n) begin(x), begin(x) + (n)

void test_TQNotes_KMP() {
  using namespace std;
  cout << "In test_TQNotes_KMP()\n";
  string text = "abababaabc";
  string pattern = "ababaab";

  int next[10] = {0}, i = 0;
  npee::getnext(pattern, next);
  int result = npee::KMP(text, pattern, next);

  cout << "text:\t\t";
  for (auto c : text)
    cout << c << " ";
  cout << '\n';
  cout << "pattern:\t";
  for (auto c : pattern)
    cout << c << " ";
  cout << '\n';
  cout << "KMP result:\t" << std::boolalpha << bool(result) << "\n";
  cout << "next array info:\n";
  cout << "\tIndex ";
  for_each(ALL(next, 10), [&](int e) { cout << i++ << " "; });
  cout << "\n\tValue ";
  for_each(ALL(next, 10), [](int e) { cout << e << " "; });
}

int main() {
  test_TQNotes_KMP();
  return 0;
}