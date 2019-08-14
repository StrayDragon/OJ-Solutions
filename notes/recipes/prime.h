#pragma once

namespace oj {
namespace math {

bool is_prime(int n);

bool is_smallprime(int n);

}  // namespace math
void example_judge_prime_number();
}  // namespace oj

#include "impl/prime.cpp"