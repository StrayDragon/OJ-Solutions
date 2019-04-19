#include <cstdio>
#include <cstring>

bool sunday(char* text, char* patt) {
  size_t temp[256];
  size_t* shift = temp;
  size_t i, patt_size = strlen(patt), text_size = strlen(text);
  for (i = 0; i < 256; i++)
    *(shift + i) = patt_size + 1;
  for (i = 0; i < patt_size; i++)
    *(shift + char(*(patt + i))) = patt_size - i;
  size_t limit = text_size - patt_size + 1;
  for (i = 0; i < limit; i += shift[int(text[i + patt_size])])
    if (text[i] == *patt) {
      char* match_text = text + i + 1;
      size_t match_size = 1;
      do {  // 输出所有匹配的位置
        if (match_size == patt_size) {
          return true;
        }
      } while ((*match_text++) == patt[match_size++]);
    }
  return false;
}

char passwords[20010][15];
int main() {
  for (int i = 0; i < 20010; i++)
    for (int j = 0; j < 15; j++)
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
    char guess[15] = {0};
    scanf("%s", guess);
    getchar();
    int matched = 0;
    for (int i = 0; i < n; i++) {
      if (sunday(passwords[i], guess)) {
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