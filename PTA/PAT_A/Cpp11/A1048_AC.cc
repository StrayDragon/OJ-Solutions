#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

const int MAXN = 100010;

int coins_at[MAXN];
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> values;
  for (int v; cin >> v; coins_at[v]++) values.push_back(v);
  std::sort(values.begin(), values.end());

  tuple<int, int> result{-1, -1};
  for (auto& v1 : values) {
    int v2 = m - v1;
    if ((v1 < v2 && coins_at[v1] - 1 >= 0 && coins_at[v2] - 1 >= 0) ||
        (v1 == v2 && coins_at[v1] - 2 >= 0)) {
      result = make_tuple(v1, v2);
      break;
    }
  }
  if (std::get<0>(result) == -1)
    cout << "No Solution\n";
  else
    cout << std::get<0>(result) << " " << std::get<1>(result) << '\n';

  return 0;
}