/*
 * @lc app=leetcode.cn id=724 lang=cpp
 *
 * [724] 寻找数组的中心下标
 */
#include "Array.h"
// @lc code=start
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        //left sum: num[0]+..+num[i-1]=0
        //x=total-num[i]-x
        //2x+num[i]=total
        int sum=0;
        for (int i = 0;i < nums.size();i++) {
            if(2*sum+nums[i]==total)
                return i;
            sum+=nums[i];
        }
        return -1;
    }
};
// @lc code=end

//前缀和
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        //left sum: num[0]+..+num[i-1]=0
        //x=total-num[i]-x
        //2x+num[i]=total
        int sum=0;
        for (int i = 0;i < nums.size();i++) {
            if(2*sum+nums[i]==total)
                return i;
            sum+=nums[i];
        }
        return -1;
    }
};