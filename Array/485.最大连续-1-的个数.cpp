/*
 * @lc app=leetcode.cn id=485 lang=cpp
 *
 * [485] 最大连续 1 的个数
 */
#include "Array.h"
// @lc code=start
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCount=0,count = 0;
        for (int i = 0;i < nums.size();i++) {
            if (nums[i] == 1) {
               count++; 
            } else {
                maxCount=max(maxCount,count);
                count=0;
            }
        }
        maxCount=max(maxCount,count);
        return maxCount;
    }
};
// @lc code=end

