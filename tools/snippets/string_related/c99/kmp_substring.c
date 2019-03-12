#include "kmp_substring.h"

static int32_t* __get_tmp_next_arr__(uint32_t ptn_len) {
  int32_t* next_arr = (int32_t*)malloc(ptn_len);
  return next_arr;
}

void kmp_get_next(int32_t next[], const char s[], uint32_t len) {
  int32_t j = -1;
  next[0] = -1;
  for (uint32_t i = 1; i < len; i++) {
    while (j != -1 && s[i] != s[j + 1])
      j = next[j];
    if (s[i] == s[j + 1])
      j++;
    next[i] = j;
  }
}

int kmp_substring(const char* text, const char* pattern) {
  uint32_t txt_len = strlen(text);
  uint32_t ptn_len = strlen(pattern);
  int32_t* next = NULL;

  //---算法无关,以下
  const size_t DSIZE = 40;
  int32_t default_next_arr[DSIZE] = {0};
  int heap_arr_flag = 0;
  // if (ptn_len < DSIZE)
  next = default_next_arr;
  // else {
  //   next = __get_tmp_next_arr__(ptn_len);
  //   heap_arr_flag = 1;
  // }
  // if (heap_arr_flag && next == NULL)
  //   return -1;
  //---算法无关,以上

  kmp_get_next(next, pattern, ptn_len);
  int j = -1;
  for (uint32_t i = 0; i < txt_len; i++) {
    while (j != -1 && text[i] != pattern[j + 1])
      j = next[j];
    if (text[i] == pattern[j + 1])
      j++;
    if (j == ptn_len - 1) {
      if (heap_arr_flag && next != NULL) {
        free(next);
        next = NULL;
      }
      return 1;
    }
  }
  if (heap_arr_flag && next != NULL) {
    free(next);
    next = NULL;
  }
  return 0;
}