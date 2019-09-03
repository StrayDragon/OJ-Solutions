#pragma once

#include <algorithm>
#include <ctime>

namespace algo {
namespace search {

/**
 * @brief 从 A 中查找第一个大于等于 x 的数
 *
 * @param A 目标数组
 * @param left 左边界
 * @param right 右边界
 * @param x 待查找数
 * @return int 目标位置下标,否则返回数组大小
 */
int lower_bound(int A[], int left, int right, int x) {
  for (int mid; left < right;) {
    // mid = (left + right) / 2; // 可能溢出
    mid = left + (right - left) / 2;
    if (A[mid] >= x)
      right = mid;
    else
      left = mid + 1;
  }
  return left;
}

/**
 * @brief 从 A 中查找第一个大于 x 的数
 *
 * @param A 目标数组
 * @param left 左边界
 * @param right 右边界
 * @param x 待查找数
 * @return int 目标位置下标,否则返回数组大小
 */
int upper_bound(int A[], int left, int right, int x) {
  for (int mid; left < right;) {
    // mid = (left + right) / 2; // 可能溢出
    mid = left + (right - left) / 2;
    if (A[mid] > x)
      right = mid;
    else
      left = mid + 1;
  }
  return left;
}

namespace {
/**
 * @brief 选取随机主元,对[left,right]划分
 *
 * @param A
 * @param left
 * @param right
 * @return int 交合处数组下标
 */
int _rand_partition(int A[], int left, int right) {
  int pivot =
      (std::round(1.0 * std::rand() / RAND_MAX * (right - left) + left));
  std::swap(A[pivot], A[right]);
  int t = A[left];
  while (left < right) {
    while (left < right && A[right] > t) right--;
    A[left] = A[right];
    while (left < right && A[left] <= t) left++;
    A[right] = A[left];
  }
  A[left] = t;
  return left;
}
}  // namespace

/**
 * @brief 查找数组中第k大元素位置
 *
 * @param A
 * @param left
 * @param right
 * @param k
 * @return int 数组下标
 */
int find_kst(int A[], int left, int right, int k) {
  if (left == right) return left;
  int pivot = _rand_partition(A, left, right);
  int m = pivot - left + 1;
  if (k == m) return pivot;
  if (k < m)
    return find_kst(A, left, pivot - 1, k);
  else
    return find_kst(A, pivot + 1, right, k - m);
}

}  // namespace search
}  // namespace algo