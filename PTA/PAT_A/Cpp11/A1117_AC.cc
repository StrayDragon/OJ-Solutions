// ---
// id         : 1117
// title      : Eddington Number
// difficulty : Medium
// score      : 25
// tag        : TODO
// keyword    : TODO
// status     : AC
// from       : PAT (Advanced Level) Practice
// ---

#include <algorithm>
#include <cstdio>
#include <functional>

using namespace std;

int arr[1000000];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  std::sort(arr, arr + n, greater<int>());
  int e;
  for (e = 0; e < n && arr[e] > e + 1;)
    e++;
  printf("%d", e);
  return 0;
}