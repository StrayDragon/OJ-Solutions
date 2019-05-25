#include <deque>
#include <iostream>
#include <string>

using namespace std;

int dict[10];

string doubleit(const string& s) {
  deque<char> result(s.begin(), s.end());
  int add = 0;
  for (int doubled, i = result.size() - 1; i >= 0; i--) {
    doubled = (result[i] - '0') * 2 + add;
    add = doubled / 10;
    result[i] = '0' + doubled % 10;
  }
  if (add > 0) {
    result.push_front('1');
  }
  return string(result.begin(), result.end());
}

int main() {
  string integer;
  cin >> integer;
  for (const auto& digit : integer)
    dict[digit - '0'] += 1;

  string doubled = doubleit(integer);
  for (const auto& digit : doubled)
    dict[digit - '0'] -= 1;

  bool is_only_permutation = true;
  for (int i = 0; i <= 9; i++) {
    if (dict[i] != 0) {
      is_only_permutation = false;
      break;
    }
  }

  cout << ((is_only_permutation) ? "Yes\n" : "No\n");
  cout << doubled << '\n';

  return 0;
}