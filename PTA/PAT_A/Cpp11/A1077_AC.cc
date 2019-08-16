// ---
// id         : 1077
// title      : Kuchiguse
// difficulty : Easy
// score      : 20
// tag        : TODO
// keyword    : TODO
// status     : AC
// from       : PAT (Advanced Level) Practice
// ---

// 易错测试点;
// - case: 混用 std::cin 与 std::getline 的坑会误读换行符等
// - case: 有n行输入,但每行都只有0或1个字符

#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

int main() {
  std::ios::sync_with_stdio(false);
  int n;
  cin >> n;
  cin.ignore();
  vector<string> lines;
  int minlen = 260;
  for (string line; std::getline(cin, line, '\n');) {
    if (minlen > line.length())
      minlen = line.length();
    lines.push_back(string(line.rbegin(), line.rend()));
  }

  string result;
  bool is_found = true;
  for (int j, i = 0; i < minlen; i++) {
    const char expected = lines[0][i];
    for (j = 1; j < lines.size(); j++) {
      if (lines[j][i] != expected) {
        if (i == 0) {
          is_found = false;
        }
        break;
      }
    }
    if (j == lines.size()) {
      result += expected;
    } else {
      break;
    }
  }

  if (is_found && !result.empty())
    std::copy(result.rbegin(), result.rend(), ostream_iterator<char>(cout));
  else
    cout << "nai";

  return 0;
}