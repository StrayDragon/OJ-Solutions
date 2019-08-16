// ---
// id         : 1084
// title      : Broken Keyboard
// difficulty : Easy
// score      : 20
// tag        : TODO
// keyword    : TODO
// status     : AC
// from       : PAT (Advanced Level) Practice
// ---

#include <cctype>
#include <iostream>
using namespace std;
int main() {
  string s1, s2, result;
  cin >> s1 >> s2;
  for (int i = 0; i < s1.length(); i++)
    if (s2.find(s1[i]) == string::npos &&
        result.find(toupper(s1[i])) == string::npos)
      result += toupper(s1[i]);
  cout << result;
  return 0;
}