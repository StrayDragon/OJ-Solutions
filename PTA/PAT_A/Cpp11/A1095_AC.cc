// ---
// id         : 1095
// title      : Cars on Campus
// difficulty : Hard
// score      : 30
// tag        : TODO
// keyword    : TODO
// status     : AC
// from       : PAT (Advanced Level) Practice
// ---

#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

#define ARR_RNG_N(x, n) x, x + n

struct Record {
  char id[8], status[4];
  int time;
} all[10010], valid[10010];

int main() {
  int n, k;
  scanf("%d %d\n", &n, &k);
  for (int hh, mm, ss, i = 0; i < n; i++) {
    scanf("%s %d:%d:%d %s\n", all[i].id, &hh, &mm, &ss, all[i].status);
    all[i].time = hh * 3600 + mm * 60 + ss;
  }

  std::sort(ARR_RNG_N(all, n), [](const Record& a, const Record& b) {
    if (strcmp(a.id, b.id)) return strcmp(a.id, b.id) < 0;
    return a.time < b.time;
  });

  int max_park_time = -1, valid_n = 0;
  map<string, int> park_time_dict;
  for (int i = 0; i < n - 1; i++) {
    if (!strcmp(all[i].id, all[i + 1].id) && all[i].status[0] == 'i' &&
        all[i + 1].status[0] == 'o') {
      valid[valid_n++] = all[i];
      valid[valid_n++] = all[i + 1];
      int this_time = all[i + 1].time - all[i].time;
      park_time_dict[all[i].id] += this_time;
      max_park_time = std::max(max_park_time, park_time_dict[all[i].id]);
    }
  }

  std::sort(ARR_RNG_N(valid, valid_n),
            [](const Record& a, const Record& b) { return a.time < b.time; });

  int now = 0, cnt = 0;
  for (int hh, mm, ss, i = 0; i < k; i++) {
    scanf("%d:%d:%d", &hh, &mm, &ss);
    int time = hh * 3600 + mm * 60 + ss;
    while (now < valid_n && valid[now].time <= time) {
      if (valid[now].status[0] == 'i')
        cnt++;
      else
        cnt--;
      now++;
    }
    printf("%d\n", cnt);
  }

  for (auto& kv : park_time_dict)
    if (kv.second == max_park_time) printf("%s ", kv.first.c_str());

  printf("%02d:%02d:%02d\n", max_park_time / 3600, max_park_time % 3600 / 60,
         max_park_time % 60);
  return 0;
}