#include <bits/stdc++.h>

#include "catch2/catch.hpp"

#define ALL(x) begin(x), end(x)
using std::begin;
using std::end;
using std::vector;

TEST_CASE("next_permutation usages", "[std],[algorithm]") {
  vector<int> actual{1, 2, 3};
  vector<int> expect[6]{
      {1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {2, 3, 1}, {3, 1, 2}, {3, 2, 1},
  };
  int now = 0;
  do {
    REQUIRE(actual == expect[now++]);
  } while (std::next_permutation(ALL(actual)));
}

using std::greater;
using std::less;
using std::priority_queue;
TEST_CASE("priority_queue usages", "[std],[queue]") {
  priority_queue<int, vector<int>, less<int>> pq;
  priority_queue<int, vector<int>, greater<int>> pq2;
}