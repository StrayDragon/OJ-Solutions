// ---
// id         : A1026
// title      : Table Tennis
// difficulty : Hard
// score      : 30
// tag        : TODO
// keyword    : TODO
// status     : AC
// from       : PAT (Advanced Level) Practice
// ---

#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;

const int START_TIME = 8 * 3600;
const int TERMINATE_TIME = 21 * 3600;
const int INF = 1e9;

struct Player {
  int arrive_time, start_time;
  int serve_duration;
  bool is_vip = false;
} players[100010];

struct Table {
  int end_time = START_TIME;
  int served_cnt = 0;
  bool is_vip = false;
} tables[110];

int main() {
  int n;
  scanf("%d", &n);
  int valid_n = 0;
  for (int hh, mm, ss, p, tag, i = 0; i < n; i++) {
    scanf("%d:%d:%d %d %d", &hh, &mm, &ss, &p, &tag);

    auto& player = players[valid_n];
    player.arrive_time = hh * 3600 + mm * 60 + ss;
    player.start_time = TERMINATE_TIME;
    if (player.arrive_time <
        TERMINATE_TIME) {  // Filter players after 21:00:00.
      player.serve_duration = p <= 120 ? p * 60 : 7200;
      player.is_vip = tag;
      valid_n++;
    }
  }

  std::sort(players, players + valid_n,
            [](Player& a, Player& b) { return a.arrive_time < b.arrive_time; });

  int k, m;
  scanf("%d %d", &k, &m);
  for (int vip_i, i = 0; i < m; i++) {
    scanf("%d", &vip_i);
    tables[vip_i].is_vip = true;
  }

  auto next_vip_i([&](int vip_i) {
    vip_i++;
    while (vip_i < valid_n && !players[vip_i].is_vip) vip_i++;
    return vip_i;
  });

  int vip_i = next_vip_i(-1);
  for (int i = 0; i < valid_n;) {
    int min_i = -1, min_end_time = INF;
    for (int j = 1; j <= k; j++) {
      if (tables[j].end_time < min_end_time) {
        min_end_time = tables[j].end_time;
        min_i = j;
      }
    }
    if (tables[min_i].end_time >= TERMINATE_TIME) break;
    if (players[i].is_vip && i < vip_i) {
      i++;
      continue;
    }

    auto allocate_table([&](int pid, int tid) {
      if (players[pid].arrive_time <= tables[tid].end_time) {
        players[pid].start_time = tables[tid].end_time;
      } else {
        players[pid].start_time = players[pid].arrive_time;
      }
      tables[tid].end_time =
          players[pid].start_time + players[pid].serve_duration;
      tables[tid].served_cnt++;
    });

    if (tables[min_i].is_vip) {
      if (players[i].is_vip) {
        allocate_table(i, min_i);
        if (vip_i == i) vip_i = next_vip_i(vip_i);
        i++;
      } else {
        if (vip_i < valid_n &&
            players[vip_i].arrive_time <= tables[min_i].end_time) {
          allocate_table(vip_i, min_i);
          vip_i = next_vip_i(vip_i);
        } else {
          allocate_table(i, min_i);
          i++;
        }
      }
    } else {
      if (!players[i].is_vip) {
        allocate_table(i, min_i);
        i++;
      } else {
        int min_vip_i = -1, min_vip_end_time = INF;
        for (int j = 1; j <= k; j++) {
          if (tables[j].is_vip && tables[j].end_time < min_vip_end_time) {
            min_vip_end_time = tables[j].end_time;
            min_vip_i = j;
          }
        }
        if (min_vip_i != -1 &&
            players[i].arrive_time >= tables[min_vip_i].end_time) {
          allocate_table(i, min_vip_i);
          if (vip_i == i) vip_i = next_vip_i(vip_i);
          i++;
        } else {
          allocate_table(i, min_i);
          if (vip_i == i) vip_i = next_vip_i(vip_i);
          i++;
        }
      }
    }
  }

  std::sort(players, players + valid_n,
            [](Player& a, Player& b) { return a.start_time < b.start_time; });

  auto fmt_print([](int d) {
    printf("%02d:%02d:%02d ", d / 3600, d % 3600 / 60, d % 60);
  });

  for (int i = 0; i < valid_n && players[i].start_time < TERMINATE_TIME; i++) {
    fmt_print(players[i].arrive_time);
    fmt_print(players[i].start_time);
    printf("%.0f\n",
           std::round((players[i].start_time - players[i].arrive_time) / 60.0));
  }

  for (int i = 1; i <= k; i++) {
    printf("%d", tables[i].served_cnt);
    if (i < k) putchar(' ');
  }

  return 0;
}