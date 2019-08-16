// ---
// id         : 1108
// title      : Finding Average
// difficulty : Easy
// score      : 20
// tag        : TODO
// keyword    : TODO
// status     : AC
// from       : PAT (Advanced Level) Practice
// ---

// reference: https://www.liuchuo.net/archives/1924

#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int main() {
  int n, cnt = 0;
  cin >> n;
  char bufin[50], bufout[50];
  double temp, sum = 0.0;
  for (int i = 0; i < n; i++) {
    scanf("%s", bufin);
    sscanf(bufin, "%lf", &temp);
    sprintf(bufout, "%.2f", temp);
    bool is_valid = true;
    for (int j = 0; j < strlen(bufin); j++)
      if (bufin[j] != bufout[j])
        is_valid = false;
    if (!is_valid || temp < -1000 || temp > 1000) {
      printf("ERROR: %s is not a legal number\n", bufin);
      continue;
    } else {
      sum += temp;
      cnt++;
    }
  }
  if (cnt == 1)
    printf("The average of 1 number is %.2f", sum);
  else if (cnt > 1)
    printf("The average of %d numbers is %.2f", cnt, sum / cnt);
  else
    printf("The average of 0 numbers is Undefined");
  return 0;
}