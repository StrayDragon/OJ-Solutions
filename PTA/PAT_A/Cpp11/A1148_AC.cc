// reference: https://blog.csdn.net/liuchuo/article/details/82560876

#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> assertions(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> assertions[i];

  for (int w1 = 1; w1 <= n; w1++) {
    for (int w2 = w1 + 1; w2 <= n; w2++) {
      vector<int> liars, honests(n + 1, 1);
      honests[w1] = honests[w2] = -1;
      for (int i = 1; i <= n; i++) {
        /* `i` is a liar*/
        if (assertions[i] * honests[std::abs(assertions[i])] < 0)
          liars.push_back(i);
      }
      /* Two liars: one human + one werewolf */
      if (liars.size() == 2 && honests[liars[0]] + honests[liars[1]] == 0) {
        cout << w1 << " " << w2;
        return 0;
      }
    }
  }
  cout << "No Solution";
  return 0;
}