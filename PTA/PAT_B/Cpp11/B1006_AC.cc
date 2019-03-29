#include <functional>
#include <iostream>
#include <string>
using namespace std;

void retrieve_last_digit(int& num, function<void(int)> deal_with) {
  if (num != 0) {
    int n = (num % 10);
    deal_with(n);
    num /= 10;
  }
}

int main() {
  int num;
  cin >> num;
  string result;

  retrieve_last_digit(num, [&](int n) {
    for (int i = n; i >= 1; i--) {
      result.push_back('0' + i);
    }
  });

  retrieve_last_digit(num, [&](int n) {
    for (int i = 0; i < n; i++)
      result.push_back('S');
  });

  retrieve_last_digit(num, [&](int n) {
    for (int i = 0; i < n; i++)
      result.push_back('B');
  });

  for (auto it = result.rbegin(); it != result.rend(); ++it)
    cout << *it;
  return 0;
}