#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool is_valid(char c) {
  return (('0' <= c and c <= '9') or ('A' <= c and c <= 'Z') or
          ('a' <= c and c <= 'z'));
}

char lowerify(char c) {
  if ('0' <= c and c <= '9')
    return (c);
  return (tolower(c));
}

int main() {
  string s;
  std::getline(cin, s, '\n');
  unordered_map<string, int> wordsdict;
  string word;
  for (auto it = s.begin(); it != s.end(); ++it) {
    if (is_valid(*it)) {
      word += lowerify(*it);
    } else {
      if (!word.empty()) {
        wordsdict[word]++;
        word.clear();
      }
    }

    // ! last case:
    if (it == s.begin() + s.length() - 1)
      wordsdict[word]++;
  }
  auto it = std::max_element(
      wordsdict.begin(), wordsdict.end(),
      [](const pair<string, int>& lhs, const pair<string, int>& rhs) {
        if (lhs.second == rhs.second)
          return lhs.first < rhs.first;
        return lhs.second < rhs.second;
      });
  cout << it->first << " " << it->second << endl;
  return 0;
}
