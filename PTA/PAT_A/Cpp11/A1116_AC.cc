// ---
// id         : 1116
// title      : Come on! Let's C
// difficulty : Easy
// score      : 20
// tag        : TODO
// keyword    : TODO
// status     : AC
// from       : PAT (Advanced Level) Practice
// ---

#include <cmath>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool is_prime(int n) {
  if (n <= 1)
    return false;
  int bound = (int)std::sqrt(1.0 * n);
  for (int i = 2; i <= bound; ++i)
    if (n % i == 0)
      return false;
  return true;
}

int main() {
  unordered_map<int, string> awarddict;
  unordered_map<int, bool> checkeddict;
  int n;
  cin >> n;
  for (int id, i = 1; i <= n; i++) {
    cin >> id;
    if (i == 1) {
      awarddict[id] = "Mystery Award";
    } else {
      if (is_prime(i)) {
        awarddict[id] = "Minion";
      } else {
        awarddict[id] = "Chocolate";
      }
    }
  }

  int k;
  cin >> k;
  for (int id; k--;) {
    cin >> id;
    printf("%04d: ", id);
    if (awarddict.find(id) != awarddict.end()) {
      if (checkeddict.find(id) != checkeddict.end()) {
        cout << "Checked\n";
      } else {
        checkeddict[id] = true;
        cout << awarddict[id] << '\n';
      }
    } else {
      cout << "Are you kidding?\n";
    }
  }
  return 0;
}
