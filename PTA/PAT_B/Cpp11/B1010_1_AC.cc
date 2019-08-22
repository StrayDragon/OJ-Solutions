#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main() {
  vector<pair<int, int>> pairs;
  for (int c, e; cin >> c >> e;) pairs.push_back({c, e});

  int cnt = 0;
  for (auto& i : pairs) {
    i.first *= i.second;
    i.second -= 1;
    if (i.first != 0) cnt++;
  }

  if (cnt == 0)
    cout << "0 0";
  else {
    for (const auto& i : pairs) {
      if (i.first != 0) {
        cout << i.first << " " << i.second;
        cnt--;
        if (cnt) cout << " ";
      }
    }
  }
  return 0;
}