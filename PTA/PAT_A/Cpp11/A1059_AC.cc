#include <cmath>
#include <iostream>

using namespace std;

bool is_prime(int num) {
  if (num == 1) return false;
  int sqr = (int)std::sqrt(num);
  for (int i = 2; i <= sqr; i++) {
    if (num % i == 0) return false;
  }
  return true;
}

int prime_table[100010], prime_cnt = 0;
static auto prime_gen = []() {
  for (int num = 1; num < 100010; num++) {
    if (is_prime(num)) prime_table[prime_cnt++] = num;
  }
  return nullptr;
}();

struct Factor {
  int x, cnt;
} factors[10];

int main() {
  int n;
  cin >> n;
  if (n == 1) {
    cout << "1=1";
  } else {
    cout << n << "=";
    int pcnt = 0, sqr = (int)sqrt(n);
    for (int i = 0; i < prime_cnt && prime_table[i] <= sqr; i++) {
      if (n % prime_table[i] == 0) {
        factors[pcnt].x = prime_table[i];
        factors[pcnt].cnt = 0;
        while (n % prime_table[i] == 0) {
          factors[pcnt].cnt++;
          n /= prime_table[i];
        }
        pcnt++;
      }
      if (n == 1) break;
    }
    if (n != 1) {
      factors[pcnt].x = n;
      factors[pcnt++].cnt = 1;
    }
    for (int i = 0; i < pcnt; i++) {
      if (i != 0) cout << "*";
      cout << factors[i].x;
      if (factors[i].cnt > 1) cout << '^' << factors[i].cnt;
    }
  }
  return 0;
}