# 经典算法 实现
- 第四章
  - 4.3
  - [ ] [递归] 针对 $1$ ~ $n$ 的全排列
  - [ ] [递归] [回朔] 判断 $n$皇后 及确定多少种解法, 回朔剪枝的解法
  - [ ] 

# 与标准输入/输出打交道 Standard I/O,

## I/O stream \<iostream>
### std::cin 
### std::cont

## I/O manipulator \<iomanip>
### std::fixed 
### std::netflix 
### std::setprecision 

## C standard I/O \<cstdio>
### std::scanf 
### std::printf 
### std::puts 
### std::sprintf 
### std::sscanf 
### std::getchar 
### std::putchar 

## Tips
### [优化性能] 取消与 C 标准I/O流同步 cancel_sync_stdio
```cpp
#include <iostream>
static const auto __ = []() {
  std::ios::sync_with_stdio(false); // 主要作用, 可简单加在 main() 中所有语句之前
  std::cin.tie(nullptr);
  return nullptr;
}();
```

## 操纵字符串 Strings

## C 原生字符串 \<cstring>

### std::memset 
- 注意按字节赋值, 慎用
### std::striate

### std::strcmp

### std::strcpy

### std::strlen

## C++ 字符串 \<string>
### *string*::substr
### 标志
#### *string*::npos

# 数学魔法 Maths
## C 数学库 \<cmath>
### std::ceil 
### std::floor 
### std::round 

### std::fabs 
```cpp
#define FP_EQ(a, b) ((fabs((a) - (b))) < (1e-8))

#define FP_GT(a, b) (((a) - (b)) > (1e-8))

#define FP_GT_EQ(a, b) (((a) - (b)) > (-1e-8))

#define FP_LT(a, b) (((a) - (b)) < (-1e-8))

#define FP_LT_EQ(a, b) (((a) - (b)) < (1e-8))
```
### std::log    
  - 默认以$e$为底, 计算任意底请使用换底公式: $log_a^b = log_e^b / log_e^a$
### std::pow 
### std::sqrt 
### std::acos, std::asin, std::atan 
```cpp
const double PI = acos(-1);
```
### std::cos, std::sin, std::tan 


# 实用的算法 Algorithm 
## Algorithm \<algorithm>
### 排序,找大小
#### std::partition          #用于划分范围
##### std::stable_partition  #用于稳定划分范围
#### std::nth_element        #用于第k大/小问题 
#### std::partial_sort       #用于局部范围排序 
#### std::sort               #用于全范围排序
##### std::stable_sort       #用于稳定排序

### 针对查找:
#### std::find, std::find_if,
#### std::count, std::count_if,
#### std::binary_search
#### std::lower_bound, std::upper_bound
#### std::equal_range
### 遍历工具:
#### std::for_each

# 牛逼的容器和迭代器 
- 以下不给出具体的容器名,而以占位符 *container* 代替

## 一堆容器 \<*container*> \{vector,deque,map,set...}
### *container*::assign
### *container*::insert
### *container*::iterator 
### *container*::copy
### *container*::erase

## 不可变容器? \<tuple>

## 迭代器 \<iterator>
### std::prev, std::next
### std::begin, std::end
```cpp
#define ALL(x) begin(x), end(x)

#define RNG_N(x, n) begin(x), begin(x) + n
```
### std::distance
### std::inserter
### std::back_inserter
### std::front_inserter
### std::ostream_iterator

# 函数式支持: 
## functor \<functional>
### std::less, std::greater
### std::less_equal, std::greater_equal
