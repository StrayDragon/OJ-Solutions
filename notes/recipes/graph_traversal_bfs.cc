#include <iostream>
#include <vector>

using namespace std;

// DFS(v)
//   在 v 上打访问标记
//   for u in v的相邻节点
//     if u 没有打过访问标记 then
//       DFS(i)

// BFS(v)
//   定义队列, v 入队
//   while 队列不空
//     取队首元素访问
//     for u in v的相邻节点
//       if u 没有打过访问标记 then
//         u 入队并标记

// Traverse()
//   for `v` in `G`
//     if `v` is not visited
//       BFS/DFS (`v`)

struct AdjListGraph {
  using EdgeInfo = int;
  static const int V = 10;

 public:
  int n;
  vector<EdgeInfo> G[V];
  static bool visited[V];
};

struct MatrixGraph {
  static const int V = 10;
  using EdgeInfo = int;

 public:
  int n;
  EdgeInfo G[V][V];
  static bool visited[V];
};

int main() { return 0; }