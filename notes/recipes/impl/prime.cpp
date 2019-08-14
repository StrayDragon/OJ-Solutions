#include <cmath>

namespace oj {
namespace math {

bool is_prime(int n) {
  if (n <= 1)
    return false;
  int bound = (int)std::sqrt(1.0 * n);
  for (int i = 2; i <= bound; ++i)
    if (n % i == 0)
      return false;
  return true;
}

[[deprecated("INFO: May overflow from the previous implementation  ")]] bool
is_smallprime(int n) {
  if (n <= 1)
    return false;
  for (int i = 2; i * i <= n; ++i)
    if (n % i == 0)
      return false;
  return true;
}

}  // namespace math
}  // namespace oj

#include "../preinclude.hpp"
namespace oj {
void example_judge_prime_number() {
  using namespace std;
  using oj::math::is_prime;
  eg::start();
  cout << "In oj::example_judge_prime_number\n";

  cout << "Is 2 a prime number?" << boolalpha << is_prime(2) << endl;
  cout << "Is 283 a prime number?" << boolalpha << is_prime(283) << endl;
  cout << "Is 547 a prime number?" << boolalpha << is_prime(547) << endl;
  cout << "Is 719 a prime number?" << boolalpha << is_prime(719) << endl;
  cout << "Is 24 a prime number?" << boolalpha << is_prime(2) << endl;
  cout << "Is 12 a prime number?" << boolalpha << is_prime(2) << endl;
  eg::over();
}

}  // namespace oj