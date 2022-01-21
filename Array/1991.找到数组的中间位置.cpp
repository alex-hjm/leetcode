/*
 * @lc app=leetcode.cn id=1991 lang=cpp
 *
 * [1991] 找到数组的中间位置
 */

// @lc code=start
class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
         //left sum: num[0]+..+num[i-1]=0
         //x=total-num[i]-x
         //2x+num[i]=total
        int sum = 0;
        for (int i = 0;i < nums.size();i++) {
            if (2 * sum + nums[i] == total)
                return i;
            sum += nums[i];
        }
        return -1;
    }
};
// @lc code=end

