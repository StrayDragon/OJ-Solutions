#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 110;

struct Point {
  int x, y;
} points[MAXN];
bool visited[MAXN] = {false};

int n;
double d;

inline bool can_save(int v) {
  return (abs(points[v].x) >= 50 - d) || (abs(points[v].y >= 50 - d));
}

inline bool first_jump(int v) {
  return sqrt(points[v].x * points[v].x + points[v].y * points[v].y) <= d + 7.5;
}

bool jump(int v1, int v2) {
  int x1 = points[v1].x;
  int y1 = points[v1].y;
  int x2 = points[v2].x;
  int y2 = points[v2].y;
  return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)) <= d;
}

bool dfs(int v) {
  bool res = false;
  visited[v] = true;
  if (can_save(v))
    return true;
  for (int i = 0; i < n; i++) {
    if (!visited[i] && jump(v, i))
      res = dfs(i);
    if (res)
      break;
  }
  return res;

  return res;
}

int main() {
  cin >> n >> d;
  for (int i = 0; i < n; i++)
    cin >> points[i].x >> points[i].y;

  bool saved = false;
  for (int i = 0; i < n; i++)
    if (!visited[i] && first_jump(i)) {
      // cout << "选择该坐标点points[" << i << "]第一次跳跃" << endl;
      // cout << "\t 当前状态为: (" << points[i].x << ", " << points[i].y << ")"
      //      << endl;
      if (saved = dfs(i))
        break;
    }

  if (saved)
    cout << "Yes\n";
  else
    cout << "No\n";
  return 0;
}