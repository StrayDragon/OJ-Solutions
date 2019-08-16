// ---
// id         : 1050
// title      : String Subtraction
// difficulty : Easy
// score      : 20
// tag        : TODO
// keyword    : TODO
// status     : AC
// from       : PAT (Advanced Level) Practice
// ---

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;
int main() {
  string s, replace_s;
  std::getline(cin, s);
  std::getline(cin, replace_s);
  unordered_set<char> dict;
  for (char c : replace_s)
    dict.insert(c);

  auto NOT_FOUND = dict.cend();
  for (char c : s)
    if (dict.find(c) == NOT_FOUND)
      cout << c;

  return 0;
}