#pragma once

namespace algo {
namespace seq {

/**
 * @brief 合并两个有序数组
 *
 * @param A
 * @param n 数组 A 大小
 * @param B
 * @param m 数组 B 大小
 * @param D 目标数组
 */
void merge(int A[], int n, int B[], int m, int D[]) {
  int i = 0, j = 0, idx = 0;
  while (i < n && j < m) {
    if (A[i] <= B[j])
      D[idx++] = A[i++];
    else
      D[idx++] = B[j++];
  }
  while (i < n) D[idx++] = A[i++];
  while (j < m) D[idx++] = B[j++];
}

}  // namespace seq
}  // namespace algo
