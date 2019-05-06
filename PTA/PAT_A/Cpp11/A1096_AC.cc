// 参考: https://blog.csdn.net/liuchuo/article/details/52139124

#include <cmath>
#include <iostream>
using namespace std;
int main() {
  int n;
  cin >> n;
  int max = std::sqrt(n);
  for (int len = 12; len >= 1; len--) {
    for (int s = 2; s <= max; s++) {
      long long int result = 1;
      for (int i = s; i - s <= len - 1; i++)
        result *= i;
      if (n % result == 0) {
        cout << len << '\n';
        cout << s;
        for (int i = s + 1; i - s <= len - 1; i++)
          cout << '*' << i;
        return 0;
      }
    }
  }
  cout << "1\n" << n;
  return 0;
}