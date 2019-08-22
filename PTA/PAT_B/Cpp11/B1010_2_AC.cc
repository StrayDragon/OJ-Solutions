#include <iostream>
using namespace std;

int main() {
  static int e2c[1010];
  int c, e, cnt = 0;
  while (cin >> c >> e) e2c[e] = c;

  e2c[0] = 0;
  for (int i = 1; i <= 1000; i++) {
    e2c[i - 1] = e2c[i] * i;
    e2c[i] = 0;
    if (e2c[i - 1] != 0) cnt++;
  }

  if (cnt == 0)
    cout << "0 0";
  else {
    for (int i = 1000; i >= 0; i--) {
      if (e2c[i] != 0) {
        cout << e2c[i] << " " << i;
        cnt--;
        if (cnt != 0) cout << " ";
      }
    }
  }
  return 0;
}