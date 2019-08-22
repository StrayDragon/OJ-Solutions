#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
  int n, m, a, b;
  cin >> n;

  unordered_map<int, pair<long long, int>> dict;
  for (long long id; n-- && cin >> id >> a >> b;) dict[a] = {id, b};

  cin >> m;
  while (m-- && cin >> a)
    cout << dict[a].first << ' ' << dict[a].second << '\n';
  return 0;
}