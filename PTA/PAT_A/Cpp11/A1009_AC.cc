#include <iomanip>
#include <iostream>
#include <utility>

using namespace std;

using Exponent = int;
using Coefficient = double;
using PolyElement = std::pair<Exponent, Coefficient>;

PolyElement polyelems[1010];

double results[2001];
int main() {
  int n1;
  cin >> n1;
  for (int i = 0; i < n1; i++)
    cin >> polyelems[i].first >> polyelems[i].second;
  int n2;
  cin >> n2;
  for (int exp, i = 0; i < n2; i++) {
    double cof;
    cin >> exp >> cof;
    for (int j = 0; j < n1; j++) {
      results[exp + polyelems[j].first] += cof * polyelems[j].second;
    }
  }

  int cnt = 0;
  for (int i = 0; i <= 2000; i++) {
    if (results[i] != 0)
      cnt++;
  }

  cout << cnt;
  for (int i = 2000; i >= 0; i--) {
    if (results[i] != 0)
      cout << " " << i << " " << std::fixed << std::setprecision(1)
           << results[i];
    // printf(" %d %.1f", i, results[i]);
  }
}