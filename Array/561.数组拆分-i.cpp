/*
 * @lc app=leetcode.cn id=561 lang=cpp
 *
 * [561] 数组拆分 I
 */
#include "Array.h"
// @lc code=start
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) return 0;
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 0;i < size / 2;i++) {
            ans += nums[2 * i];
        }
        return ans;
    }
};
// @lc code=end

//my pass
int arrayPairSum(vector<int>& nums) {
    int size = nums.size();
    if (size == 0) return 0;
    sort(nums.begin(), nums.end());
    int ans = 0;
    for (int i = 0;i < size / 2;i++) {
        ans += nums[2 * i];
    }
    return ans;
}

//排序
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 0; i < nums.size(); i += 2) {
            ans += nums[i];
        }
        return ans;
    }
};
