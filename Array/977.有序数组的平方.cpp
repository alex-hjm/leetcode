/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */
#include "Array.h"
// @lc code=start
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left = 0, right = nums.size();
        vector<int> ans;
        ans.resize(nums.size());
        int index = right - 1;
        while (left < right) {
            int a = nums[left] * nums[left];
            int b = nums[right - 1] * nums[right - 1];
            if (a < b) {
                ans[index] = b;
                right--;
            } else {
                ans[index] = a;
                left++;
            }
            index--;
        }
        return ans;
    }
};
// @lc code=end

//暴力解法
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;
        for (int i : nums)
            ans.push_back(i * i);
        sort(ans.begin(), ans.end());
        return ans;
    }
}

//双指针
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int negative = -1;
        for (int i = 0; i < n; ++i) {
            if (nums[i] < 0) {
                negative = i;
            } else {
                break;
            }
        }

        vector<int> ans;
        int i = negative, j = negative + 1;
        while (i >= 0 || j < n) {
            if (i < 0) {
                ans.push_back(nums[j] * nums[j]);
                ++j;
            } else if (j == n) {
                ans.push_back(nums[i] * nums[i]);
                --i;
            } else if (nums[i] * nums[i] < nums[j] * nums[j]) {
                ans.push_back(nums[i] * nums[i]);
                --i;
            } else {
                ans.push_back(nums[j] * nums[j]);
                ++j;
            }
        }

        return ans;
    }
};

//双指针
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        for (int i = 0, j = n - 1, pos = n - 1; i <= j;) {
            if (nums[i] * nums[i] > nums[j] * nums[j]) {
                ans[pos] = nums[i] * nums[i];
                ++i;
            } else {
                ans[pos] = nums[j] * nums[j];
                --j;
            }
            --pos;
        }
        return ans;
    }
};
