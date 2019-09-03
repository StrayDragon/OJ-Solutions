# 判断是否为闰年 
```cpp
bool is_leap(int yyyy){
  return (yyyy % 4 == 0 and yyyy % 100 != 0) or (yyyy % 400)
}
```


# 其他有趣的代码段
## 输出一段序列, 空格间隔, 最后无空格
```cpp
//...
for (auto itr = items.begin(); itr != items.end(); ++itr) {
  if (next(itr) == end(items))
    printf("%d %.1lf", itr->first, itr->second);
  else
    printf("%d %.1lf ", itr->first, itr->second);
}
//...
```

# 取消与C的标准输入输出流同步,并提高iostream速度
```cpp
#include <iostream>
static const auto __ = []() {
  std::ios::sync_with_stdio(false); // 主要作用, 可简单加在 main() 中所有语句之前
  std::cin.tie(nullptr);
  return nullptr;
}();
```