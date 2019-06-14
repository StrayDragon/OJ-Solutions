#include <cctype>
#include <iostream>

using namespace std;
const int MAXN = 200005;

int seq[MAXN];

int main() {
  int n1, n2;

  scanf("%d", &n1);
  for (int i = 0; i < n1; i++)
    scanf("%d", &seq[i]);
  seq[n1] = INT32_MAX;

  scanf("%d", &n2);
  int result, cnt = 0, i = 0, median = (n1 + n2 + 1) / 2;
  for (int tmp; n2--;) {
    scanf("%d", &tmp);
    while (seq[i] < tmp) {
      cnt++;
      if (cnt == median) {
        result = seq[i];
        break;
      }
      i++;
    }
    cnt++;
    if (cnt == median) {
      result = tmp;
      break;
    }
  }
  while (i < n1) {
    cnt++;
    if (cnt == median) {
      result = seq[i];
      break;
    }
    i++;
  }
  printf("%d", result);

  return 0;
}