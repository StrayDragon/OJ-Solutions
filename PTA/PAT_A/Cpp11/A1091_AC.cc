#include <iostream>
#include <queue>

using namespace std;

struct Point {
  int x, y, z;
};

int n, m, slices, threshold;

int pixel[1290][130][61];
bool inq[1290][130][61];

bool can_visit(int x, int y, int z) {
  if (x >= n or x < 0 or y >= m or y < 0 or z >= slices or z < 0) return false;
  if (pixel[x][y][z] == 0 || inq[x][y][z]) return false;
  return true;
}

int X[6] = {0, 0, 0, 0, 1, -1};
int Y[6] = {0, 0, 1, -1, 0, 0};
int Z[6] = {1, -1, 0, 0, 0, 0};

int bfs(int x, int y, int z) {
  int cnt = 0;
  queue<Point> q;
  q.push({x, y, z});
  inq[x][y][z] = true;
  while (not q.empty()) {
    Point t = q.front();
    q.pop();
    cnt++;
    for (int i = 0; i < 6; i++) {
      int tx = t.x + X[i];
      int ty = t.y + Y[i];
      int tz = t.z + Z[i];
      if (can_visit(tx, ty, tz)) {
        q.push({tx, ty, tz});
        inq[tx][ty][tz] = true;
      }
    }
  }
  return cnt >= threshold ? cnt : 0;
}

int main() {
  cin >> n >> m >> slices >> threshold;
  for (int z = 0; z < slices; z++)
    for (int x = 0; x < n; x++)
      for (int y = 0; y < m; y++) cin >> pixel[x][y][z];

  int total = 0;
  for (int z = 0; z < slices; z++)
    for (int x = 0; x < n; x++)
      for (int y = 0; y < m; y++)
        if (pixel[x][y][z] == 1 && not inq[x][y][z]) total += bfs(x, y, z);

  cout << total;
  return 0;
}