// ---
// id         : 1121
// title      : Damn Single
// difficulty : Medium
// score      : 25
// tag        : TODO
// keyword    : TODO
// status     : AC
// from       : PAT (Advanced Level) Practice
// ---

#include <algorithm>
#include <cstdio>
#include <unordered_set>
#include <vector>

using namespace std;

const int MAXN = 100000;
const int IS_SINGLE_DOG = -1;

int anotherdict[MAXN];

int main() {
  std::fill(anotherdict, anotherdict + MAXN, IS_SINGLE_DOG);
  int n;
  scanf("%d", &n);
  for (int lhs, rhs; n--;) {
    scanf("%d %d", &lhs, &rhs);
    anotherdict[lhs] = rhs;
    anotherdict[rhs] = lhs;
  }
  int m;
  scanf("%d", &m);
  unordered_set<int> _singledogs;

  vector<int> suspects, singledogs;
  for (int visitor; m--;) {
    scanf("%d", &visitor);
    suspects.push_back(visitor);
    _singledogs.insert(visitor);
  }

  for (int that, i = 0; i < suspects.size(); i++) {
    that = suspects[i];
    if (anotherdict[that] == IS_SINGLE_DOG ||
        _singledogs.find(anotherdict[that]) == _singledogs.end()) {
      singledogs.push_back(that);
    }
  }

  std::sort(singledogs.begin(), singledogs.end());
  printf("%d\n", (int)singledogs.size());
  if (!singledogs.empty())
    printf("%05d", singledogs[0]);
  for (int i = 1; i < singledogs.size(); ++i)
    printf(" %05d", singledogs[i]);

  return 0;
}
