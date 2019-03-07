#define CATCH_CONFIG_MAIN
#include "catch.hpp"

// 引入待测试目标
#include "../../snippets/string_related/c99/kmp_substring.c"
// 引入完毕

TEST_CASE("测试KMP算法", "[kmp_substring]") {
  const char* hitted_text = "xxxxabababcxx";
  const char* not_hitted_text = "xxabaxxbabcxx";
  const char* pattern = "abababc";

  SECTION("验证计算next数组") {
    int32_t next[7] = {0};
    uint32_t len = strlen(pattern);
    kmp_get_next(next, pattern, len);
    int32_t expected[] = {-1, -1, 0, 1, 2, 3, -1};
    for (uint32_t i = 0; i < len; ++i) {
      REQUIRE(next[i] == expected[i]);
    }
  }

  SECTION("验证KMP子字符串查找算法") {
    const int32_t ERR_MALLOC_FAILED = -1;
    const int32_t OK_IS_FOUND = 1;
    const int32_t OK_NOT_FOUND = 0;

    int result_code_1 = kmp_substring(hitted_text, pattern);
    CHECK(result_code_1 != ERR_MALLOC_FAILED);
    REQUIRE(result_code_1 == OK_IS_FOUND);

    int result_code_2 = kmp_substring(not_hitted_text, pattern);
    CHECK(result_code_2 != ERR_MALLOC_FAILED);
    REQUIRE(result_code_2 == OK_NOT_FOUND);
  }
}