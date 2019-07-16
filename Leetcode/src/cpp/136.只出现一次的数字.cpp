/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */
class Solution {
   public:
    int singleNumberSlow(vector<int>& nums) {
        int res;
        for (size_t i = 0; i < nums.size(); ++i)
            if (count(nums.begin(), nums.end(), nums[i]) == 1)
                res = nums[i];
        return res;
    }
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (size_t i = 0; i < nums.size(); ++i)
            res ^= nums[i];
        return res;
    }
};