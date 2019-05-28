#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
using namespace std;

struct Node {
  std::string data;
  int li, ri;
};

Node nodes[25];
bool visited[25];

string dfs(int root) {
  if (nodes[root].li == -1 && nodes[root].ri == -1)
    return nodes[root].data;
  if (nodes[root].li == -1 && nodes[root].ri != -1)
    return "(" + nodes[root].data + dfs(nodes[root].ri) + ")";
  if (nodes[root].li != -1 && nodes[root].ri != -1)
    return "(" + dfs(nodes[root].li) + nodes[root].data + dfs(nodes[root].ri) +
           ")";
  return "";
}

int main() {
  int n;
  cin >> n;
  string data;
  for (int i = 1; i <= n; ++i) {
    cin >> nodes[i].data >> nodes[i].li >> nodes[i].ri;
    if (nodes[i].li != -1)
      visited[nodes[i].li] = true;

    if (nodes[i].ri != -1)
      visited[nodes[i].ri] = true;
  }

  int root = 0;
  for (int i = 1; i <= n; ++i) {
    if (!visited[i]) {
      root = i;
      break;
    }
  }

  string result = dfs(root);
  if (result[0] == '(') {
    std::copy(result.begin() + 1, result.begin() + result.length() - 1,
              std::ostream_iterator<char>(cout));
    return 0;
  }
  cout << result;

  return 0;
}