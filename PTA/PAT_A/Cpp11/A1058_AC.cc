// ---
// id         : 1058
// title      : A+B in Hogwarts
// difficulty : Easy
// score      : 20
// tag        : TODO
// keyword    : TODO
// status     : AC
// from       : PAT (Advanced Level) Practice
// ---

#include <cstdio>

using namespace std;

int main() {
  int g1, s1, k1, g2, s2, k2;
  scanf("%d.%d.%d %d.%d.%d", &g1, &s1, &k1, &g2, &s2, &k2);
  int k = (k1 + k2) % 29, carry = (k1 + k2) / 29;
  int s = (s1 + s2 + carry) % 17;
  carry = (s1 + s2 + carry) / 17;
  int g = g1 + g2 + carry;
  printf("%d.%d.%d\n", g, s, k);
  return 0;
}