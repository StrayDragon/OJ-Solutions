#include <cmath>

#include "catch2/catch.hpp"

#include "../../src/Math/Algebra.hpp"

using namespace math::algebra;
TEST_CASE("math::algebra usages", "[Algebra]") {
  auto a = 2LL;
  auto b = 4LL;
  long long expect = std::pow(a, b);

  SECTION("binpow") {
    auto actual = binpow(a, b);
    REQUIRE(actual == expect);
  }

  SECTION("binpow_rec") {
    auto actual = binpow_rec(a, b);
    REQUIRE(actual == expect);
  }
}