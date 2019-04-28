#ifndef __KMP_SUBSTRING_H
#define __KMP_SUBSTRING_H

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief 求解长度为 len 的 字符串 (char 数组) s 的 next 数组
 *
 * @param next 外部初始化好的长度为s_len的next数组,用于回溯状态
 * @param s char数组(字符串)
 * @param len s的长度
 */
void kmp_get_next(int32_t next[], char s[], uint32_t len);

/**
 * @brief 验证 pattern 是否为 text 的子串
 *
 * @param text 目标字符串 (char数组)
 * @param pattern 待验证子串 (char数组)
 * @return int 匹配结果:(1,成功),(0,失败),(-1,内部错误)
 */
int kmp_substring(const char* text, const char* pattern);

#endif