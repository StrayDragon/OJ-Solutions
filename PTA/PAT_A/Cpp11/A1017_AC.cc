// ---
// id         : 1017
// title      : Queueing at Bank
// difficulty : Medium
// score      : 25
// tag        : TODO
// keyword    : TODO
// status     : AC
// from       : PAT (Advanced Level) Practice
// ---

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

struct Customer {
  int arrive_time, duration;
};

constexpr int to_second(int h, int m, int s) { return h * 3600 + m * 60 + s; }

const int MAXK = 105;
const int INF = 1234567890;

const int START_TIME{to_second(8, 0, 0)};
const int END_TIME{to_second(17, 0, 0)};

int end_serve_times[MAXK];

int main() {
  int c, w;
  cin >> c >> w;

  for (int i = 0; i < w; i++) {
    end_serve_times[i] = START_TIME;
  }

  vector<Customer> customers;
  Customer customer;
  for (int i = 0; i < c; i++) {
    int h, m, s, duration;
    scanf("%d:%d:%d %d", &h, &m, &s, &duration);
    int arrive_time{to_second(h, m, s)};
    if (arrive_time <= END_TIME) {
      customer.arrive_time = arrive_time;
      customer.duration = duration <= 60 ? duration * 60 : 3600;
      customers.push_back(customer);
    }
  }

  std::sort(customers.begin(), customers.end(),
            [](const Customer& lhs, const Customer& rhs) {
              return lhs.arrive_time < rhs.arrive_time;
            });

  double total_duration = 0;
  for (int i = 0; i < customers.size(); i++) {
    int min_i = -1, min_end_time = INF;
    for (int j = 0; j < w; j++) {
      if (end_serve_times[j] < min_end_time) {
        min_end_time = end_serve_times[j];
        min_i = j;
      }
    }

    if (end_serve_times[min_i] <= customers[i].arrive_time) {
      end_serve_times[min_i] = customers[i].arrive_time + customers[i].duration;
    } else {
      total_duration += (end_serve_times[min_i] - customers[i].arrive_time);
      end_serve_times[min_i] += customers[i].duration;
    }
  }

  if (customers.size() == 0)
    cout << "0.0";
  else
    cout << std::fixed << std::setprecision(1)
         << total_duration / 60 / customers.size();
  return 0;
}