#include <algorithm>

#include "catch2/catch.hpp"

#include "../../src/Algorithm/SeqManip.hpp"

using namespace algo::seq;
TEST_CASE("algo::seq usages", "[SeqManip]") {
  int a[]{1, 3, 5, 7, 11, 233}, asize = sizeof(a) / sizeof(int);
  int b[]{2, 4, 6, 8, 10, 13, 888}, bsize = sizeof(b) / sizeof(int);
  static int actual[200], expect[200];

  for (int i = 0; i < asize; i++) expect[i] = a[i];
  for (int i = 0; i < bsize; i++) expect[asize + i] = b[i];
  std::sort(expect, expect + asize + bsize);

  SECTION("merge") {
    merge(a, asize, b, bsize, actual);
    for (int i = 0; i < asize + bsize; i++) REQUIRE(actual[i] == expect[i]);
  }
}