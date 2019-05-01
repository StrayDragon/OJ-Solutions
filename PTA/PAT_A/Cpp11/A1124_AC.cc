#include <iostream>
#include <iterator>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
  int m, n, s;
  cin >> m >> n >> s;
  vector<string> forwards{"Placeholder"};
  for (string name; cin >> name;)
    forwards.push_back(name);
  unordered_map<string, bool> wondict;
  if (m < s) {
    cout << "Keep going...\n";
  } else {
    for (int i = s; i <= m;) {
      if (i <= m && wondict.find(forwards[i]) == wondict.end()) {
        wondict[forwards[i]] = true;
        cout << forwards[i] << '\n';
        i += n;
      } else {
        ++i;
      }
    }
  }

  return 0;
}