// ---
// id         : A1014
// title      : Waiting in Line
// difficulty : Hard
// score      : 30
// tag        : TODO
// keyword    : TODO
// status     : AC
// from       : PAT (Advanced Level) Practice
// ---


#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

#define START_TIME 480
#define TERMINATE_TIME 1020

int n, m, k, q, work_duration[1010], result_time[1010];
struct Window {
  int end_time = START_TIME, pop_time = START_TIME;
  queue<int> q;
} windows[20];

int main() {
  cin >> n >> m >> k >> q;
  for (int i = 0; i < k; i++) cin >> work_duration[i];

  int ci = 0;  // customer index
  for (int i = 0; i < std::min(n * m, k); i++) {
    windows[ci % n].q.push(ci);
    windows[ci % n].end_time += work_duration[ci];
    if (ci < n) windows[ci].pop_time = work_duration[ci];
    result_time[ci] = windows[ci % n].end_time;
    ci++;
  }

  for (; ci < k; ci++) {
    int next_ci = -1, min_pop_time = 1e9;
    for (int i = 0; i < n; i++) {
      if (windows[i].pop_time < min_pop_time) {
        next_ci = i;
        min_pop_time = windows[i].pop_time;
      }
    }

    auto& w = windows[next_ci];
    w.q.pop();
    w.q.push(next_ci);
    w.end_time += work_duration[ci];
    w.pop_time += work_duration[w.q.front()];
    result_time[ci] = w.end_time;
  }

  auto fmt_println([](int m) { printf("%02d:%02d\n", m / 60 % 24, m % 60); });

  for (int i; q-- && cin >> i;) {
    i--;
    if (result_time[i] - work_duration[i] >= TERMINATE_TIME) {
      cout << "Sorry\n";
    } else {
      fmt_println(result_time[i]);
    }
  }
  return 0;
}