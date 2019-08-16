// ---
// id         : 1033
// title      : To Fill or Not to Fill
// difficulty : Medium
// score      : 25
// tag        : TODO
// keyword    : TODO
// status     : AC
// from       : PAT (Advanced Level) Practice
// ---

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Station {
  double p, d;
  bool operator<(Station& rhs) const { return d < rhs.d; }
};

int main() {
  double cmax, d, davg, n;
  cin >> cmax >> d >> davg >> n;

  vector<Station> stations(n);
  for (int i = 0; i < n; i++) cin >> stations[i].p >> stations[i].d;

  std::sort(stations.begin(), stations.end());
  //! Aggregate initialization (C++20 official support)
  stations.push_back(Station{.p = 0.0, .d = d});

  if (!stations.empty() && stations[0].d != 0) {
    printf("The maximum travel distance = 0.00\n");
  } else {
    double total_price = 0, cur_tank = 0, max_d = cmax * davg;
    int cur = 0;
    for (; cur < n;) {
      int lowest_price_station = -1;
      double min_p = 1234567890;
      for (int i = cur + 1;
           i <= n && stations[i].d - stations[cur].d <= max_d; i++) {
        if (stations[i].p < min_p) {
          min_p = stations[i].p;
          lowest_price_station = i;
          if (min_p < stations[cur].p) break;
        }
      }
      if (lowest_price_station == -1) break;
      double need =
          (stations[lowest_price_station].d - stations[cur].d) / davg;
      if (min_p < stations[cur].p) {
        if (cur_tank < need) {
          total_price += (need - cur_tank) * stations[cur].p;
          cur_tank = 0;
        } else {
          cur_tank -= need;
        }
      } else {
        total_price += (cmax - cur_tank) * stations[cur].p;
        cur_tank = cmax - need;
      }
      cur = lowest_price_station;
    }
    if (cur == n) {
      printf("%.2f\n", total_price);
    } else {
      printf("The maximum travel distance = %.2f\n",
             stations[cur].d + max_d);
    }
  }

  return 0;
}