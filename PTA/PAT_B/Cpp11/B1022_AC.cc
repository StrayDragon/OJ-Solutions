#include <algorithm>
#include <iostream>
#include <iterator>
using namespace std;

int main() {
  int a, b, d;
  cin >> a >> b >> d;
  int sum = a + b;
  int digits[31], cnt = 0;
  do {
    digits[cnt++] = sum % d;
    sum /= d;
  } while (sum != 0);
  std::reverse_copy(digits, digits + cnt, ostream_iterator<int>(cout));
  return 0;
}