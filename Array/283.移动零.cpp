/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */
#include "Array.h"
// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
       int n= nums.size(),left=0,right=0;
       while(right<n) {
           if(nums[right]){
               swap(nums[left],nums[right]);
               left++;
           }
           right++;
       }
    }
};
// @lc code=end

//单指针
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size = nums.size();
        if (size == 0)return;
        int j = 0;
        for (int i : nums) {
            if (i != 0)
                nums[j++] = i;
        }
        for (int i = j;i < size;i++)
            nums[i] = 0;
    }
};

//双指针
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
       int n= nums.size(),left=0,right=0;
       while(right<n) {
           if(nums[right]){
               swap(nums[left],nums[right]);
               left++;
           }
           right++;
       }
    }
};