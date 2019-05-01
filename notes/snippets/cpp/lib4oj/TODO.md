# 有用的算法库函数 <algorithm>
## 排序,找大小
- [ ] std::partition          // 用于划分范围
  - [ ] std::stable_partition // 用于稳定划分范围
- [ ] std::nth_element        // 用于第k大/小问题;
- [ ] std::partial_sort       // 用于局部范围排序;
- [ ] std::sort               // 用于全范围排序
  - [ ] std::stable_sort      // 用于稳定排序
## 针对查找:
- [ ] std::find, std::find_if,
- [ ] std::count, std::count_if,
- [ ] std::binary_search
- [ ] std::lower_bound, std::upper_bound
- [ ] std::equal_range

## 工具相关:
- [ ] std::for_each

# 容器相关 <*container*> {vector,deque,map,set...}
- 以下不给出具体的容器名,而以占位符 *container* 代替

- [ ] *container*::assign
- [ ] *container*::insert
  - [ ] *container*::iterator 
    - std::inserter
    - std::back_inserter
    - std::front_inserter
- [ ] *container*::copy
- [ ] *container*::erase

## 字符串
- [ ] string::substr

# 迭代器相关 <iterator>
- [ ] std::prev, std::next
- [ ] std::begin, std::end
- [ ] std::distance

# 函数相关: <functional>
## 比较子
- [ ] std::less, std::greater
- [ ] std::less_equal, std::greater_equal
