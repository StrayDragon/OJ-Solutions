#pragma once

namespace oj {
namespace strings {
// extern int next[10];

/**
 * @brief 求解长度为 len 的 字符串 (char 数组) s 的 next 数组
 *
 * @param s char数组(字符串)
 * @param len s的长度
 */
void kmp_get_next(char s[], int len);

/**
 * @brief 验证 pattern 是否为 text 的子串
 *
 * @param text 目标字符串 (char数组)
 * @param pattern 待验证子串 (char数组)
 * @return int 匹配结果:(1,成功),(0,失败),(-1,内部错误)
 */
bool kmp(char text[], char pattern[]);

}  // namespace strings
void example_pattern_match_kmp();

}  // namespace oj

#include "impl/kmp.cpp"