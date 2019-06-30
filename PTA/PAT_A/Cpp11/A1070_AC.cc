#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Mooncake {
  /* WARNING: `amount` is float number QwQ */
  double amount, unit, totalprice;
};

int main() {
  int n, d;
  cin >> n >> d;

  vector<Mooncake> mookcakes(n);
  for (int i = 0; i < n; i++) {
    cin >> mookcakes[i].amount;
  }

  for (int i = 0; i < n; i++) {
    cin >> mookcakes[i].totalprice;
    mookcakes[i].unit = mookcakes[i].totalprice / mookcakes[i].amount;
  }

  std::sort(mookcakes.begin(), mookcakes.end(),
            [](const Mooncake& lhs, const Mooncake& rhs) {
              return lhs.unit > rhs.unit;
            });

  double result = 0.0;
  for (auto& cake : mookcakes) {
    if (d >= cake.amount) {
      result += cake.totalprice;
      d -= cake.amount;
    } else {
      result += cake.unit * d;
      break;
    }
  }

  printf("%.2lf", result);

  return 0;
}