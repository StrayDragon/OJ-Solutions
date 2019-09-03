// ---
// id         : 1041
// title      : Be Unique
// difficulty : Easy
// score      : 20
// tag        : Primary Algorithm
// keyword    : hash;
// status     : AC
// from       : PAT (Advanced Level) Practice
// ---

#include <iostream>

static const auto __ = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return nullptr;
}();

using namespace std;
int input[100010], hashtable[10010] = {0};
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> input[i];
    hashtable[input[i]]++;
  }
  int result = 0;
  for (int i = 0; i < n; i++) {
    if (hashtable[input[i]] == 1) {
      result = input[i];
      break;
    }
  }
  if (result)
    cout << result << '\n';
  else
    cout << "None\n";

  return 0;
}