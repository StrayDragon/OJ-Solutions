/*
 * @lc app=leetcode.cn id=219 lang=cpp
 *
 * [219] 存在重复元素 II
 */
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
      unordered_set<int> exist;
      for(int i = 0; i < nums.size(); i++){
        if(exist.find(nums[i]) != exist.end()) return true;
        exist.insert(nums[i]);
        if(exist.size() > k){
          exist.erase(nums[i-k]);
        }
      }
     return false;
    }
};