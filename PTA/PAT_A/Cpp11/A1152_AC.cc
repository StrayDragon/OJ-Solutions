#include <cmath>
#include <iostream>
#include <string>

using namespace std;

bool is_prime(int n) {
  if (n <= 1)
    return false;
  int bound = std::sqrt(1.0 * n);
  for (int i = 2; i < bound; i++)
    if (n % i == 0)
      return false;
  return true;
}

int main() {
  int l, k;
  string n;
  cin >> l >> k >> n;
  for (int num, i = 0; i <= l - k; i++) {
    string tmp = n.substr(i, k);
    if (is_prime(num = stoi(tmp))) {
      cout << tmp;
      return 0;
    }
  }
  cout << "404\n";
  return 0;
}