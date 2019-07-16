/*
 * @lc app=leetcode.cn id=387 lang=cpp
 *
 * [387] 字符串中的第一个唯一字符
 */
class Solution {
  int cnt[256];

 public:
  int firstUniqChar(string s) {
    std::fill(cnt, cnt + 256, 0);
    for (auto &&c : s) {
      cnt[c]++;
    }
    for (int i = 0; i < s.size(); i++) {
      if (cnt[s[i]] == 1) return i;
    }
    return -1;
  }
};

