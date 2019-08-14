#include <stdio.h>
#include <string.h>
// #define MAX_DIGITS 1000
const int MAX_DIGITS = 1000;
typedef struct BigInt {
  int d[MAX_DIGITS];
  int size;
} bign_t;

void _init(bign_t* n) {
  memset(n->d, 0, sizeof(n->d));
  n->size = 0;
}

bign_t change(char str[]) {
  bign_t bn;
  _init(&bn);
  bn.size = strlen(str);
  for (int i = 0; i < bn.size; i++)
    bn.d[i] = str[bn.size - i - 1] - '0';
  return bn;
}

int compare(bign_t lhs, bign_t rhs) {
  const int LHS_BIGGER = 1;
  const int RHS_BIGGER = -1;
  const int LHS_EQ_RHS = 0;

  if (lhs.size > rhs.size)
    return LHS_BIGGER;
  else if (lhs.size < rhs.size)
    return RHS_BIGGER;
  else {
    for (int i = lhs.size - 1; i >= 0; i--) {
      if (lhs.d[i] > rhs.d[i])
        return LHS_BIGGER;
      else if (lhs.d[i] < rhs.d[i])
        return RHS_BIGGER;
    }
    return LHS_EQ_RHS;
  }
}

bign_t add(bign_t lhs, bign_t rhs) {
  bign_t result;
  _init(&result);
  int carry = 0;
  for (int i = 0; i < lhs.size || i < rhs.size; i++) {
    int tmp = lhs.d[i] + rhs.d[i] + carry;
    result.d[result.size++] = tmp % 10;
    carry = tmp / 10;
  }
  if (carry != 0)
    result.d[result.size++] = carry;
  return result;
}

bign_t sub(bign_t lhs, bign_t rhs) {
  bign_t result;
  _init(&result);

  for (int i = 0; i < lhs.size || i < rhs.size; i++) {
    if (lhs.d[i] < rhs.d[i]) {
      lhs.d[i + 1]--;
      lhs.d[i] += 10;
    }
    result.d[result.size] = lhs.d[i] - rhs.d[i];
  }

  while (result.size - 1 >= 1 && result.d[result.size - 1] == 0) {
    result.size--;
  }

  return result;
}

bign_t multi(bign_t lhs, int multiplier) {
  bign_t result;
  _init(&result);
  int carry = 0;
  for (int i = 0; i < lhs.size; i++) {
    int tmp = lhs.d[i] * multiplier + carry;
    result.d[result.size++] = tmp % 10;
  }

  while (carry != 0) {
    result.d[result.size++] = carry % 10;
    carry /= 10;
  }

  return result;
}

bign_t divide(bign_t lhs, int divisor, int* remain) {
  bign_t result;
  _init(&result);
  result.size = lhs.size;
  for (int i = lhs.size - 1; i >= 0; i--) {
    *remain = *remain * 10 + lhs.d[i];
    if (*remain < divisor)
      result.d[i] = 0;
    else {
      result.d[i] = *remain / divisor;
      *remain = *remain % divisor;
    }
  }

  while (result.size - 1 >= 1 && result.d[result.size - 1] == 0) {
    result.size--;
  }

  return result;
}