#include <algorithm>
#include <iterator>

#include "catch2/catch.hpp"

#include "../../src/Algorithm/Search.hpp"

using namespace algo::search;
using std::begin;
using std::distance;
using std::end;

TEST_CASE("algo::search usages", "[Search]") {
  SECTION("lower_bound") {
    int arr[]{1, 3, 3, 3, 6};
    int size = sizeof(arr) / sizeof(int);
    SECTION("  x < arr[0]") {
      int i = lower_bound(arr, 0, size, 0);
      REQUIRE(i == 0);

      auto it = std::lower_bound(arr, arr + size, 0);
      REQUIRE(distance(begin(arr), it) == 0);
    }

    SECTION("  x in arr") {
      int i = lower_bound(arr, 0, size, 3);
      REQUIRE(i == 1);

      auto it = std::lower_bound(arr, arr + size, 3);
      REQUIRE(distance(begin(arr), it) == 1);
    }

    SECTION("  x > arr[size-1]") {
      int i = lower_bound(arr, 0, size, arr[size - 1] + 1);
      REQUIRE(i == size);

      auto it = std::lower_bound(arr, arr + size, arr[size - 1] + 1);
      REQUIRE(it == end(arr));
    }
  }

  SECTION("upper_bound") {
    int arr[]{1, 3, 3, 3, 6};
    int size = sizeof(arr) / sizeof(int);

    SECTION("  x < arr[0]") {
      int i = upper_bound(arr, 0, size, 0);
      REQUIRE(i == 0);

      auto it = std::upper_bound(arr, arr + size, 0);
      REQUIRE(distance(begin(arr), it) == 0);
    }

    SECTION("  x in arr") {
      int i = upper_bound(arr, 0, size, 3);
      REQUIRE(i == 4);

      auto it = std::upper_bound(arr, arr + size, 3);
      REQUIRE(distance(begin(arr), it) == 4);
    }

    SECTION("  x > arr[size-1]") {
      int i = upper_bound(arr, 0, size, arr[size - 1] + 1);
      REQUIRE(i == size);

      auto it = std::upper_bound(arr, arr + size, arr[size - 1] + 1);
      REQUIRE(it == end(arr));
    }
  }

  SECTION("find_kst") {
    int arr[]{5, 12, 7, 2, 9, 3};
    int size = sizeof(arr) / sizeof(int);

    int i = find_kst(arr, 0, size-1, 3);
    REQUIRE(arr[i] == 5);
  }
}