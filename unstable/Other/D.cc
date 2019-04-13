#include <stdio.h>
#include <string.h>

void kmp_get_next(int next[], const char s[], int len) {
  int j = -1;
  next[0] = -1;
  for (int i = 1; i < len; i++) {
    while (j != -1 && s[i] != s[j + 1])
      j = next[j];
    if (s[i] == s[j + 1])
      j++;
    next[i] = j;
  }
}

int kmp_substring(const char* text, const char* pattern) {
  int txt_len = strlen(text);
  int ptn_len = strlen(pattern);

  const size_t DSIZE = 20;
  int default_next_arr[DSIZE] = {0};
  kmp_get_next(default_next_arr, pattern, ptn_len);
  int j = -1;
  for (int i = 0; i < txt_len; i++) {
    while (j != -1 && text[i] != pattern[j + 1])
      j = default_next_arr[j];
    if (text[i] == pattern[j + 1])
      j++;
    if (j == ptn_len - 1) {
      return 1;
    }
  }
  return 0;
}

char passwords[20000][20];
int main() {
  for (int i = 0; i < 20000; i++)
    for (int j = 0; j < 20; j++)
      passwords[i][j] = '\0';

  int n;
  scanf("%d\n", &n);
  for (int i = 0; i < n; i++) {
    for (int d, j = 0;; j++) {
      d = getchar();
      if (d != '\n')
        passwords[i][j] = d;
      else
        break;
    }
  }

  int m;
  scanf("%d", &m);
  for (int case_cnt = 1; case_cnt <= m; case_cnt++) {
    printf("Case #%d:\n", case_cnt);
    char guess[11] = {0};
    scanf("%s", guess);
    getchar();
    int matched = 0;
    for (int i = 0; i < n; i++) {
      if (kmp_substring(passwords[i], guess)) {
        matched = 1;
        break;
      }
    }
    if (matched) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }

  return 0;
}