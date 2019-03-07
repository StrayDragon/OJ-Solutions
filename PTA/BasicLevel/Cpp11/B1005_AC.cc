#include <algorithm>
#include <cstdio>

using namespace std;
int main() {
  int k, m, input[110];
  scanf("%d", &k);
  bool hash_table[10000] = {0};
  for (size_t i = 0; i < k; i++) {
    scanf("%d", &input[i]);
    m = input[i];
    while (m != 1) {
      if (m % 2 == 1)
        m = (3 * m + 1) / 2;
      else
        m = m / 2;
      hash_table[m] = true;
    }
  }
  int cnt = 0;
  for (size_t i = 0; i < k; i++) {
    if (hash_table[input[i]] == false)
      cnt++;
  }
  
  sort(input, input + k, [](int lhs, int rhs) { return lhs > rhs; });

  for (size_t i = 0; i < k; i++) {
    if (hash_table[input[i]] == false) {
      printf("%d", input[i]);
      cnt--;
      if (cnt > 0)
        printf(" ");
    }
  }
  return 0;
}