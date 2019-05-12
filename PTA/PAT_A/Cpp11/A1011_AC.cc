#include <cstdio>

using namespace std;

int main() {
  char session_dict[3] = {'W', 'T', 'L'};
  double infos[3][3];
  double maximum, profit = 1;
  for (int no, i = 0; i < 3; ++i) {
    no = maximum = 0;
    for (int j = 0; j < 3; ++j) {
      scanf("%lf", &infos[i][j]);
      if (maximum < infos[i][j]) {
        maximum = infos[i][j];
        no = j;
      }
    }
    profit *= maximum;
    printf("%c ", session_dict[no]);
  }
  profit *= 0.65;
  profit = (profit - 1) * 2;
  printf("%.2lf\n", profit);
  return 0;
}