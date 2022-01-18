/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */
#include "Array.h"
// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int sum = 0;
        int ans = INT_MAX;
        for (int left = 0, right = 0;right < n;) {
            sum += nums[right];
            while (sum >= target) {
                ans = min(ans, right - left + 1);
                sum -= nums[left];
                left++;
            }
            right++;
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
// @lc code=end

//暴力解法
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int ans = INT_MAX;
        for (int i = 0;i < n;i++) {
            int sum = 0;
            for (int j = i;j < n;j++) {
                sum += nums[j];
                if (sum >= target) {
                    ans = min(ans, j - i + 1);
                    break;
                }
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};

//前缀和 + 二分查找
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        int ans = INT_MAX;
        vector<int> sums(n + 1, 0); 
        // 为了方便计算，令 size = n + 1 
        // sums[0] = 0 意味着前 0 个元素的前缀和为 0
        // sums[1] = A[0] 前 1 个元素的前缀和为 A[0]
        // 以此类推
        for (int i = 1; i <= n; i++) {
            sums[i] = sums[i - 1] + nums[i - 1];
        }
        for (int i = 1; i <= n; i++) {
            int target = s + sums[i - 1];
            auto bound = lower_bound(sums.begin(), sums.end(), target);//二分查找大于等于target的第一个位置
            if (bound != sums.end()) {
                ans = min(ans, static_cast<int>((bound - sums.begin()) - (i - 1)));
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};

//滑动窗口
int minSubArrayLen(int target, vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    int sum = 0;
    int ans = INT_MAX;
    for (int left = 0, right = 0;right < n;) {
        sum += nums[right];
        while (sum >= target) {
            ans = min(ans, right - left + 1);
            sum -= nums[left];
            left++;
        }
        right++;
    }
    return ans == INT_MAX ? 0 : ans;
}