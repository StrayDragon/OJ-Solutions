// ---
// id         : 1015
// title      : Reversible Primes
// difficulty : Easy
// score      : 20
// tag        : TODO
// keyword    : TODO
// status     : AC
// from       : PAT (Advanced Level) Practice
// ---

#include <cmath>
#include <iostream>

bool is_prime(int n) {
  if (n <= 1)
    return false;
  int bound = (int)std::sqrt(1.0 * n);
  for (int i = 2; i <= bound; ++i)
    if (n % i == 0)
      return false;
  return true;
}

int digits[110];
int reverse_redix_convert(int n, int d) {
  int len = 0;
  do {
    digits[len++] = n % d;
    n /= d;
  } while (n != 0);
  for (int i = 0; i < len; i++) {
    n = n * d + digits[i];
  }
  return n;
}

using namespace std;
int main() {
  int n, d;
  while (true) {
    cin >> n;
    if (n < 0)
      break;
    cin >> d;
    if (is_prime(n) && is_prime(reverse_redix_convert(n, d)))
      cout << "Yes\n";
    else
      cout << "No\n";
  }

  return 0;
}