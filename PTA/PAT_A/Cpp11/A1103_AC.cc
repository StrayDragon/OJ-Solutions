#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int n, k, p;

vector<int> fac, ans, tmp;
int max_fac_sum = -1;
void dfs(int i, int cnt, int sum, int fac_sum) {
  if (sum == n and cnt == k) {
    if (fac_sum > max_fac_sum) {
      max_fac_sum = fac_sum;
      ans = tmp;
    }
    return;
  }
  if (sum > n or cnt > k) return;
  if (i - 1 >= 0) {
    tmp.push_back(i);
    dfs(i, cnt + 1, sum + fac[i], fac_sum + i);
    tmp.pop_back();
    dfs(i - 1, cnt, sum, fac_sum);
  }
}

int main() {
  cin >> n >> k >> p;

  {
    for (int i = 0, tmp = 0; tmp <= n;) {
      fac.push_back(tmp);
      tmp = std::pow(++i, p);
    }
  }

  dfs(fac.size() - 1, 0, 0, 0);

  if (max_fac_sum == -1)
    cout << "Impossible";
  else {
    cout << n << " = " << ans[0] << "^" << p;
    for (int i = 1; i < ans.size(); i++) {
      cout << " + " << ans[i] << "^" << p;
    }
  }
  return 0;
}