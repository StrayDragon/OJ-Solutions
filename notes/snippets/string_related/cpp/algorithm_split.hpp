#pragma once
#include <algorithm>
#include <iterator>
#include <string>
namespace utils {

/**
 * @brief 适用于std::string的返回策略函数
 *
 */
auto string_splite_fn = [](std::string::iterator it1,
                           std::string::iterator it2) {
  return std::string(it1, it2);
};

/**
 * @brief 分割字符串算法 <br>
 *   e.g.: split(begin(info), end(info), back_inserter(t), ' ', bin_fn);

 *
 * @tparam InputItr 输入迭代器类型
 * @tparam OutputItr 输出迭代器类型
 * @tparam T 分割符号(separator)类型
 * @tparam F 返回策略类型,可以使用提供的 string_splite_fn
 * @param it begin(?)迭代器
 * @param end_it end(?)迭代器
 * @param out_it 输出迭代器,推荐back_inserter
 * @param separator 分割符号(char)
 * @param bin_fn 返回策略
 * @return InputItr begin(?)输入迭代器
 */
template <typename InputItr, typename OutputItr, typename T, typename F>
InputItr split(InputItr it,
               InputItr end_it,
               OutputItr out_it,
               T separator,
               F bin_fn) {
  while (it != end_it) {
    auto slice_end = std::find(it, end_it, separator);
    *out_it++ = bin_fn(it, slice_end);

    if (slice_end == end_it)
      return end_it;
    it = std::next(slice_end);
  }
  return it;
}

}  // namespace utils
