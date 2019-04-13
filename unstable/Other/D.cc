#include <stdio.h>
#include <string.h>

#define SIZE 256

int MoveByGS(int j, int m, int suffix[], bool prefix[]) {
  int k = m - j - 1;  // 好后缀长度
  if (suffix[k] != -1) return j + 1 - suffix[k];

  for (int r = j + 2; r < m; r++) {
    if (prefix[m - r] == true) return r;
  }

  return m;
}

// 生成好后缀数组
void GenerateGS(char str[], int m, int suffix[], bool prefix[]) {
  for (int i = 0; i < m; i++) {
    suffix[i] = -1;
    prefix[i] = false;
  }

  // [0, i] 的子串和模式串求公共后缀子串
  for (int i = 0; i < m - 1; i++) {
    int j = i;
    int k = 0;
    while (j >= 0 && str[j] == str[m - 1 - k])  // 下标都向前移动
    {
      j--;
      k++;
    }

    if (k != 0) suffix[k] = j + 1;  // 公共后缀子串的起始位置
    if (j == -1) prefix[k] = true;  // 公共后缀子串同时也是模式串的前缀子串
  }
}

// 生成坏字符对应的散列表
void GenerateBC(char str[], int m, int bc[]) {
  // 所有字符初始化为 -1
  for (int i = 0; i < SIZE; i++) {
    bc[i] = -1;
  }

  for (int i = 0; i < m; i++) {
    int ascii = str[i] - '\0';  // 求出字符对应的 ASCII 码
    bc[ascii] = i;
  }
}

int BM(char str1[], int n, char str2[], int m) {
  int bc[SIZE];  // 记录每个字符在模式串中最后出现的位置，作为坏字符散列表
  GenerateBC(str2, m, bc);

  int suffix[m];
  bool prefix[m];
  GenerateGS(str2, m, suffix, prefix);

  int i = 0;    // 表示主串和模式串对齐时第一个字符的位置
  int si = 0;   // 坏字符对应于模式串中的位置
  int xi = -1;  // 坏字符在模式串中最后出现的位置

  while (i <= n - m) {
    int j = 0;
    // 从后向前进行匹配
    for (j = m - 1; j >= 0; j--) {
      // 找到了第一个不匹配的字符
      if (str1[i + j] != str2[j]) break;
    }

    if (j < 0) return i;  // 匹配成功

    si = j;
    xi = bc[str1[i + j] - '\0'];
    int x = si - xi;  // 坏字符规则应该向后移动的位数
    int y = 0;        // 好后缀规则应该向后移动的位数

    if (j < m - 1) y = MoveByGS(j, m, suffix, prefix);

    x = x > y ? x : y;
    i = i + x;
  }

  return -1;
}

char passwords[20000][20];
int main() {
  for (int i = 0; i < 20000; i++)
    for (int j = 0; j < 20; j++) passwords[i][j] = '\0';

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
      if (BM(passwords[i], strlen(passwords[i]), guess, strlen(guess)) != -1) {
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