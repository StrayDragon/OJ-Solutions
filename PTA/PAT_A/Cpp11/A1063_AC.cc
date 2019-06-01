#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
#include <vector>

#define ALL(x) (x).begin(), (x).end()
using namespace std;
set<int> sets[51];

int main() {
  int n;
  cin >> n;
  for (int m, i = 1; i <= n; i++) {
    cin >> m;
    for (int e; m--;) {
      cin >> e;
      sets[i].insert(e);
    }
  }
  cin >> n;
  for (int i, j; n--;) {
    cin >> i >> j;

    vector<int> intersections, unions;
    std::set_intersection(ALL(sets[i]), ALL(sets[j]),
                          back_inserter(intersections));
    std::set_union(ALL(sets[i]), ALL(sets[j]), back_inserter(unions));

    double nc = intersections.size();
    double nt = unions.size();
    printf("%.1lf%%\n", nc / nt * 100);
  }

  return 0;
}