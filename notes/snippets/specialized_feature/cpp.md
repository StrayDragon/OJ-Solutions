# 取消与C的io同步 cancel_sync_stdio

```cpp
#include <iostream>
static const auto __ = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return nullptr;
}();
```